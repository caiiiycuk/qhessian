/*
 * QTestlibTest.h
 *
 *  Created on: 01.11.2010
 *      Author: caiiiycuk
 */

#ifndef QSANITYCHECKTEST_H_
#define QSANITYCHECKTEST_H_

#include "QTestHessian.h"

#include <stdexcept>
#include <QtCore>
#include <QtCore/QObject>

class QSanityCheckTest: public QObject {
Q_OBJECT
public:
	QSanityCheckTest() {
		nullCall();
		helloCall();
	}

	void nullCall() {
		TEST_START

		QHessian::QHessianMethodCall call("nullCall");
		call.invoke(networkManager, urlTest1, this, SLOT(replyNullCall()), SLOT(error(int, const QString&)));
	}

	void helloCall() {
		TEST_START
		QHessian::QHessianMethodCall call("hello");
		call.invoke(networkManager, urlTest1, this, SLOT(replyHelloCall()), SLOT(error(int, const QString&)));
	}

public slots:
	void replyNullCall() {
		TEST_END
	}

	void replyHelloCall() {
		QString hello;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> String(hello);
		parser.parse();

		COMPARE(hello, QString("Hello, World"));

		TEST_END
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QSANITYCHECKTEST_H_ */
