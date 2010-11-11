/*
 * QCauchoTest.h
 *
 *  Created on: 05.11.2010
 *      Author: caiiiycuk
 */

#ifndef QCAUCHOTEST2_H_
#define QCAUCHOTEST2_H_

#include "QTestHessian.h"

#include <stdexcept>
#include <QtCore>
#include <QtCore/QObject>

#define EXCEPT_TRUE \
		using namespace QHessian::out; \
		bool success; \
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender(); \
        parser >> Boolean(success); \
        COMPARE(success, true); \
        parser.deleteLater(); \
		TEST_END

class QCauchoTest2: public QObject {
Q_OBJECT
public:
	QCauchoTest2() {
		methodNull();

		//
		// Binary
		//
		argBinary_0Call();
		argBinary_1Call();
		argBinary_15Call();
		argBinary_16Call();
		argBinary_1023Call();
		argBinary_1024Call();
		argBinary_65536Call();

		//
		// lists
		//
		argUntypedFixedList_0Call();
		argUntypedFixedList_1Call();
		argUntypedFixedList_7Call();
		argUntypedFixedList_8Call();
	}

	void methodNull() {
		TEST_START

		QHessian::QHessianMethodCall call("methodNull");
		call.invoke(networkManager, urlTest2, this, SLOT(replyNullCall()), SLOT(error(int, const QString&)));
	}

	void argBinary_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argBinary_0");
		call << Binary(QString(""));
		call.invoke(networkManager, urlTest2, this, SLOT(argBinary_0()), SLOT(error(int, const QString&)));
	}

	void argBinary_1Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argBinary_1");
		call << Binary(QString("0"));
		call.invoke(networkManager, urlTest2, this, SLOT(argBinary_1()), SLOT(error(int, const QString&)));
	}

	void argBinary_15Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argBinary_15");
		call << Binary(QString("012345678901234"));
		call.invoke(networkManager, urlTest2, this, SLOT(argBinary_15()), SLOT(error(int, const QString&)));
	}

	void argBinary_16Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argBinary_16");
		call << Binary(QString("0123456789012345"));
		call.invoke(networkManager, urlTest2, this, SLOT(argBinary_16()), SLOT(error(int, const QString&)));
	}

	void argBinary_1023Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argBinary_1023");
		call << Binary(generateString(1023));
		call.invoke(networkManager, urlTest2, this, SLOT(argBinary_1023()), SLOT(error(int, const QString&)));
	}

	void argBinary_1024Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argBinary_1024");
		call << Binary(generateString(1024));
		call.invoke(networkManager, urlTest2, this, SLOT(argBinary_1024()), SLOT(error(int, const QString&)));
	}

	void argBinary_65536Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argBinary_65536");
		call << Binary(generateString(65536));
		call.invoke(networkManager, urlTest2, this, SLOT(argBinary_65536()), SLOT(error(int, const QString&)));
	}

	void argUntypedFixedList_0Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argUntypedFixedList_0");
		call << BeginCollection(0)
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedFixedList_0()), SLOT(error(int, const QString&)));
	}

	void argUntypedFixedList_1Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argUntypedFixedList_1");
		call << BeginCollection(7)
				<< String("1")
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedFixedList_1()), SLOT(error(int, const QString&)));
	}

	void argUntypedFixedList_7Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argUntypedFixedList_7");
		call << BeginCollection(7)
				<< String("1")
				<< String("2")
				<< String("3")
				<< String("4")
				<< String("5")
				<< String("6")
				<< String("7")
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedFixedList_7()), SLOT(error(int, const QString&)));
	}

	void argUntypedFixedList_8Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argUntypedFixedList_8");
		call << BeginCollection(7)
				<< String("1")
				<< String("2")
				<< String("3")
				<< String("4")
				<< String("5")
				<< String("6")
				<< String("7")
				<< String("8")
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedFixedList_8()), SLOT(error(int, const QString&)));
	}


public slots:
	void replyNullCall() {
		TEST_END
	}

	void argBinary_0() {
		EXCEPT_TRUE
	}

	void argBinary_1() {
		EXCEPT_TRUE
	}

	void argBinary_15() {
		EXCEPT_TRUE
	}

	void argBinary_16() {
		EXCEPT_TRUE
	}

	void argBinary_1023() {
		EXCEPT_TRUE
	}

	void argBinary_1024() {
		EXCEPT_TRUE
	}

	void argBinary_65536() {
		EXCEPT_TRUE
	}

	void argUntypedFixedList_0() {
		EXCEPT_TRUE
	}

	void argUntypedFixedList_1() {
		EXCEPT_TRUE
	}

	void argUntypedFixedList_7() {
		EXCEPT_TRUE
	}

	void argUntypedFixedList_8() {
		EXCEPT_TRUE
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QCAUCHOTEST2_H_ */
