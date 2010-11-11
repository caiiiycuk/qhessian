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

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    qDebug() << "Start tests";

    QSanityCheckTest 	sanityTest;
    QCauchoTest 		cauchoTest;
    QCauchoTest2 		cauchoTest2;

    while (WAIT_FOR_TEST) {
    	QCoreApplication::processEvents();
    	QThread::currentThread()->yieldCurrentThread();
    }

    qDebug() << "All test finished";

	return 0;
}


#endif /* TEST_CPP_ */
