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

		//
		// booleans
		//
		replyTrueCall();
		replyFalseCall();

		//
		// integers
		//
		replyInt_0Call();
		replyInt_1Call();
		replyInt_47Call();
		replyInt_m16Call();
		replyInt_0x30Call();
		replyInt_0x7ffCall();
		replyInt_m17Call();
		replyInt_m0x800Call();
		replyInt_0x800Call();
		replyInt_0x3ffffCall();
		replyInt_m0x801Call();
		replyInt_m0x40000Call();
		replyInt_0x40000Call();
		replyInt_0x7fffffffCall();
		replyInt_m0x40001Call();
		replyInt_m0x80000000Call();

		//
		// longs
		//
		replyLong_0Call();
		replyLong_1Call();
		replyLong_15Call();
		replyLong_m8Call();
		replyLong_0x10Call();
		replyLong_0x7ffCall();
		replyLong_m9Call();
		replyLong_m0x800Call();
		replyLong_0x800Call();
		replyLong_0x3ffffCall();
		replyLong_m0x801Call();
		replyLong_m0x40000Call();
		replyLong_0x40000Call();
		replyLong_0x7fffffffCall();
		replyLong_m0x40001Call();
		replyLong_m0x80000000Call();
		replyLong_0x80000000Call();
		replyLong_m0x80000001Call();

		//
		// doubles
		//
		replyDouble_0_0Call();
		replyDouble_1_0Call();
		replyDouble_2_0Call();
		replyDouble_127_0Call();
		replyDouble_m128_0Call();
		replyDouble_128_0Call();
		replyDouble_m129_0Call();
		replyDouble_32767_0Call();
		replyDouble_m32768_0Call();
		replyDouble_0_001Call();
		replyDouble_m0_001Call();
		replyDouble_65_536Call();
		replyDouble_3_14159Call();

		//
		// dates
		//
		replyDate_0Call();
		replyDate_1Call();
		replyDate_2Call();

		//
		// strings
		//
		replyString_0Call();    // what is difference
		replyString_nullCall(); // between these two tests?
		replyString_1Call();
		replyString_31Call();
		replyString_32Call();
		replyString_1023Call();
		replyString_1024Call();
		replyString_65536Call();

		//
		// binary length
		//
		replyBinary_0Call();
		replyBinary_nullCall();
		replyBinary_1Call();
		replyBinary_15Call();
		replyBinary_16Call();
		replyBinary_1023Call();
		replyBinary_1024Call();
		replyBinary_65536Call();

		//
		// Untyped lists
		//
		replyUntypedFixedList_0Call();
		replyUntypedFixedList_1Call();
		replyUntypedFixedList_7Call();
		replyUntypedFixedList_8Call();

		//
		// Typed lists
		//
		replyTypedFixedList_0Call();
		replyTypedFixedList_1Call();
		replyTypedFixedList_7Call();
		replyTypedFixedList_8Call();

		//
		// untyped maps
		//
		replyUntypedMap_0Call();
		replyUntypedMap_1Call();
		replyUntypedMap_2Call();
		replyUntypedMap_3Call();

		//
		// typed maps
		//
		replyTypedMap_0Call();
		replyTypedMap_1Call();
		replyTypedMap_2Call();
		replyTypedMap_3Call();

		//
		// objects
		//
		replyObject_0Call();
		replyObject_16Call();
		replyObject_1Call();
		replyObject_2Call();
		replyObject_2aCall();
		replyObject_2bCall();
		replyObject_3Call();
	}

	void methodNull() {
		TEST_START

		QHessian::QHessianMethodCall call("methodNull");
		call.invoke(networkManager, urlTest2, this, SLOT(replyNullCall()), SLOT(error(int, const QString&)));
	}

	void replyNull() {
		TEST_START

		QHessian::QHessianMethodCall call("replyNull");
		call.invoke(networkManager, urlTest2, this, SLOT(replyNullCall()), SLOT(error(int, const QString&)));
	}

	void replyTrueCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTrue");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTrue()), SLOT(error(int, const QString&)));
	}

	void replyFalseCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyFalse");
		call.invoke(networkManager, urlTest2, this, SLOT(replyFalse()), SLOT(error(int, const QString&)));
	}

	void replyInt_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_0()), SLOT(error(int, const QString&)));
	}

	void replyInt_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_1()), SLOT(error(int, const QString&)));
	}

	void replyInt_47Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_47");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_47()), SLOT(error(int, const QString&)));
	}

		void replyInt_m16Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_m16");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_m16()), SLOT(error(int, const QString&)));
	}

	void replyInt_0x30Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_0x30");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_0x30()), SLOT(error(int, const QString&)));
	}

	void replyInt_0x7ffCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_0x7ff");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_0x7ff()), SLOT(error(int, const QString&)));
	}

	void replyInt_m17Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_m17");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_m17()), SLOT(error(int, const QString&)));
	}

	void replyInt_m0x800Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_m0x800");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_m0x800()), SLOT(error(int, const QString&)));
	}

	void replyInt_0x800Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_0x800");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_0x800()), SLOT(error(int, const QString&)));
	}

	void replyInt_0x3ffffCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_0x3ffff");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_0x3ffff()), SLOT(error(int, const QString&)));
	}

	void replyInt_m0x801Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_m0x801");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_m0x801()), SLOT(error(int, const QString&)));
	}

	void replyInt_m0x40000Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_m0x40000");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_m0x40000()), SLOT(error(int, const QString&)));
	}

	void replyInt_0x40000Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_0x40000");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_0x40000()), SLOT(error(int, const QString&)));
	}

	void replyInt_0x7fffffffCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_0x7fffffff");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_0x7fffffff()), SLOT(error(int, const QString&)));
	}

	void replyInt_m0x40001Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_m0x40001");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_m0x40001()), SLOT(error(int, const QString&)));
	}

	void replyInt_m0x80000000Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyInt_m0x80000000");
		call.invoke(networkManager, urlTest2, this, SLOT(replyInt_m0x80000000()), SLOT(error(int, const QString&)));
	}

	void replyLong_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0()), SLOT(error(int, const QString&)));
	}

	void replyLong_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_1()), SLOT(error(int, const QString&)));
	}

	void replyLong_15Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_15");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_15()), SLOT(error(int, const QString&)));
	}

	void replyLong_m8Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m8");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m8()), SLOT(error(int, const QString&)));
	}

	void replyLong_0x10Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0x10");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0x10()), SLOT(error(int, const QString&)));
	}

	void replyLong_0x7ffCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0x7ff");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0x7ff()), SLOT(error(int, const QString&)));
	}

	void replyLong_m9Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m9");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m9()), SLOT(error(int, const QString&)));
	}

	void replyLong_m0x800Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m0x800");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m0x800()), SLOT(error(int, const QString&)));
	}

	void replyLong_0x800Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0x800");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0x800()), SLOT(error(int, const QString&)));
	}

	void replyLong_0x3ffffCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0x3ffff");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0x3ffff()), SLOT(error(int, const QString&)));
	}

	void replyLong_m0x801Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m0x801");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m0x801()), SLOT(error(int, const QString&)));
	}

	void replyLong_m0x40000Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m0x40000");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m0x40000()), SLOT(error(int, const QString&)));
	}

	void replyLong_0x40000Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0x40000");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0x40000()), SLOT(error(int, const QString&)));
	}

	void replyLong_0x7fffffffCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0x7fffffff");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0x7fffffff()), SLOT(error(int, const QString&)));
	}

	void replyLong_m0x40001Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m0x40001");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m0x40001()), SLOT(error(int, const QString&)));
	}

	void replyLong_m0x80000000Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m0x80000000");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m0x80000000()), SLOT(error(int, const QString&)));
	}

	void replyLong_0x80000000Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_0x80000000");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_0x80000000()), SLOT(error(int, const QString&)));
	}

	void replyLong_m0x80000001Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyLong_m0x80000001");
		call.invoke(networkManager, urlTest2, this, SLOT(replyLong_m0x80000001()), SLOT(error(int, const QString&)));
	}

	void replyDouble_0_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_0_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_0_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_1_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_1_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_1_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_2_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_2_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_2_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_127_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_127_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_127_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_m128_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_m128_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_m128_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_128_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_128_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_128_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_m129_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_m129_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_m129_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_32767_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_32767_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_32767_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_m32768_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_m32768_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_m32768_0()), SLOT(error(int, const QString&)));
	}

	void replyDouble_0_001Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_0_001");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_0_001()), SLOT(error(int, const QString&)));
	}

	void replyDouble_m0_001Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_m0_001");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_m0_001()), SLOT(error(int, const QString&)));
	}

	void replyDouble_65_536Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_65_536");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_65_536()), SLOT(error(int, const QString&)));
	}

	void replyDouble_3_14159Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDouble_3_14159");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDouble_3_14159()), SLOT(error(int, const QString&)));
	}

	void replyDate_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDate_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDate_0()), SLOT(error(int, const QString&)));
	}

	void replyDate_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDate_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDate_1()), SLOT(error(int, const QString&)));
	}

	void replyDate_2Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyDate_2");
		call.invoke(networkManager, urlTest2, this, SLOT(replyDate_2()), SLOT(error(int, const QString&)));
	}

	void replyString_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_0()), SLOT(error(int, const QString&)));
	}

	void replyString_nullCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_null");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_null()), SLOT(error(int, const QString&)));
	}

	void replyString_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_1()), SLOT(error(int, const QString&)));
	}

	void replyString_31Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_31");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_31()), SLOT(error(int, const QString&)));
	}

	void replyString_32Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_32");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_32()), SLOT(error(int, const QString&)));
	}

	void replyString_1023Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_1023");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_1023()), SLOT(error(int, const QString&)));
	}

	void replyString_1024Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_1024");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_1024()), SLOT(error(int, const QString&)));
	}

	void replyString_65536Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyString_65536");
		call.invoke(networkManager, urlTest2, this, SLOT(replyString_65536()), SLOT(error(int, const QString&)));
	}

    void replyBinary_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_0()), SLOT(error(int, const QString&)));
	}

	void replyBinary_nullCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_null");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_null()), SLOT(error(int, const QString&)));
	}

	void replyBinary_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_1()), SLOT(error(int, const QString&)));
	}

	void replyBinary_15Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_15");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_15()), SLOT(error(int, const QString&)));
	}

	void replyBinary_16Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_16");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_16()), SLOT(error(int, const QString&)));
	}

	void replyBinary_1023Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_1023");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_1023()), SLOT(error(int, const QString&)));
	}

	void replyBinary_1024Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_1024");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_1024()), SLOT(error(int, const QString&)));
	}

	void replyBinary_65536Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyBinary_65536");
		call.invoke(networkManager, urlTest2, this, SLOT(replyBinary_65536()), SLOT(error(int, const QString&)));
	}

	void replyUntypedFixedList_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedFixedList_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedFixedList_0()), SLOT(error(int, const QString&)));
	}

	void replyUntypedFixedList_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedFixedList_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedFixedList_1()), SLOT(error(int, const QString&)));
	}

	void replyUntypedFixedList_7Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedFixedList_7");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedFixedList_7()), SLOT(error(int, const QString&)));
	}

	void replyUntypedFixedList_8Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedFixedList_8");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedFixedList_8()), SLOT(error(int, const QString&)));
	}

	void replyTypedFixedList_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedFixedList_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedFixedList_0()), SLOT(error(int, const QString&)));
	}

	void replyTypedFixedList_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedFixedList_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedFixedList_1()), SLOT(error(int, const QString&)));
	}

	void replyTypedFixedList_7Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedFixedList_7");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedFixedList_7()), SLOT(error(int, const QString&)));
	}

	void replyTypedFixedList_8Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedFixedList_8");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedFixedList_8()), SLOT(error(int, const QString&)));
	}

	void replyUntypedMap_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedMap_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedMap_0()), SLOT(error(int, const QString&)));
	}

	void replyUntypedMap_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedMap_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedMap_1()), SLOT(error(int, const QString&)));
	}

	void replyUntypedMap_2Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedMap_2");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedMap_2()), SLOT(error(int, const QString&)));
	}

	void replyUntypedMap_3Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyUntypedMap_3");
		call.invoke(networkManager, urlTest2, this, SLOT(replyUntypedMap_3()), SLOT(error(int, const QString&)));
	}

	void replyTypedMap_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedMap_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedMap_0()), SLOT(error(int, const QString&)));
	}

	void replyTypedMap_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedMap_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedMap_1()), SLOT(error(int, const QString&)));
	}

	void replyTypedMap_2Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedMap_2");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedMap_2()), SLOT(error(int, const QString&)));
	}

	void replyTypedMap_3Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyTypedMap_3");
		call.invoke(networkManager, urlTest2, this, SLOT(replyTypedMap_3()), SLOT(error(int, const QString&)));
	}

	void replyObject_0Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyObject_0");
		call.invoke(networkManager, urlTest2, this, SLOT(replyObject_0()), SLOT(error(int, const QString&)));
	}

	void replyObject_16Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyObject_16");
		call.invoke(networkManager, urlTest2, this, SLOT(replyObject_16()), SLOT(error(int, const QString&)));
	}

	void replyObject_1Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyObject_1");
		call.invoke(networkManager, urlTest2, this, SLOT(replyObject_1()), SLOT(error(int, const QString&)));
	}

	void replyObject_2Call() {
		TEST_START

		QHessian::QHessianMethodCall call("replyObject_2");
		call.invoke(networkManager, urlTest2, this, SLOT(replyObject_2()), SLOT(error(int, const QString&)));
	}

	void replyObject_2aCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyObject_2a");
		call.invoke(networkManager, urlTest2, this, SLOT(replyObject_2a()), SLOT(error(int, const QString&)));
	}

	void replyObject_2bCall() {
		TEST_START

		QHessian::QHessianMethodCall call("replyObject_2b");
		call.invoke(networkManager, urlTest2, this, SLOT(replyObject_2b()), SLOT(error(int, const QString&)));
	}

	void replyObject_3Call(){
		TEST_START

		QHessian::QHessianMethodCall call("replyObject_3");
		call.invoke(networkManager, urlTest2, this, SLOT(replyObject_3()), SLOT(error(int, const QString&)));
	}

public slots:
	void replyNullCall() {
		TEST_END
	}
	void replyTrue() {
        bool boolean;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Boolean(boolean);
        parser.deleteLater();

        COMPARE(boolean, true);

		TEST_END
	}

	void replyFalse() {
        bool boolean;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Boolean(boolean);
        parser.deleteLater();

        COMPARE(boolean, false);

		TEST_END
	}

	void replyInt_0() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0);

		TEST_END
	}

	void replyInt_1() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)1);

		TEST_END
	}

	void replyInt_47() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)47);

		TEST_END
	}

	void replyInt_m16() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)-16);

		TEST_END
	}

	void replyInt_0x30() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0x30);

		TEST_END
	}

	void replyInt_0x7ff() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0x7ff);

		TEST_END
	}

	void replyInt_m17() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)-17);

		TEST_END
	}

	void replyInt_m0x800() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)-0x800);

		TEST_END
	}

	void replyInt_0x800() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0x800);

		TEST_END
	}

	void replyInt_0x3ffff() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0x3ffff);

		TEST_END
	}

	void replyInt_m0x801() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)-0x801);

		TEST_END
	}

	void replyInt_m0x40000() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)-0x40000);

		TEST_END
	}

	void replyInt_0x40000() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0x40000);

		TEST_END
	}

	void replyInt_0x7fffffff() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0x7fffffff);

		TEST_END
	}

	void replyInt_m0x40001() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)-0x40001);

		TEST_END
	}

	void replyInt_m0x80000000() {
        qint32 integer;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Integer(integer);
        parser.deleteLater();

        COMPARE(integer, (qint32)0x80000000); //minus is dropped because of "unary minus operator applied to unsigned type, result still unsigned"

		TEST_END
	}

	void replyLong_0() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0LL);

		TEST_END
	}

	void replyLong_1() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 1LL);

		TEST_END
	}

	void replyLong_15() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 15LL);

		TEST_END
	}

	void replyLong_m8() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -8LL);

		TEST_END
	}

	void replyLong_0x10() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0x10LL);

		TEST_END
	}

	void replyLong_0x7ff() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0x7ffLL);

		TEST_END
	}

	void replyLong_m9() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -9LL);

		TEST_END
	}

	void replyLong_m0x800() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -0x800LL);

		TEST_END
	}

	void replyLong_0x800() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0x800LL);

		TEST_END
	}

	void replyLong_0x3ffff() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0x3ffffLL);

		TEST_END
	}

	void replyLong_m0x801() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -0x801LL);

		TEST_END
	}

	void replyLong_m0x40000() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -0x40000LL);

		TEST_END
	}

	void replyLong_0x40000() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0x40000LL);

		TEST_END
	}

	void replyLong_0x7fffffff() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0x7fffffffLL);

		TEST_END
	}

	void replyLong_m0x40001() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -0x40001LL);

		TEST_END
	}

	void replyLong_m0x80000000() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -0x80000000LL);

		TEST_END
	}

	void replyLong_0x80000000() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, 0x80000000LL);

		TEST_END
	}

	void replyLong_m0x80000001() {
        qint64 longInt;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Long(longInt);
        parser.deleteLater();

        COMPARE(longInt, -0x80000001LL);

		TEST_END
	}

	void replyDouble_0_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)0);

		TEST_END
	}

	void replyDouble_1_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)1);

		TEST_END
	}

	void replyDouble_2_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)2);

		TEST_END
	}

	void replyDouble_127_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)127);

		TEST_END
	}

	void replyDouble_m128_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)-128);

		TEST_END
	}

	void replyDouble_128_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)128);

		TEST_END
	}

	void replyDouble_m129_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)-129);

		TEST_END
	}

	void replyDouble_32767_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)32767);

		TEST_END
	}

	void replyDouble_m32768_0() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)-32768);

		TEST_END
	}

	void replyDouble_0_001() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)0.001);

		TEST_END
	}

	void replyDouble_m0_001() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)-0.001);

		TEST_END
	}

	void replyDouble_65_536() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)65.536);

		TEST_END
	}

	void replyDouble_3_14159() {
        qreal real;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Double(real);
        parser.deleteLater();

        COMPARE(real, (qreal)3.14159);

		TEST_END
	}

	void replyDate_0() {
        QDateTime date;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> DateTime(date);
        parser.deleteLater();

        QDateTime x;
		x.setMSecsSinceEpoch(0);
        COMPARE(date, x);

		TEST_END
	}

	void replyDate_1() {
        QDateTime date;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> DateTime(date);
        parser.deleteLater();

        QDateTime x;
		x.setMSecsSinceEpoch(894621091000LL);
        COMPARE(date, x);

		TEST_END
	}

	void replyDate_2() {
        QDateTime date;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> DateTime(date);
        parser.deleteLater();

        QDateTime x;
		x.setMSecsSinceEpoch(894621091000LL - (894621091000LL % 60000LL));
        COMPARE(date, x);

		TEST_END
	}

	void replyString_0() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

        COMPARE(string, QString());

		TEST_END
	}

	void replyString_null() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

		COMPARE(string, QString());

		TEST_END
	}

	void replyString_1() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

        COMPARE(string, QString("0"));

		TEST_END
	}

	void replyString_31() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

        COMPARE(string, QString("0123456789012345678901234567890"));

		TEST_END
	}

	void replyString_32() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

        COMPARE(string, QString("01234567890123456789012345678901"));

		TEST_END
	}

	void replyString_1023() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

        COMPARE(string, generateString(1023));

		TEST_END
	}

	void replyString_1024() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

        COMPARE(string, generateString(1024));

		TEST_END
	}

	void replyString_65536() {
        QString string;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> String(string);
        parser.deleteLater();

        COMPARE(string, generateString(65536));

		TEST_END
	}

	void replyBinary_0() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 0);

		TEST_END
	}

	void replyBinary_null() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 0); //means null

		TEST_END
	}

	void replyBinary_1() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 1);
        COMPARE(binary.at(0).toAscii(), '0');

		TEST_END
	}

	void replyBinary_15() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 15);
        COMPARE(binary, QString("012345678901234"));

		TEST_END
	}

	void replyBinary_16() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 16);
        COMPARE(binary, QString("0123456789012345"));

		TEST_END
	}

	void replyBinary_1023() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 1023);
        COMPARE(binary, generateString(1023));

		TEST_END
	}

	void replyBinary_1024() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 1024);
        COMPARE(binary, generateString(1024));

		TEST_END
	}

	void replyBinary_65536() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.deleteLater();

        COMPARE(binary.length(), 65536);
        COMPARE(binary, generateString(65536));

		TEST_END
	}

	void replyUntypedFixedList_0() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 0, true);
        parser.deleteLater();

		TEST_END
	}

	void replyUntypedFixedList_1() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 1, true);
        parser.deleteLater();

		TEST_END
	}

	void replyUntypedFixedList_7() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 7, true);
        parser.deleteLater();

		TEST_END
	}

	void replyUntypedFixedList_8() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 8, true);
        parser.deleteLater();

		TEST_END
	}

	void replyTypedFixedList_0() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 0, false);
        parser.deleteLater();

		TEST_END
	}

	void replyTypedFixedList_1() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 1, false);
        parser.deleteLater();

		TEST_END
	}

	void replyTypedFixedList_7() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 7, false);
        parser.deleteLater();

		TEST_END
	}

	void replyTypedFixedList_8() {
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        compareFixedList(parser, 8, false);
        parser.deleteLater();

		TEST_END
	}

	void replyUntypedMap_0() {
		using namespace QHessian::out;

		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap();
		parser >> HasMoreMap(hasMore);
	    parser >> EndMap();
        parser.deleteLater();

        COMPARE(hasMore, false);

		TEST_END
	}

	void replyUntypedMap_1() {
		using namespace QHessian::out;

		QString key;
		qint32  value;
		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap();
		while ((parser >> HasMoreMap(hasMore), hasMore)) {
			parser >> String(key);
			parser >> Integer(value);
			COMPARE(key, QString("a"))
			COMPARE(value, 0)
		}
	    parser >> EndMap();


        parser.deleteLater();

		TEST_END
	}

	void replyUntypedMap_2() {
		using namespace QHessian::out;

		qint32 	key;
		QString value;
		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap();

        parser >> HasMoreMap(hasMore);
		parser >> Integer(key);
		parser >> String(value);

		COMPARE(hasMore, true)

		bool desc = true;

		if (key == 0) {
			COMPARE(key, 0)
			COMPARE(value, QString("a"))
			desc = false;
		} else {
			COMPARE(key, 1)
			COMPARE(value, QString("b"))
		}

		parser >> HasMoreMap(hasMore);
		parser >> Integer(key);
		parser >> String(value);

		COMPARE(hasMore, true)

		if (desc) {
			COMPARE(key, 0)
			COMPARE(value, QString("a"))
		} else {
			COMPARE(key, 1)
			COMPARE(value, QString("b"))
		}

		parser >> HasMoreMap(hasMore);
		COMPARE(hasMore, false)

	    parser >> EndMap();
        parser.deleteLater();

		TEST_END
	}

	void replyUntypedMap_3() {
		using namespace QHessian::out;

		QString	key;
		qint32 	value;
		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap();

        parser >> HasMoreMap(hasMore);
		COMPARE(hasMore, true)

        //key
        qint32 size;
		parser >> BeginCollection(size)
			   >> String(key)
			   >> EndCollection();

		COMPARE(size, 1)
		COMPARE(key, QString("a"))

		//value
		parser >> Integer(value);
		COMPARE(value, 0)

	    parser >> EndMap();
        parser.deleteLater();

		TEST_END
	}

	void replyTypedMap_0() {
		using namespace QHessian::out;

		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap("", "java.util.Hashtable");
		parser >> HasMoreMap(hasMore);
	    parser >> EndMap();
        parser.deleteLater();

        COMPARE(hasMore, false);

		TEST_END
	}

	void replyTypedMap_1() {
		using namespace QHessian::out;

		QString key;
		qint32  value;
		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap("", "java.util.Hashtable");
		while ((parser >> HasMoreMap(hasMore), hasMore)) {
			parser >> String(key);
			parser >> Integer(value);
			COMPARE(key, QString("a"))
			COMPARE(value, 0)
		}
	    parser >> EndMap();


        parser.deleteLater();

		TEST_END
	}

	void replyTypedMap_2() {
		using namespace QHessian::out;

		qint32 	key;
		QString value;
		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap("", "java.util.Hashtable");

        parser >> HasMoreMap(hasMore);
		parser >> Integer(key);
		parser >> String(value);

		COMPARE(hasMore, true)

		bool desc = true;

		if (key == 0) {
			COMPARE(key, 0)
			COMPARE(value, QString("a"))
			desc = false;
		} else {
			COMPARE(key, 1)
			COMPARE(value, QString("b"))
		}

		parser >> HasMoreMap(hasMore);
		parser >> Integer(key);
		parser >> String(value);

		COMPARE(hasMore, true)

		if (desc) {
			COMPARE(key, 0)
			COMPARE(value, QString("a"))
		} else {
			COMPARE(key, 1)
			COMPARE(value, QString("b"))
		}

		parser >> HasMoreMap(hasMore);
		COMPARE(hasMore, false)

	    parser >> EndMap();
        parser.deleteLater();

		TEST_END
	}

	void replyTypedMap_3() {
		using namespace QHessian::out;

		QString	key;
		qint32 	value;
		bool	hasMore;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginMap("", "java.util.Hashtable");

        parser >> HasMoreMap(hasMore);
		COMPARE(hasMore, true)

        //key
        qint32 size;
		parser >> BeginCollection(size)
			   >> String(key)
			   >> EndCollection();

		COMPARE(size, 1)
		COMPARE(key, QString("a"))

		//value
		parser >> Integer(value);
		COMPARE(value, 0)

	    parser >> EndMap();
        parser.deleteLater();

		TEST_END
	}

	void replyObject_0() {
		using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginObject("", "com.caucho.hessian.test.A0")
        	   >> EndObject();
        parser.deleteLater();

		TEST_END
	}

	void replyObject_16() {
		using namespace QHessian::out;

		qint32 size;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginCollection(size);

        for (int i=0; i<size; ++i) {
        	parser
        		>> BeginObject("", std::string("com.caucho.hessian.test.A")+QString::number(i).toStdString())
        		>> EndObject();
        }
        parser >> EndCollection();
        parser.deleteLater();

		TEST_END
	}

	void replyObject_1() {
		using namespace QHessian::out;

		qint32 _value;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser
        	>> BeginObject("", "com.caucho.hessian.test.TestObject")
        		>> Integer("_value", _value)
        	>> EndObject();
        parser.deleteLater();

        COMPARE(_value, 0)

		TEST_END
	}

	void replyObject_2() {
		using namespace QHessian::out;

		qint32 size;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginCollection(size);

        for (int i=0; i<size; ++i){
			qint32 _value;
        	parser 	>> BeginObject("", "com.caucho.hessian.test.TestObject")
        				>> Integer("_value", _value)
        			>> EndObject();

        	COMPARE(_value, i)
        }

        parser >> EndCollection();
        parser.deleteLater();

		TEST_END
	}

	void replyObject_2a() {
		using namespace QHessian::out;

		qint32 size;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginCollection(size);

        COMPARE(size, 2)

        qint32 _value;

		parser 	>> BeginObject("", "com.caucho.hessian.test.TestObject")
					>> Integer("_value", _value)
				>> EndObject();

		COMPARE(_value, 0)

		qint32 	refTo;

		parser  >> Ref(refTo);

		COMPARE(parser.wasNull(), false);
		COMPARE(refTo, 1);

        parser >> EndCollection();
        parser.deleteLater();

		TEST_END
	}

	void replyObject_2b() {
		using namespace QHessian::out;

		qint32 size;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> BeginCollection(size);

        COMPARE(size, 2)

        qint32 _value;

		parser 	>> BeginObject("", "com.caucho.hessian.test.TestObject")
					>> Integer("_value", _value)
				>> EndObject();

		COMPARE(_value, 0)

		parser 	>> BeginObject("", "com.caucho.hessian.test.TestObject")
					>> Integer("_value", _value)
				>> EndObject();

		COMPARE(_value, 0)

		TEST_END
	}

	void replyObject_3(){
		using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();

        QString first;
        qint32  ref;

		parser 	>> BeginObject("", "com.caucho.hessian.test.TestCons");
		parser	>> Ref("_first", ref);
		COMPARE(parser.wasNull(), true);
		parser	>> String("_first", first);
		parser	>> Ref("_rest", ref);
		COMPARE(parser.wasNull(), false);
		parser	>> EndObject();

		COMPARE(first, QString("a"))
		COMPARE(ref, 	 0)

		parser.deleteLater();

		TEST_END
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QCAUCHOTEST_H_ */
