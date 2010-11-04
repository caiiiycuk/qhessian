/*
 * Test.cpp
 *
 *  Created on: 01.11.2010
 *      Author: caiiiycuk
 */

#ifndef TEST_CPP_
#define TEST_CPP_

#include "QSanityCheckTest.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    QSanityCheckTest test;

    while (WAIT_FOR_TEST) {
    	QCoreApplication::processEvents();
    	QThread::currentThread()->yieldCurrentThread();
    }

	return 0;
}


#endif /* TEST_CPP_ */
