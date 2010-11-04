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

QHessianMethodCall &QHessianMethodCall::appendNameString(const std::string& name) {
	qint16 length = name.length();

	postData.append(static_cast<char>((length >> 8) & 0xFF));
	postData.append(static_cast<char>(length & 0xFF));
	postData.append(name.c_str(), length);

	return *this;
}

QHessianMethodCall &QHessianMethodCall::appendPropetyName(const QString& name) {
	if (name.length() > 0) {
		appendString(name.toStdString());
	}

	return *this;
}

inline QHessianMethodCall &QHessianMethodCall::appendString(const std::string& value) {
    const char* pSrcBegin = value.data();
    const char* pSrcEnd = pSrcBegin + value.size();
    do {
        std::string::size_type count;
        const char* pEnd = countUTF8Char(pSrcBegin, pSrcEnd, count);
        postData.append((pEnd < pSrcEnd) ? 's' : 'S');

    	postData.append(static_cast<char>((count >> 8) & 0xFF));
    	postData.append(static_cast<char>(count & 0xFF));
        postData.append(pSrcBegin, count);
        pSrcBegin = pEnd;
    } while (pSrcBegin < pSrcEnd);

    return *this;
}

QHessianMethodCall::QHessianMethodCall(const QString& methodName) {
	//--begin call;
	postData.append('c');
	postData.append('\x01');
	postData.append('\x00');
	postData.append('m');

	//--write call method name
	appendNameString(methodName.toStdString());
}

QHessianMethodCall::~QHessianMethodCall() {
}

QByteArray QHessianMethodCall::toByteArray() const {
	QByteArray data = postData;
	data.append('z'); //end call
	return data;
}

inline QHessianMethodCall &QHessianMethodCall::operator<<(const bool& value) {
	postData.append(value ? 'T' : 'F');
	return *this;
}

inline QHessianMethodCall &QHessianMethodCall::operator<<(const std::string& value) {
	appendString(value);
    return *this;
}

inline QHessianMethodCall &QHessianMethodCall::operator<<(const QString& value) {
	appendString(value.toStdString());
    return *this;
}

inline QHessianMethodCall &QHessianMethodCall::operator<<(const qint64& value) {
	postData.append('L');
	postData.append(static_cast<char>((value >> 56) & 0xFF));
	postData.append(static_cast<char>((value >> 48) & 0xFF));
	postData.append(static_cast<char>((value >> 40) & 0xFF));
	postData.append(static_cast<char>((value >> 32) & 0xFF));
	postData.append(static_cast<char>((value >> 24) & 0xFF));
	postData.append(static_cast<char>((value >> 16) & 0xFF));
	postData.append(static_cast<char>((value >> 8) & 0xFF));
	postData.append(static_cast<char>(value & 0xFF));
	return *this;
}

inline QHessianMethodCall &QHessianMethodCall::operator<<(const qint32& value) {
	postData.append('I');
	postData.append(static_cast<char>((value >> 24) & 0xFF));
	postData.append(static_cast<char>((value >> 16) & 0xFF));
	postData.append(static_cast<char>((value >> 8) & 0xFF));
	postData.append(static_cast<char>(value & 0xFF));
	return *this;
}

inline QHessianMethodCall &QHessianMethodCall::operator<<(const qreal& value) {
    postData.append('D');
    postData.append(reinterpret_cast<const char *>(&value), sizeof(value));
	return *this;
}

inline QHessianMethodCall &QHessianMethodCall::beginObject(const std::string& object) {
	postData.append('M');
	postData.append('t');
	appendNameString(object);
	return *this;
}

QHessianMethodCall &QHessianMethodCall::operator<<(const IProperty& object) {
	using namespace in;


	switch (object.getType()) {
		case BOOLEAN:
			return appendPropetyName(((Boolean&) object).getName()) << ((Boolean&) object).getValue();
		break;

		case INTEGER:
			return appendPropetyName(((Integer&) object).getName()) << ((Integer&) object).getValue();
		break;

		case LONG:
			return appendPropetyName(((Long&) object).getName()) << ((Long&) object).getValue();
		break;

		case DOUBLE:
			return appendPropetyName(((Double&) object).getName()) << ((Double&) object).getValue();
		break;

		case STRING:
			return appendPropetyName(((String&) object).getName()) << ((String&) object).getValue();
		break;

		case BEGIN_OBJECT:
			beginObject(((BeginObject&) object).getValue());
			return *this;
		break;

		case END_OBJECT:
			postData.append('z');
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
