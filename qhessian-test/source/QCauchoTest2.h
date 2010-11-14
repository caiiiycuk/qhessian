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

		//
		// typed list
		//
		argTypedFixedList_0Call();
		argTypedFixedList_1Call();
		argTypedFixedList_7Call();
		argTypedFixedList_8Call();

		//
		// untyped maps
		//
		argUntypedMap_0Call();
		argUntypedMap_1Call();
		argUntypedMap_2Call();
		argUntypedMap_3Call();

		//
		// typed maps
		//
		argTypedMap_0Call();
		argTypedMap_1Call();
		argTypedMap_2Call();
		argTypedMap_3Call();
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

	void argTypedFixedList_0Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argTypedFixedList_0");
		call << BeginCollection("", "[string", 0)
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedFixedList_0()), SLOT(error(int, const QString&)));
	}

	void argTypedFixedList_1Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argTypedFixedList_1");
		call << BeginCollection("", "[string", 1)
						<< String("1")
				 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedFixedList_1()), SLOT(error(int, const QString&)));
	}

	void argTypedFixedList_7Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argTypedFixedList_7");
		call << BeginCollection("", "[string", 7)
						<< String("1")
						<< String("2")
						<< String("3")
						<< String("4")
						<< String("5")
						<< String("6")
						<< String("7")
				 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedFixedList_7()), SLOT(error(int, const QString&)));
	}

	void argTypedFixedList_8Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argTypedFixedList_8");
		call << BeginCollection("", "[string", 8)
						<< String("1")
						<< String("2")
						<< String("3")
						<< String("4")
						<< String("5")
						<< String("6")
						<< String("7")
						<< String("8")
				 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedFixedList_8()), SLOT(error(int, const QString&)));
	}

	void argUntypedMap_0Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argUntypedMap_0");
		call << BeginMap()
			 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedMap_0()), SLOT(error(int, const QString&)));
	}

	void argUntypedMap_1Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argUntypedMap_1");
		call << BeginMap()
					<< String("a") << Integer(0) // key == a, value == 0
			 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedMap_1()), SLOT(error(int, const QString&)));
	}

	void argUntypedMap_2Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argUntypedMap_2");
		call << BeginMap()
					<< Integer(0) << String("a") // key == 0, value == a
					<< Integer(1) << String("b") // key == 1, value == b
			 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedMap_2()), SLOT(error(int, const QString&)));
	}

	void argUntypedMap_3Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argUntypedMap_3");
		call << BeginMap()
				//KEY
				<< BeginCollection(1)
				<< String("a")
				<< EndCollection()
				//VALUE
				<< Integer(0)
			 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argUntypedMap_3()), SLOT(error(int, const QString&)));
	}

	void argTypedMap_0Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argTypedMap_0");
		call << BeginMap("", "java.util.Hashtable")
			 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedMap_0()), SLOT(error(int, const QString&)));
	}

	void argTypedMap_1Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argTypedMap_1");
		call << BeginMap("", "java.util.Hashtable")
				<< String("a") << Integer(0)  // key == a, value == 0
			 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedMap_1()), SLOT(error(int, const QString&)));
	}

	void argTypedMap_2Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argTypedMap_2");
		call << BeginMap("", "java.util.Hashtable")
					<< Integer(0) << String("a") // key == 0, value == a
					<< Integer(1) << String("b") // key == 1, value == b
			 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedMap_2()), SLOT(error(int, const QString&)));
	}

	void argTypedMap_3Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argTypedMap_3");
		call << BeginMap("", "java.util.Hashtable")
						//KEY
						<< BeginCollection(1)
						<< String("a")
						<< EndCollection()
						//VALUE
						<< Integer(0)
					 << EndMap();
		call.invoke(networkManager, urlTest2, this, SLOT(argTypedMap_3()), SLOT(error(int, const QString&)));
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

	void argTypedFixedList_0() {
		EXCEPT_TRUE
	}

	void argTypedFixedList_1() {
		EXCEPT_TRUE
	}

	void argTypedFixedList_7() {
		EXCEPT_TRUE
	}

	void argTypedFixedList_8() {
		EXCEPT_TRUE
	}

	void argUntypedMap_0() {
		EXCEPT_TRUE
	}

	void argUntypedMap_1() {
		EXCEPT_TRUE
	}

	void argUntypedMap_2() {
		EXCEPT_TRUE
	}

	void argUntypedMap_3() {
		EXCEPT_TRUE
	}

	void argTypedMap_0() {
		EXCEPT_TRUE
	}

	void argTypedMap_1() {
		EXCEPT_TRUE
	}

	void argTypedMap_2() {
		EXCEPT_TRUE
	}

	void argTypedMap_3() {
		EXCEPT_TRUE
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QCAUCHOTEST2_H_ */
