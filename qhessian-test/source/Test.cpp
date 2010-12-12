/*
 * Test.cpp
 *
 *  Created on: 01.11.2010
 *      Author: caiiiycuk
 */

#ifndef TEST_CPP_
#define TEST_CPP_

#include "QSanityCheckTest.h"
#include "QCauchoTest.h"
#include "QCauchoTest2.h"
#include "QFruitTest.h"
#include "QStringTest.h"
#include "QNullTest.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    qDebug() << "Start tests";

    //
	// Set UTF8 String codec
	//

	const char* codecName = "utf8" ;

	QTextCodec::setCodecForLocale(QTextCodec::codecForName(codecName));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName(codecName));
	QTextCodec::setCodecForTr(QTextCodec::codecForName(codecName));

	//
	// Test stack
	//

    QSanityCheckTest 	sanityTest;
    QCauchoTest 		cauchoTest;
    QCauchoTest2 		cauchoTest2;
    QFruitTest			fruitTest;
    QStringTest			stringTest;
	QNullTest			nullTest;

    while (WAIT_FOR_TEST) {
    	QCoreApplication::processEvents();
    	QThread::currentThread()->yieldCurrentThread();
    }

    qDebug() << "All test finished";

	return 0;
}


#endif /* TEST_CPP_ */
