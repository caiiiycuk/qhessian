/*
 *
 *  Created on: 25.07.2010
 *      Author: caiiiycuk
 */

#include "QHessianReturnParser.h"

#include <QDebug>
#include <QtCore>

namespace QHessian {

#define QHESSIAN_EXCEPTION(cause) \
	throw std::runtime_error(cause + std::string(" in ") + std::string(__FILE__) + std::string(", line ") + QString::number(__LINE__).toStdString());

#define QHESSIAN_SAVE_STATE() \
	int    oldOffset 	= replyOffset; \
	char*  oldPostion 	= replyArray;

#define QHESSIAN_RESTORE_STATE() \
	replyOffset = oldOffset;\
	replyArray  = oldPostion;

QHessianReturnParser::QHessianReturnParser(QNetworkReply* reply): reply(reply), errorState(false) {
	QObject::connect(reply, SIGNAL(finished()), this, SLOT(finished()));
	QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
}

QHessianReturnParser::~QHessianReturnParser() {
	qDeleteAll(properties);
	properties.clear();
}

void QHessianReturnParser::finished() {
	if (!errorState) {
		//parse input
		QByteArray array = reply->readAll();
		replyArray = array.data();
		replyOffset = 0;
		replySize = array.length();
//============================================================
//		Uncomment this to enable debug output
//
//		for (int i=0; i<array.size(); ++i) {
//			qDebug() << "line: " << (i+1) << QString::number(array.at(i)) << ":" << array.at(i);
//		}
//============================================================
		try {
			expect('r');
			read(); // major version
			read(); // minor version

			if (peek('f')) {
				readFault();
				reply->deleteLater();
				return;
			}
		} catch (std::runtime_error& parseError) {
			emit error(0, parseError.what());
		}

		emit ready();
	}

	reply->deleteLater();
}

inline void QHessianReturnParser::readNext(IProperty& property) {
	using namespace out;

	//
	// Null check
	//

	if (peek('N')) {
		lastReadWasNull = true;
		return;
	}

	//
	// Other check
	//

	lastReadWasNull = false;

	switch (property.getType()) {
	 	case NULL_VALUE:
	 		QHESSIAN_EXCEPTION("Null value doesn`t supports by QHessianReturnParser");
		break;

		case BINARY:
			expectString(((Binary&) property).getName());
			readBytes(((Binary&) property).getValue());

			break;

		case BOOLEAN:
			expectString(((Boolean&) property).getName());
			readBool(((Boolean&) property).getValue());

			break;

		case INTEGER:
			expectString(((Integer&) property).getName());
			expect('I', "QHessianReturnParser::readNext: Expected Integer ('I') tag");
			readInt(((Integer&) property).getValue());
			break;

		case LONG:
			expectString(((Long&) property).getName());
			expect('L', "QHessianReturnParser::readNext: Expected Long ('L') tag");
			readLong(((Long&) property).getValue());
			break;

		case DOUBLE:
			expectString(((Double&) property).getName());
		    expect('D', "QHessianReturnParser::readNext: Expected Double ('D') tag");
		    readDouble(((Double&) property).getValue());

			break;

		case STRING: {
			expectString(((String&) property).getName());
			readString(((String&) property).getValue());
		} break;

		case DATE: {
			expectString(((DateTime&) property).getName());
			readDate(((DateTime&) property).getValue());
		} break;

		case BEGIN_COLLECTION: {
			BeginCollection& collection = (BeginCollection&) property;
	        expectString(collection.getName());
	        readCollection(collection);
		} break;

		case BEGIN_MAP: {
			BeginMap& map = (BeginMap&) property;
			expectString(map.getName());
			readMap(map);
		} break;

		case HAS_MORE_MAP: {
			((HasMoreMap&) property).getValue() = (peek() != 'z');
		} break;

		case BEGIN_OBJECT: {
			expectString(((BeginObject&) property).getName());
		    expect('M', "QHessianReturnParser::readObject: Excepted Object ('M') tag");
		    if (peek('t')) {
		        expectStdString(((BeginObject&) property).getValue());
		    }
		} break;

		case END_OBJECT:
		case END_MAP:
		case END_COLLECTION: {
		    expect('z', "QHessianReturnParser::Excepted end ('z') tag");
		} break;

		case REF: {
			expectString(((Ref&) property).getName());
			expect('R');
			readInt(((Ref&) property).getValue());
		} break;
	}
}

inline void QHessianReturnParser::readString(QString& string) {
	string.clear();

	int tag = read();

    while (tag == 's') {
        string.append(readStringChunk());
        tag = read();
    }

    expect('S', tag, "QHessianReturnParser::readString: Excepted tag ('S')");
    string.append(readStringChunk());
}

inline void QHessianReturnParser::readFault() {
	QString keyCode;
	QString code;

	QString keyMessage;
	QString message;

	readString(keyCode);
	readString(code);

	readString(keyMessage);
	readString(message);

	std::string errorString = keyCode.toStdString() + std::string(": ")
			+ code.toStdString() + std::string(", ") + keyMessage.toStdString()
			+ std::string(": ") + message.toStdString();

	emit error(0, QString::fromStdString(errorString));
}

void QHessianReturnParser::error(QNetworkReply::NetworkError code) {
	errorState = true;
	emit error(code, QString(reply->readAll()));
}

//
// low - level read functions
//

// Reads boolean
inline void QHessianReturnParser::readBool(bool& value) {
    int tag = read();
    switch (tag) {
    case 'F':
        value = false;
        break;
    case 'T':
        value = true;
        break;
    default:
		QHESSIAN_EXCEPTION("except boolean (F or T), found tag " + tag);
    }
}

// Reads 32-bit integer.
inline void QHessianReturnParser::readInt(qint32& value) {
    value = ((read() & 0xFF) << 24) |
            ((read() & 0xFF) << 16) |
            ((read() & 0xFF) << 8) |
            (read() & 0xFF);
}

// Reads 64-bit integer.
inline void QHessianReturnParser::readLong(qint64& value) {
    value = (static_cast<qint64>(read() & 0xFF) << 56) |
            (static_cast<qint64>(read() & 0xFF) << 48) |
            (static_cast<qint64>(read() & 0xFF) << 40) |
            (static_cast<qint64>(read() & 0xFF) << 32) |
            (static_cast<qint64>(read() & 0xFF) << 24) |
            (static_cast<qint64>(read() & 0xFF) << 16) |
            (static_cast<qint64>(read() & 0xFF) << 8) |
             static_cast<qint64>(read() & 0xFF);
}

//Double
inline void QHessianReturnParser::readDouble(qreal& value) {
    double dValue = 0.0;

    char* array = reinterpret_cast<char*>(&dValue);

    for (int i=sizeof(double) -1; i>=0; --i) {
    	array[i] = readChar();
    }

    value = dValue;
}

//read date
inline void QHessianReturnParser::readDate(QDateTime& value) {
    expect('d');
    qint64 millis;
    readLong(millis);
	if (QT_VERSION >= QT_VERSION_CHECK(4, 7, 0)) {
		value.setMSecsSinceEpoch(millis);
	} else {
		value.setTime_t(millis / 1000);
	}
}

// Reads UTF-8 encoded string
inline QString QHessianReturnParser::readStringChunk() {
	QByteArray data;

    std::string::size_type nChar = ((read() & 0xFF) << 8) | (read() & 0xFF);
    for (std::string::size_type i = 0; i < nChar; ++i) {
        int ch = read();

		data.append(ch);

        if ((ch & 0xe0) == 0xc0) {
        	data.append(read());
		}

        if ((ch & 0xf0) == 0xe0) {
			data.append(read());
			data.append(read());
		}
    }

    return QString::fromUtf8(data.data(), data.size());
}

inline void QHessianReturnParser::readByteChunk(QByteArray& bytes) {
	int b16 = read() & 0xFF;
	int b8 = read() & 0xFF;
	int len = (b16 << 8) + b8;

	for (int i = 0; i < len; i++) {
		bytes.push_back(readChar());
	}
}

inline void QHessianReturnParser::readBytes(QByteArray& bytes) {
	int tag = read();

	if (tag == 'N') {
		bytes.clear();
		return;
	}

	std::string stream;

	while (tag == 'b') {
		readByteChunk(bytes);
		tag = read();
	}

	if (tag != 'B') {
		QHESSIAN_EXCEPTION("excepted B tag");
	}

	readByteChunk(bytes);
}

inline void QHessianReturnParser::readCollection(out::BeginCollection& collection) {
    expect('V');
    int tag = peek();
    if (tag == 't') {
        read();
        expectStdString(collection.getTypeName().toStdString());
        tag = peek();
    }

    if (tag == 'l') {
        read();
        readInt(collection.getValue());
    }
}

inline void QHessianReturnParser::readMap(out::BeginMap& map) {
    expect('M');
    int tag = peek();

    if (tag == 't') {
        read();

        if (map.getTypeName().length() > 0) {
        	expectStdString(map.getTypeName().toStdString());
        } else {
        	readStringChunk(); // read type string
        }
    }
}

inline int QHessianReturnParser::read() {
	if (replyOffset < replySize) {
		int byte = *replyArray;
		replyOffset++;
		replyArray++;
		return byte;
	} else {
		QString error("index out of bounds ");
		error.append(replyOffset).append(" >= ").append(replySize);
		QHESSIAN_EXCEPTION(error.toStdString());
	}
}

inline char QHessianReturnParser::readChar() {
	if (replyOffset < replySize) {
		char byte = *replyArray;
		replyOffset++;
		replyArray++;
		return byte;
	} else {
		QString error("index out of bounds ");
		error.append(replyOffset).append(" >= ").append(replySize);
		QHESSIAN_EXCEPTION(error.toStdString());
	}
}

inline bool QHessianReturnParser::peek(char c) {
	int tag = peek();

	if (tag == c) {
		read();
		return true;
	}

	return false;
}

inline int QHessianReturnParser::peek() {
	if (replyOffset < replySize) {
		int byte = *replyArray;
		return byte;
	} else {
		QString error("index out of bounds ");
		error.append(replyOffset).append(" >= ").append(replySize);
		QHESSIAN_EXCEPTION(error.toStdString());
	}
}

inline void QHessianReturnParser::expect(int expectedTag) {
	expect(expectedTag, read(), "n/a");
}

inline void QHessianReturnParser::expect(int expectedTag, const QString& details) {
	expect(expectedTag, read(), details);
}

inline void QHessianReturnParser::expect(int expectedTag, int actualTag, const QString& details) {
    if (expectedTag != actualTag) {
    	QString error;
    	error.append("expected ").append(expectedTag).append(", but found ").append(actualTag)
    				.append(", at ").append(QString::number(replyOffset)).append(" / ").append(QString::number(replySize))
    				.append(", extra: ").append(details);
        QHESSIAN_EXCEPTION(error.toStdString());
    }
}

inline void QHessianReturnParser::expectString(const QString& string) {
	if (string.length() > 0) {
		QString realString;
		readString(realString);

		if (realString != string) {
			QString error;
			error.append("Incompatible types ").append(string).append(" and ").append(realString);
			QHESSIAN_EXCEPTION(error.toStdString());
		}
	}
}

inline void QHessianReturnParser::expectStdString(const std::string& string) {
	if (string.length() > 0) {
        QString realString = readStringChunk();

		if (realString != QString::fromStdString(string)) {
			QString error;
			error.append("Incompatible types ").append(QString::fromStdString(string)).append(" and ").append(realString);
			QHESSIAN_EXCEPTION(error.toStdString());
		}
	}
}

QHessianReturnParser &QHessianReturnParser::operator>>(const IProperty& property) {
	IProperty* copy = property.clone();
	try {
		readNext(*copy);
	} catch (std::runtime_error& exp) {
		emit error(0, QString(exp.what()));
		delete copy;
		return *this;
	}
	delete copy;
	return *this;
}

bool QHessianReturnParser::peek(const IProperty& property) {
	QHESSIAN_SAVE_STATE()

	IProperty* copy = property.clone();
	try {
		readNext(*copy);
	} catch (...) {
		QHESSIAN_RESTORE_STATE()
		delete copy;
		return false;
	}
	delete copy;
	return true;
}

bool QHessianReturnParser::wasNull() const {
	return lastReadWasNull;
}

}
