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
	QByteArray stream;

	void writeCall();
	void writeStdString(const std::string&);
	void writePropetyName(const QString&);

	void writeBool(const bool& );
	void writeString(const QString& );
	void writeString(const std::string& );
	void writeLong(const qint64& );
	void writeInt(const qint32& );
	void writeDouble(const qreal& );
	void writeBinary(const QByteArray& );
	void writeBinaryPart(const QByteArray&, qint32 form, qint32 len);

	void writeObject(const std::string&);

	QByteArray toByteArray() const;

public:
	QHessianMethodCall(const QString& methodName);
	virtual ~QHessianMethodCall();


	QHessianMethodCall &operator<<(const IProperty&);

	void invoke(QNetworkAccessManager& networkManager,
			 	const QUrl& url,
				QObject* reciver,
				const char* replySlot,
				const char* errorSlot);

};

}

#endif /* QHESSIANMETHODCALL_H_ */
