/*
 * QCauchoTest.h
 *
 *  Created on: 05.11.2010
 *      Author: caiiiycuk
 */

#ifndef QCAUCHOTEST_H_
#define QCAUCHOTEST_H_

#include "QTestHessian.h"

#include <stdexcept>
#include <QtCore>
#include <QtCore/QObject>

class QCauchoTest: public QObject {
Q_OBJECT
public:
	QCauchoTest() {
		methodNull();
		replyNull();
	}

	void methodNull() {
		TEST_START

		QHessian::QHessianMethodCall call("methodNull");
		call.invoke(networkManager, urlTest1, this, SLOT(replyNullCall()), SLOT(error(int, const QString&)));
	}

	void replyNull() {
		TEST_START

		QHessian::QHessianMethodCall call("replyNull");
		call.invoke(networkManager, urlTest1, this, SLOT(replyNullCall()), SLOT(error(int, const QString&)));
	}

public slots:
	void replyNullCall() {
		TEST_END
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QCAUCHOTEST_H_ */
