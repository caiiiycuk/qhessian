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
		echoCall();
		echoNullCall();
		faultCall();
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

	void echoCall() {
		TEST_START
		QHessian::QHessianMethodCall call("echo");

		using namespace QHessian::in;
		call << String("Hey, it`s ok!");
		call.invoke(networkManager, urlTest1, this, SLOT(echo()), SLOT(error(int, const QString&)));
	}

	void echoNullCall() {
		TEST_START
		QHessian::QHessianMethodCall call("echo");

		using namespace QHessian::in;
		call << Null();
		call.invoke(networkManager, urlTest1, this, SLOT(echoNull()), SLOT(error(int, const QString&)));
	}

	void faultCall() {
		TEST_START
		QHessian::QHessianMethodCall call("fault");

		using namespace QHessian::in;
		call.invoke(networkManager, urlTest1, this, SLOT(fault()), SLOT(error(int, const QString&)));
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
		parser.deleteLater();

		COMPARE(hello, QString("Hello, World"));

		TEST_END
	}

	void replySubtractCall() {
		qint32 result;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> Integer(result);
		parser.deleteLater();

		COMPARE(result, 5);

		TEST_END
	}

	void fault() {
	}

	void echo() {
		QString result;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> String(result);
		parser.deleteLater();

		COMPARE(result, QString("Hey, it`s ok!"));

		TEST_END
	}

	void echoNull() {
		QString result;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> String(result);
		parser.deleteLater();

		COMPARE(parser.wasNull(), true);

		TEST_END
	}

	void error(int, const QString& string) {
		COMPARE(string, QString("code: ServiceException, message: sample exception"))
		TEST_END
	}
};

#endif /* QSANITYCHECKTEST_H_ */
