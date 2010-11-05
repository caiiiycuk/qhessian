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
		subtractCall();
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

	void subtractCall() {
		TEST_START
		QHessian::QHessianMethodCall call("subtract"); // a-b

		using namespace QHessian::in;

		call << Integer(105)  // a
			 << Integer(100); // b

		call.invoke(networkManager, urlTest1, this, SLOT(replySubtractCall()), SLOT(error(int, const QString&)));
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

	void replySubtractCall() {
		qint32 result;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> Integer(result);
		parser.parse();

		COMPARE(result, 5);

		TEST_END
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QSANITYCHECKTEST_H_ */
