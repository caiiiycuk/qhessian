/*
 * QHessianMethodArgs.h
 *
 *  Created on: 25.07.2010
 *      Author: caiiiycuk
 */

#ifndef QHESSIANMETHODCALL_H_
#define QHESSIANMETHODCALL_H_

#include <QtCore>
#include "QHessianTypes.h"

class QNetworkAccessManager;

namespace QHessian {

class QHessianMethodCall {
private:
	Q_DISABLE_COPY(QHessianMethodCall)

protected:
	QByteArray postData;

	QHessianMethodCall &appendString(const std::string&);
	QHessianMethodCall &appendNameString(const std::string&);
	QHessianMethodCall &appendPropetyName(const QString&);

	QHessianMethodCall &operator<<(const bool& );
	QHessianMethodCall &operator<<(const QString& );
	QHessianMethodCall &operator<<(const std::string& );
	QHessianMethodCall &operator<<(const qint64& );
	QHessianMethodCall &operator<<(const qint32& );
	QHessianMethodCall &operator<<(const qreal& );

	QHessianMethodCall &beginObject(const std::string&);

public:
	QHessianMethodCall(const QString& methodName);
	virtual ~QHessianMethodCall();

	QByteArray toByteArray() const;

	QHessianMethodCall &operator<<(const IProperty&);

	void invoke(QNetworkAccessManager& networkManager,
			 	const QUrl& url,
				QObject* reciver,
				const char* replySlot,
				const char* errorSlot);

//FIXME: add this methods

//	Hessian1OutputStream&
//	Hessian1OutputStream::operator<< (hessian::Date value)
//	{
//	    write('d');
//	    write(value.timeInMillis());
//	    return *this;
//	}

//	Hessian1OutputStream&
//	Hessian1OutputStream::operator<< (const hessian::Binary& value)
//	{
//	    const char *pValue = &value[0];
//	    std::string::size_type nBytes = value.size();
//	    while (nBytes > CHUNK_MAX) {
//	        write('b');
//	        write(CHUNK_MAX, pValue);
//
//	        pValue += CHUNK_MAX;
//	        nBytes -= CHUNK_MAX;
//	    }
//
//	    write('B');
//	    write(nBytes, pValue);
//	    return *this;
//	}

//    void beginList();
//    void endList();
//
//    void beginObject(
//            const char* pTypeName, std::string::size_type typeNameLength);
//    void endObject();

};

}

#endif /* QHESSIANMETHODCALL_H_ */
