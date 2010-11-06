/*
 *
 *  Created on: 25.07.2010
 *      Author: caiiiycuk
 */

#include "QHessianReturnParser.h"

#include <QDebug>
#include <QtCore>

namespace QHessian {

#define EXCEPTION(cause) \
	throw std::runtime_error(cause + std::string(" in ") + std::string(__FILE__) + std::string(", line ") + QString::number(__LINE__).toStdString());

const static char REPLY_TAG = 'r';
const static char FAULT_TAG = 'f';

const static char OBJECT_TAG = 'M';

//TYPE TAGS
const static char NULL_TAG = 'N';
const static char INTEGER_TAG = 'I';
const static char STRING_SMALL_TAG = 's';
const static char STRING_BIG_TAG = 'S';

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

//		for (int i=0; i<array.size(); ++i) {
//			qDebug() << array.at(i);
//		}

		try {
			expect(REPLY_TAG);
			read(); // major version
			read(); // minor version

			if (peek(FAULT_TAG)) {
				readFault();
			}
		} catch (std::runtime_error& parseError) {
			emit error(0, parseError.what());
		}

		emit ready();
	}

	reply->deleteLater();
}

inline void QHessianReturnParser::readNext(QList<IProperty*>& properties) {
	using namespace out;

	IProperty* property = properties.takeFirst();

	switch (property->getType()) {
		case BINARY:
			expectString(((Binary*) property)->getName());
			readBytes(((Binary*) property)->getValue());

			break;

		case BOOLEAN:
			expectString(((Boolean*) property)->getName());
			readBool(((Boolean*) property)->getValue());

			break;

		case INTEGER:
			expectString(((Integer*) property)->getName());
			expect(INTEGER_TAG, "QHessianReturnParser::readNext: Expected Integer ('I') tag");
			readInt(((Integer*) property)->getValue());
			break;

		case LONG:
			expectString(((Long*) property)->getName());
			expect('L', "QHessianReturnParser::readNext: Expected Long ('L') tag");
			readLong(((Long*) property)->getValue());
			break;

		case DOUBLE:
			expectString(((Double*) property)->getName());
		    expect('D', "QHessianReturnParser::readNext: Expected Double ('D') tag");
		    readDouble(((Double*) property)->getValue());

			break;

		case STRING: {
			expectString(((String*) property)->getName());
			readString(((String*) property)->getValue());
		} break;

		case DATE: {
			expectString(((DateTime*) property)->getName());

			QDateTime& dateTime = ((DateTime*) property)->getValue();

		    expect('d');
		    qint64 millis;
		    readLong(millis);

		    dateTime.setTime_t(millis / 1000);
		} break;

		case BEGIN_COLLECTION: {
			BeginCollection* collection = (BeginCollection*) property;
	        expectString(collection->getName());
	        readCollection(*collection);
		} break;

		case END_COLLECTION: {
		    expect('z', "QHessianReturnParser::readObject: Excepted Collection end ('z') tag");
		} break;

		case BEGIN_OBJECT: {
		    expect(OBJECT_TAG, "QHessianReturnParser::readObject: Excepted Object ('M') tag");
		    if (peek('t')) {
		        expectStdString(((BeginObject*) property)->getValue());
		    }
		} break;

		case END_OBJECT: {
			expect('z', "QHessianReturnParser::readObject: Excepted Object end ('z') tag");
		} break;
	}

	delete property;
}

inline void QHessianReturnParser::readString(QString& string) {
	int tag = read();

	if (tag == NULL_TAG) {
		string.clear();
		return;
	}

	std::string value;

    while (tag == STRING_SMALL_TAG) {
        readString(value);
        tag = read();
    }

    expect(STRING_BIG_TAG, tag, "QHessianReturnParser::readString: Excepted tag ('S')");
    readString(value);

    string = QString::fromStdString(value);
}

inline void QHessianReturnParser::readFault() {
	//FIXME: need parse fault results
	QString keyCode;
	QString code;

	QString keyMessage;
	QString message;

	readString(keyCode);
	readString(code);

	readString(keyMessage);
	readString(message);

	std::string error = keyCode.toStdString() + std::string(": ")
			+ code.toStdString() + std::string(", ") + keyMessage.toStdString()
			+ std::string(": ") + message.toStdString();

	EXCEPTION(error)
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
		EXCEPTION("except boolean (F or T), found tag " + tag);
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

//ddouble
inline void QHessianReturnParser::readDouble(qreal& value) {
    double dValue;

    char* array = reinterpret_cast<char*>(&dValue);

    for (int i=sizeof(double) -1; i>=0; --i) {
    	array[i] = readChar();
    }

    value = dValue;
}

// Reads UTF-8 encoded string, and appends to value.
inline void QHessianReturnParser::readString(std::string& value) {
    std::string::size_type nChar = ((read() & 0xFF) << 8) | (read() & 0xFF);
    for (std::string::size_type i = 0; i < nChar; ++i) {
        int ch = read();
        value.append(1, static_cast<char>(ch));

        if (ch >= 0x80) {
            switch (ch & 0xF0) {
            case 0xF0:
                value.append(1, static_cast<char>(read()));
                // FALL THROUGH
            case 0xE0:
                value.append(1, static_cast<char>(read()));
                // FALL THROUGH
            default:
                value.append(1, static_cast<char>(read()));
            }
        }
    }
}

inline void QHessianReturnParser::readByteChunk(std::string& bytes) {
	int b16 = read() & 0xFF;
	int b8 = read() & 0xFF;
	int len = (b16 << 8) + b8;

	for (int i = 0; i < len; i++) {
		bytes.push_back(readChar());
	}
}

inline void QHessianReturnParser::readBytes(QString& bytes) {
	int tag = read();

	if (tag == 'N') {
		bytes.clear();
		return;
	}

	std::string stream;

	while (tag == 'b') {
		readByteChunk(stream);
		tag = read();
	}

	if (tag != 'B') {
		EXCEPTION("excepted B tag");
	}

	readByteChunk(stream);

	bytes = QString::fromStdString(stream);
}

inline void QHessianReturnParser::readCollection(out::BeginCollection& collection) {
    expect('V');
    int tag = peek();
    if (tag == 't') {
        read();
        expectString(collection.getName());
        tag = peek();
    }

    if (tag == 'l') {
        read();
        readInt(collection.getValue());
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
		EXCEPTION(error.toStdString());
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
		EXCEPTION(error.toStdString());
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
		EXCEPTION(error.toStdString());
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
        EXCEPTION(error.toStdString());
    }
}

inline void QHessianReturnParser::expectString(const QString& string) {
	if (string.length() > 0) {
		QString realString;
		readString(realString);

		if (realString != string) {
			QString error;
			error.append("Incompatible types ").append(string).append(" and ").append(realString);
			EXCEPTION(error.toStdString());
		}
	}
}


inline void QHessianReturnParser::expectStdString(const std::string& string) {
	if (string.length() > 0) {
        std::string realString;
        readString(realString);

		if (realString != string) {
			QString error;
			error.append("Incompatible types ").append(QString::fromStdString(string)).append(" and ").append(QString::fromStdString(realString));
			EXCEPTION(error.toStdString());
		}
	}
}

QHessianReturnParser &QHessianReturnParser::operator>>(const IProperty& property) {
//	properties.push_back(property.clone());
	//FIXME
	QList<IProperty*> props;
	props.append(property.clone());
	readNext(props);
	return *this;
}

}
