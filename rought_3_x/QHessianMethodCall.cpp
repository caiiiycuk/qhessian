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

	QHessianReturnParser* parser = new QHessianReturnParser(networkManager.post(request, toByteArray()));
	QObject::connect(parser, SIGNAL(ready()), reciver, replySlot);
	QObject::connect(parser, SIGNAL(error(int, const QString&)), reciver, errorSlot);
}

void QHessianMethodCall::writeName(const std::string& name) {
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
	writeName(methodName.toStdString());
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
	stream.append('L');
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
	stream.append('I');
	stream.append(static_cast<char>((value >> 24) & 0xFF));
	stream.append(static_cast<char>((value >> 16) & 0xFF));
	stream.append(static_cast<char>((value >> 8) & 0xFF));
	stream.append(static_cast<char>(value & 0xFF));
}

inline void QHessianMethodCall::writeDouble(const qreal& value) {
    stream.append('D');
    stream.append(reinterpret_cast<const char *>(&value), sizeof(value));
}

inline void QHessianMethodCall::writeObject(const std::string& object) {
	stream.append('M');
	stream.append('t');
	writeName(object);
}

QHessianMethodCall &QHessianMethodCall::operator<<(const IProperty& object) {
	using namespace in;


	switch (object.getType()) {
		case BOOLEAN:
			writePropetyName(((Boolean&) object).getName());
			writeBool(((Boolean&) object).getValue());
		break;

		case INTEGER:
			writePropetyName(((Integer&) object).getName());
			writeInt(((Integer&) object).getValue());
		break;

		case LONG:
			writePropetyName(((Long&) object).getName());
			writeLong(((Long&) object).getValue());
		break;

		case DOUBLE:
			writePropetyName(((Double&) object).getName());
			writeDouble(((Double&) object).getValue());
		break;

		case STRING:
			writePropetyName(((String&) object).getName());
			writeString(((String&) object).getValue());
		break;

		case BEGIN_OBJECT:
			writeObject(((BeginObject&) object).getValue());
			return *this;
		break;

		case END_OBJECT:
			stream.append('z');
			return *this;
		break;
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
