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
		// Null
		//
		argNullCall();

		//
		// boolean
		//
		argTrueCall();
		argFalseCall();

		//
		// integer
		//
		argInt_0Call();
		argInt_1Call();
		argInt_47Call();
		argInt_m16Call();
		argInt_0x30Call();
		argInt_0x7ffCall();
		argInt_m17Call();
		argInt_m0x800Call();
		argInt_0x800Call();
		argInt_0x3ffffCall();
		argInt_m0x801Call();
		argInt_m0x40000Call();
		argInt_0x40000Call();
		argInt_0x7fffffffCall();
		argInt_m0x40001Call();
		argInt_m0x80000000Call();

		//
		// longs
		//
		argLong_0Call();
		argLong_1Call();
		argLong_15Call();
		argLong_m8Call();
		argLong_0x10Call();
		argLong_0x7ffCall();
		argLong_m9Call();
		argLong_m0x800Call();
		argLong_0x800Call();
		argLong_0x3ffffCall();
		argLong_m0x801Call();
		argLong_m0x40000Call();
		argLong_0x40000Call();
		argLong_0x7fffffffCall();
		argLong_m0x40001Call();
		argLong_m0x80000000Call();
		argLong_0x80000000Call();
		argLong_m0x80000001Call();

		//
		// doubles
		//
		argDouble_0_0Call();
		argDouble_1_0Call();
		argDouble_2_0Call();
		argDouble_127_0Call();
		argDouble_m128_0Call();
		argDouble_128_0Call();
		argDouble_m129_0Call();
		argDouble_32767_0Call();
		argDouble_m32768_0Call();
		argDouble_0_001Call();
		argDouble_m0_001Call();
		argDouble_65_536Call();
		argDouble_3_14159Call();

		//
		// date
		//
		argDate_0Call();
		argDate_1Call();
		argDate_2Call();

		//
		// string
		//
		argString_0Call();
		argString_1Call();
		argString_31Call();
		argString_32Call();
		argString_1023Call();
		argString_1024Call();
		argString_65536Call();

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

		//
		// objects
		//
		argObject_0Call();
		argObject_16Call();
		argObject_1Call();
		argObject_2Call();
		argObject_2aCall();
		argObject_2bCall();
		argObject_3Call();
	}

	void methodNull() {
		TEST_START

		QHessian::QHessianMethodCall call("methodNull");
		call.invoke(networkManager, urlTest2, this, SLOT(replyNullCall()), SLOT(error(int, const QString&)));
	}

	void argNullCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argNull");
		call << Null();
		call.invoke(networkManager, urlTest2, this, SLOT(argNull()), SLOT(error(int, const QString&)));
	}

	void argTrueCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argTrue");
		call << Boolean(true);
		call.invoke(networkManager, urlTest2, this, SLOT(argTrue()), SLOT(error(int, const QString&)));
	}

	void argFalseCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argFalse");
		call << Boolean(false);
		call.invoke(networkManager, urlTest2, this, SLOT(argFalse()), SLOT(error(int, const QString&)));
	}

	void argInt_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_0");
		call << Integer(0);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_0()), SLOT(error(int, const QString&)));
	}

	void argInt_1Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_1");
		call << Integer(1);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_1()), SLOT(error(int, const QString&)));
	}

	void argInt_47Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_47");
		call << Integer(47);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_47()), SLOT(error(int, const QString&)));
	}

	void argInt_m16Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_m16");
		call << Integer(-16);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_m16()), SLOT(error(int, const QString&)));
	}

	void argInt_0x30Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_0x30");
		call << Integer(0x30);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_0x30()), SLOT(error(int, const QString&)));
	}

	void argInt_0x7ffCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_0x7ff");
		call << Integer(0x7ff);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_0x7ff()), SLOT(error(int, const QString&)));
	}

	void argInt_m17Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_m17");
		call << Integer(-17);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_m17()), SLOT(error(int, const QString&)));
	}

	void argInt_m0x800Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_m0x800");
		call << Integer(-0x800);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_m0x800()), SLOT(error(int, const QString&)));
	}

	void argInt_0x800Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_0x800");
		call << Integer(0x800);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_0x800()), SLOT(error(int, const QString&)));
	}

	void argInt_0x3ffffCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_0x3ffff");
		call << Integer(0x3ffff);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_0x3ffff()), SLOT(error(int, const QString&)));
	}

	void argInt_m0x801Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_m0x801");
		call << Integer(-0x801);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_m0x801()), SLOT(error(int, const QString&)));
	}

	void argInt_m0x40000Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_m0x40000");
		call << Integer(-0x40000);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_m0x40000()), SLOT(error(int, const QString&)));
	}

	void argInt_0x40000Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_0x40000");
		call << Integer(0x40000);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_0x40000()), SLOT(error(int, const QString&)));
	}

	void argInt_0x7fffffffCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_0x7fffffff");
		call << Integer(0x7fffffff);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_0x7fffffff()), SLOT(error(int, const QString&)));
	}

	void argInt_m0x40001Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_m0x40001");
		call << Integer(-0x40001);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_m0x40001()), SLOT(error(int, const QString&)));
	}

	void argInt_m0x80000000Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argInt_m0x80000000");
		call << Integer(-0x80000000);
		call.invoke(networkManager, urlTest2, this, SLOT(argInt_m0x80000000()), SLOT(error(int, const QString&)));
	}

	void argLong_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0");
		call << Long(0);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0()), SLOT(error(int, const QString&)));
	}

	void argLong_1Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_1");
		call << Long(1);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_1()), SLOT(error(int, const QString&)));
	}

	void argLong_15Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_15");
		call << Long(15);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_15()), SLOT(error(int, const QString&)));
	}

	void argLong_m8Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m8");
		call << Long(-8);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m8()), SLOT(error(int, const QString&)));
	}

	void argLong_0x10Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0x10");
		call << Long(0x10);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0x10()), SLOT(error(int, const QString&)));
	}

	void argLong_0x7ffCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0x7ff");
		call << Long(0x7ff);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0x7ff()), SLOT(error(int, const QString&)));
	}

	void argLong_m9Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m9");
		call << Long(-9);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m9()), SLOT(error(int, const QString&)));
	}

	void argLong_m0x800Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m0x800");
		call << Long(-0x800);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m0x800()), SLOT(error(int, const QString&)));
	}

	void argLong_0x800Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0x800");
		call << Long(0x800);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0x800()), SLOT(error(int, const QString&)));
	}

	void argLong_0x3ffffCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0x3ffff");
		call << Long(0x3ffff);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0x3ffff()), SLOT(error(int, const QString&)));
	}

	void argLong_m0x801Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m0x801");
		call << Long(-0x801);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m0x801()), SLOT(error(int, const QString&)));
	}

	void argLong_m0x40000Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m0x40000");
		call << Long(-0x40000);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m0x40000()), SLOT(error(int, const QString&)));
	}

	void argLong_0x40000Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0x40000");
		call << Long(0x40000);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0x40000()), SLOT(error(int, const QString&)));
	}

	void argLong_0x7fffffffCall() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0x7fffffff");
		call << Long(0x7fffffff);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0x7fffffff()), SLOT(error(int, const QString&)));
	}

	void argLong_m0x40001Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m0x40001");
		call << Long(-0x40001);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m0x40001()), SLOT(error(int, const QString&)));
	}

	void argLong_m0x80000000Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m0x80000000");
		call << Long(-0x80000000ll);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m0x80000000()), SLOT(error(int, const QString&)));
	}

	void argLong_0x80000000Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_0x80000000");
		call << Long(0x80000000ll);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_0x80000000()), SLOT(error(int, const QString&)));
	}

	void argLong_m0x80000001Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argLong_m0x80000001");
		call << Long(-0x80000001ll);
		call.invoke(networkManager, urlTest2, this, SLOT(argLong_m0x80000001()), SLOT(error(int, const QString&)));
	}

	void argDouble_0_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_0_0");
		call << Double(0.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_0_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_1_0Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argDouble_1_0");
		call << Double(1.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_1_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_2_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_2_0");
		call << Double(2.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_2_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_127_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_127_0");
		call << Double(127.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_127_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_m128_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_m128_0");
		call << Double(-128.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_m128_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_128_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_128_0");
		call << Double(128.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_128_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_m129_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_m129_0");
		call << Double(-129.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_m129_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_32767_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_32767_0");
		call << Double(32767.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_32767_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_m32768_0Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_m32768_0");
		call << Double(-32768.0);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_m32768_0()), SLOT(error(int, const QString&)));
	}

	void argDouble_0_001Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_0_001");
		call << Double(0.001);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_0_001()), SLOT(error(int, const QString&)));
	}

	void argDouble_m0_001Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_m0_001");
		call << Double(-0.001);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_m0_001()), SLOT(error(int, const QString&)));
	}

	void argDouble_65_536Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_65_536");
		call << Double(65.536);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_65_536()), SLOT(error(int, const QString&)));
	}

	void argDouble_3_14159Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argDouble_3_14159");
		call << Double(3.14159);
		call.invoke(networkManager, urlTest2, this, SLOT(argDouble_3_14159()), SLOT(error(int, const QString&)));
	}

		void argDate_0Call() {
		QDateTime date;

		TEST_START

		using namespace QHessian::in;

		date.setMSecsSinceEpoch(0);
		QHessian::QHessianMethodCall call("argDate_0");
		call << DateTime(date);
		call.invoke(networkManager, urlTest2, this, SLOT(argDate_0()), SLOT(error(int, const QString&)));
	}

		void argDate_1Call() {
		QDateTime date;

		TEST_START

		using namespace QHessian::in;

		date.setMSecsSinceEpoch(894621091000LL);
		QHessian::QHessianMethodCall call("argDate_1");
		call << DateTime(date);
		call.invoke(networkManager, urlTest2, this, SLOT(argDate_1()), SLOT(error(int, const QString&)));
	}

		void argDate_2Call() {
		QDateTime date;

		TEST_START

		using namespace QHessian::in;

		date.setMSecsSinceEpoch(894621091000LL - (894621091000LL % 60000LL));
		QHessian::QHessianMethodCall call("argDate_2");
		call << DateTime(date);
		call.invoke(networkManager, urlTest2, this, SLOT(argDate_2()), SLOT(error(int, const QString&)));
	}

	void argString_0Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argString_0");
		call << String(QString(""));
		call.invoke(networkManager, urlTest2, this, SLOT(argString_0()), SLOT(error(int, const QString&)));
	}

	void argString_1Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argString_1");
		call << String(QString("0"));
		call.invoke(networkManager, urlTest2, this, SLOT(argString_1()), SLOT(error(int, const QString&)));
	}

	void argString_31Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argString_31");
		call << String(QString("0123456789012345678901234567890"));
		call.invoke(networkManager, urlTest2, this, SLOT(argString_31()), SLOT(error(int, const QString&)));
	}

	void argString_32Call() {
		TEST_START

		using namespace QHessian::in;

		QHessian::QHessianMethodCall call("argString_32");
		call << String(QString("01234567890123456789012345678901"));
		call.invoke(networkManager, urlTest2, this, SLOT(argString_32()), SLOT(error(int, const QString&)));
	}

	void argString_1023Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argString_1023");
		call << String(generateString(1023));
		call.invoke(networkManager, urlTest2, this, SLOT(argString_1023()), SLOT(error(int, const QString&)));
	}

	void argString_1024Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argString_1024");
		call << String(generateString(1024));
		call.invoke(networkManager, urlTest2, this, SLOT(argString_1024()), SLOT(error(int, const QString&)));
	}

	void argString_65536Call() {
		TEST_START

		using namespace QHessian::in;


		QHessian::QHessianMethodCall call("argString_65536");
		call << String(generateString(65536));
		call.invoke(networkManager, urlTest2, this, SLOT(argString_65536()), SLOT(error(int, const QString&)));
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

	void argObject_0Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argObject_0");
		call << BeginObject("com.caucho.hessian.test.A0")
			 << EndObject();
		call.invoke(networkManager, urlTest2, this, SLOT(argObject_0()), SLOT(error(int, const QString&)));
	}

	void argObject_16Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argObject_16");

		call << BeginCollection(17)
				<< BeginObject("com.caucho.hessian.test.A0")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A1")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A2")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A3")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A4")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A5")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A6")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A7")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A8")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A9")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A10")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A11")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A12")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A13")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A14")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A15")
				<< EndObject()
				<< BeginObject("com.caucho.hessian.test.A16")
				<< EndObject()
			 << EndCollection();

		call.invoke(networkManager, urlTest2, this, SLOT(argObject_16()), SLOT(error(int, const QString&)));
	}

	void argObject_1Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argObject_1");
		call << BeginObject("com.caucho.hessian.test.TestObject")
				<< Integer("_value", 0)
			 << EndObject();
		call.invoke(networkManager, urlTest2, this, SLOT(argObject_1()), SLOT(error(int, const QString&)));
	}

	void argObject_2Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argObject_2");
		call << BeginCollection(2)
				 << BeginObject("com.caucho.hessian.test.TestObject")
					<< Integer("_value", 0)
				 << EndObject()
				 << BeginObject("com.caucho.hessian.test.TestObject")
					<< Integer("_value", 1)
				 << EndObject()
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argObject_2()), SLOT(error(int, const QString&)));
	}

	void argObject_2aCall() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argObject_2a");
		call << BeginCollection(2) 	// first object
				 << BeginObject("com.caucho.hessian.test.TestObject") 	//
					<< Integer("_value", 0)								// secong object (first is list)
				 << EndObject()											//
				 << Ref(1)			// ref to com.caucho.hessian.test.TestObject
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argObject_2a()), SLOT(error(int, const QString&)));
	}

	void argObject_2bCall() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argObject_2b");
		call << BeginCollection(2)
				 << BeginObject("com.caucho.hessian.test.TestObject")
					<< Integer("_value", 0)
				 << EndObject()
				 << BeginObject("com.caucho.hessian.test.TestObject")
					<< Integer("_value", 0)
				 << EndObject()
			 << EndCollection();
		call.invoke(networkManager, urlTest2, this, SLOT(argObject_2b()), SLOT(error(int, const QString&)));
	}

	void argObject_3Call() {
		TEST_START

		using namespace QHessian::in;
		QHessian::QHessianMethodCall call("argObject_3");
		call << BeginObject("com.caucho.hessian.test.TestCons")
				<< String("_first", "a")
				<< Ref("_rest", 0)			// ref tocom.caucho.hessian.test.TestCons
			 << EndObject();
		call.invoke(networkManager, urlTest2, this, SLOT(argObject_3()), SLOT(error(int, const QString&)));
	}

public slots:
	void replyNullCall() {
		TEST_END
	}

	void argNull() {
		EXCEPT_TRUE
	}

	void argTrue() {
		EXCEPT_TRUE
	}

	void argFalse() {
		EXCEPT_TRUE
	}

	void argInt_0() {
		EXCEPT_TRUE
	}

	void argInt_1() {
		EXCEPT_TRUE
	}

	void argInt_47() {
		EXCEPT_TRUE
	}

	void argInt_m16() {
		EXCEPT_TRUE
	}

	void argInt_0x30() {
		EXCEPT_TRUE
	}

	void argInt_0x7ff() {
		EXCEPT_TRUE
	}

	void argInt_m17() {
		EXCEPT_TRUE
	}

	void argInt_m0x800() {
		EXCEPT_TRUE
	}

	void argInt_0x800() {
		EXCEPT_TRUE
	}

	void argInt_0x3ffff() {
		EXCEPT_TRUE
	}

	void argInt_m0x801() {
		EXCEPT_TRUE
	}

	void argInt_m0x40000() {
		EXCEPT_TRUE
	}

	void argInt_0x40000() {
		EXCEPT_TRUE
	}

	void argInt_0x7fffffff() {
		EXCEPT_TRUE
	}

	void argInt_m0x40001() {
		EXCEPT_TRUE
	}

	void argInt_m0x80000000() {
		EXCEPT_TRUE
	}

	void argLong_0() {
		EXCEPT_TRUE
	}

	void argLong_1() {
		EXCEPT_TRUE
	}

	void argLong_15() {
		EXCEPT_TRUE
	}

	void argLong_m8() {
		EXCEPT_TRUE
	}

	void argLong_0x10() {
		EXCEPT_TRUE
	}

	void argLong_0x7ff() {
		EXCEPT_TRUE
	}

	void argLong_m9() {
		EXCEPT_TRUE
	}

	void argLong_m0x800() {
		EXCEPT_TRUE
	}

	void argLong_0x800() {
		EXCEPT_TRUE
	}

	void argLong_0x3ffff() {
		EXCEPT_TRUE
	}

	void argLong_m0x801() {
		EXCEPT_TRUE
	}

	void argLong_m0x40000() {
		EXCEPT_TRUE
	}

	void argLong_0x40000() {
		EXCEPT_TRUE
	}

	void argLong_0x7fffffff() {
		EXCEPT_TRUE
	}

	void argLong_m0x40001() {
		EXCEPT_TRUE
	}

	void argLong_m0x80000000() {
		EXCEPT_TRUE
	}

	void argLong_0x80000000() {
		EXCEPT_TRUE
	}

	void argLong_m0x80000001() {
		EXCEPT_TRUE
	}

	void argDouble_0_0() {
		EXCEPT_TRUE
	}

	void argDouble_1_0() {
		EXCEPT_TRUE
	}

	void argDouble_2_0() {
		EXCEPT_TRUE
	}

	void argDouble_127_0() {
		EXCEPT_TRUE
	}

	void argDouble_m128_0() {
		EXCEPT_TRUE
	}

	void argDouble_128_0() {
		EXCEPT_TRUE
	}

	void argDouble_m129_0() {
		EXCEPT_TRUE
	}

	void argDouble_32767_0() {
		EXCEPT_TRUE
	}

	void argDouble_m32768_0() {
		EXCEPT_TRUE
	}

	void argDouble_0_001() {
		EXCEPT_TRUE
	}

	void argDouble_m0_001() {
		EXCEPT_TRUE
	}

	void argDouble_65_536() {
		EXCEPT_TRUE
	}

	void argDouble_3_14159() {
		EXCEPT_TRUE
	}

	void argDate_0() {
		EXCEPT_TRUE
	}

	void argDate_1() {
		EXCEPT_TRUE
	}

	void argDate_2() {
		EXCEPT_TRUE
	}

	void argString_0() {
		EXCEPT_TRUE
	}

	void argString_1() {
		EXCEPT_TRUE
	}

	void argString_31() {
		EXCEPT_TRUE
	}

	void argString_32() {
		EXCEPT_TRUE
	}

	void argString_1023() {
		EXCEPT_TRUE
	}

	void argString_1024() {
		EXCEPT_TRUE
	}

	void argString_65536() {
		EXCEPT_TRUE
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

	void argObject_0() {
		EXCEPT_TRUE
	}

	void argObject_16() {
		EXCEPT_TRUE
	}

	void argObject_1() {
		EXCEPT_TRUE
	}

	void argObject_2() {
		EXCEPT_TRUE
	}

	void argObject_2a() {
		EXCEPT_TRUE
	}

	void argObject_2b() {
		EXCEPT_TRUE
	}

	void argObject_3() {
		EXCEPT_TRUE
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QCAUCHOTEST2_H_ */
