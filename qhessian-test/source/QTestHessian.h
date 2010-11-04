/*
 * QTestHessian.h
 *
 *  Created on: 31.10.2010
 *      Author: caiiiycuk
 */

#ifndef QTESTHESSIAN_H_
#define QTESTHESSIAN_H_

#include "../rought_3_x/QHessian.h"
#include <QtNetwork/QNetworkAccessManager>
#include <stdexcept>

static const QUrl	urlTest1("http://localhost:8080/test1");

static QNetworkAccessManager networkManager;

class TestCounter {
protected:
	int testCount;

	TestCounter(): testCount(0) {
	}

public:
	void inc() {
		testCount++;
	}

	void dec() {
		testCount--;
	}

	bool hasMoreTests() {
		return testCount > 0;
	}

	static TestCounter& instance() {
		static TestCounter testCounter;
		return testCounter;
	}
};

template <typename T1, typename T2>
    void compare(T1 const &, T2 const &, const char *, const char *, const char *, int);

static void compare(QString const& a, QString const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual)
			+ " file " + std::string(file)
			+ " line " + QString::number(line).toStdString());
	}
}

#define COMPARE(actual, expected) \
    compare(actual, expected, #actual, #expected, __FILE__, __LINE__);

#define TEST_START 		TestCounter::instance().inc();
#define TEST_END		TestCounter::instance().dec();
#define WAIT_FOR_TEST	TestCounter::instance().hasMoreTests()

#endif /* QTESTHESSIAN_H_ */
