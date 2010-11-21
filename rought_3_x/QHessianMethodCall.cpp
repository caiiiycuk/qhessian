/*
 * QHessianMethodArgs.cpp
 *
 *  Created on: 25.07.2010
 *      Author: caiiiycuk
 */

#include "QHessianMethodCall.h"
#include "QHessianReturnParser.h"

#include <QNetworkAccessManager>

namespace QHessian {

namespace {

const char*
countUTF8Char (
        const char* ,
        const char* ,
        std::string::size_type& );

}

void QHessianMethodCall::invoke(QNetworkAccessManager& networkManager,
		 	const QUrl& url,
			QObject* reciver,
			const char* replySlot,
			const char* errorSlot) {

	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "x-application/hessian");

//	QByteArray arr = toByteArray();
//			for (int i=0; i<array.size(); ++i) {
//				qDebug() << QString::number(arr.at(i)) << ":" << arr.at(i);
//			}
//	QHessianReturnParser* parser = new QHessianReturnParser(networkManager.post(request, arr));

	QHessianReturnParser* parser = new QHessianReturnParser(networkManager.post(request, toByteArray()));
	QObject::connect(parser, SIGNAL(ready()), reciver, replySlot);
	QObject::connect(parser, SIGNAL(error(int, const QString&)), reciver, errorSlot);
}

void QHessianMethodCall::writeStdString(const std::string& name) {
	qint16 length = name.length();

	stream.append(static_cast<char>((length >> 8) & 0xFF));
	stream.append(static_cast<char>(length & 0xFF));
	stream.append(name.c_str(), length);
}

void QHessianMethodCall::writePropetyName(const QString& value) {
	if (value.length() > 0) {
		writeString(value.toStdString());
	}
}

inline void QHessianMethodCall::writeString(const std::string& value) {
    const char* pSrcBegin = value.data();
    const char* pSrcEnd = pSrcBegin + value.size();
    do {
        std::string::size_type count;
        const char* pEnd = countUTF8Char(pSrcBegin, pSrcEnd, count);
        stream.append((pEnd < pSrcEnd) ? 's' : 'S');

    	stream.append(static_cast<char>((count >> 8) & 0xFF));
    	stream.append(static_cast<char>(count & 0xFF));
        stream.append(pSrcBegin, count);
        pSrcBegin = pEnd;
    } while (pSrcBegin < pSrcEnd);
}

inline void QHessianMethodCall::writeCall() {
	stream.append('c');
	stream.append('\x01');
	stream.append('\x00');
	stream.append('m');
}

QHessianMethodCall::QHessianMethodCall(const QString& methodName) {
	//--begin call;
	writeCall();

	//--write call method name
	writeStdString(methodName.toStdString());
}

QHessianMethodCall::~QHessianMethodCall() {
}

QByteArray QHessianMethodCall::toByteArray() const {
	QByteArray data = stream;
	data.append('z'); //end call
	return data;
}

inline void QHessianMethodCall::writeBool(const bool& value) {
	stream.append(value ? 'T' : 'F');
}

inline void QHessianMethodCall::writeString(const QString& value) {
	writeString(value.toStdString());
}

inline void QHessianMethodCall::writeLong(const qint64& value) {
	stream.append(static_cast<char>((value >> 56) & 0xFF));
	stream.append(static_cast<char>((value >> 48) & 0xFF));
	stream.append(static_cast<char>((value >> 40) & 0xFF));
	stream.append(static_cast<char>((value >> 32) & 0xFF));
	stream.append(static_cast<char>((value >> 24) & 0xFF));
	stream.append(static_cast<char>((value >> 16) & 0xFF));
	stream.append(static_cast<char>((value >> 8) & 0xFF));
	stream.append(static_cast<char>(value & 0xFF));
}

inline void QHessianMethodCall::writeInt(const qint32& value) {
	stream.append(static_cast<char>((value >> 24) & 0xFF));
	stream.append(static_cast<char>((value >> 16) & 0xFF));
	stream.append(static_cast<char>((value >> 8) & 0xFF));
	stream.append(static_cast<char>(value & 0xFF));
}

inline void QHessianMethodCall::writeDouble(const qreal& value) {
    stream.append(reinterpret_cast<const char *>(&value), sizeof(value));
}

inline void QHessianMethodCall::writeObject(const std::string& object) {
	stream.append('M');
	stream.append('t');
	writeStdString(object);
}

void QHessianMethodCall::writeBinary(const std::string& bytes) {
	size_t l_bytesLen = bytes.size();
	size_t l_pos = 0;
	while(l_bytesLen > 0x8000) {
		size_t l_sublen = 0x8000;
		stream.append('b');
		writeStdString(bytes.substr(l_pos, l_sublen));
		l_bytesLen -= l_sublen;
		l_pos += l_sublen;
	}
	stream.append('B');
	writeStdString(bytes.substr(l_pos, l_bytesLen));
}

QHessianMethodCall &QHessianMethodCall::operator<<(const IProperty& object) {
	using namespace in;


	switch (object.getType()) {
		case NULL_VALUE:
			writePropetyName(((Null&) object).getName());
			stream.append("N");
		break;

		case BOOLEAN:
			writePropetyName(((Boolean&) object).getName());
			writeBool(((Boolean&) object).getValue());
		break;

		case INTEGER:
			writePropetyName(((Integer&) object).getName());
			stream.append('I');
			writeInt(((Integer&) object).getValue());
		break;

		case LONG:
			writePropetyName(((Long&) object).getName());
			stream.append('L');
			writeLong(((Long&) object).getValue());
		break;

		case DOUBLE:
			writePropetyName(((Double&) object).getName());
			stream.append('D');
			writeDouble(((Double&) object).getValue());
		break;

		case STRING:
			writePropetyName(((String&) object).getName());
			writeString(((String&) object).getValue());
		break;

		case BINARY:
			writePropetyName(((Binary&) object).getName());
			writeBinary(((Binary&) object).getValue().toStdString());
		break;

		case BEGIN_COLLECTION: {
			BeginCollection& collcetion = (BeginCollection&) object;
			writePropetyName(collcetion.getName());
			stream.append('V');
			if (collcetion.getTypeName().length()) {
				stream.append('t');
				writeStdString(collcetion.getTypeName().toStdString());
			}
			stream.append("l");
			writeInt(collcetion.getValue());
		} break;

		case BEGIN_OBJECT: {
			writePropetyName(((BeginObject&) object).getName());
			writeObject(((BeginObject&) object).getValue());
			return *this;
		} break;

		case BEGIN_MAP: {
			BeginMapProperty& map = (BeginMapProperty&) object;
			writePropetyName(map.getName());
			stream.append("M");
			if (map.getTypeName().length()) {
				stream.append("t");
				writeStdString(map.getName().toStdString());
			}
		} break;

		case REF: {
			Ref& ref = (Ref&) object;
			writePropetyName(ref.getName());
			stream.append('R');
			writeInt(ref.getValue());
		} break;

		case END_MAP:
		case END_COLLECTION:
		case END_OBJECT: {
			stream.append('z');
			return *this;
		} break;
	}

	return *this;
}

namespace {

const std::string::size_type CHUNK_MAX = 65535;

// Counts the number of UTF-8 encoded characters until the end of the range
// or the maximum chunk length is reached.  Assumes char is signed.
// Return pointer to byte after last byte examined.

const char*
countUTF8Char (
        const char* pSrc,
        const char* pEnd,
        std::string::size_type& retCount)
{
    std::string::size_type count = 0;

    while (pSrc < pEnd && *pSrc >= 0) {
ascii:
        ++pSrc;

        if (++count >= CHUNK_MAX) {
            retCount = count;
            return pSrc;
        }
    }

    while (pSrc < pEnd) {
        if (*pSrc >= 0) {
            goto ascii;
        } else {
            switch (*pSrc & 0xF0) {
            case 0xE0:
                pSrc += 3;
                break;
            case 0xF0:
                pSrc += 4;
                break;
            default:
                pSrc += 2;
            }
        }

        if (++count >= CHUNK_MAX) {
            break;
        }
    }

    retCount = count;
    return pSrc;
}

}

}
