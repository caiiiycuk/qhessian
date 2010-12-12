/*
 * QTestHessian.h
 *
 *  Created on: 31.10.2010
 *      Author: caiiiycuk
 */

#ifndef QTESTHESSIAN_H_
#define QTESTHESSIAN_H_

#include "../qhessian/QHessian.h"
#include <QtNetwork/QNetworkAccessManager>
#include <stdexcept>

static const QUrl	urlTest1("http://localhost:8080/test1");
static const QUrl	urlTest2("http://localhost:8080/test2");
static const QUrl	fruitUrl("http://localhost:8080/fruit");
static const QUrl	stringUrl("http://localhost:8080/string");
static const QUrl	nullUrl("http://localhost:8080/null");

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

namespace {

void compare(QString const& a, QString const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual) + ":" + a.toStdString()
			+ " file " + std::string(file) + ":" + b.toStdString()
			+ " line " + QString::number(line).toStdString());
	}
}

void compare(qint32 const& a, qint32 const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual) + ":" + QString::number(a).toStdString()
			+ " file " + std::string(file) + ":" + QString::number(b).toStdString()
			+ " line " + QString::number(line).toStdString());
	}
}

void compare(qint64 const& a, qint64 const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual) + ":" + QString::number(a).toStdString()
			+ " file " + std::string(file) + ":" + QString::number(b).toStdString()
			+ " line " + QString::number(line).toStdString());
	}
}

void compare(qreal const& a, qreal const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual) + ":" + QString::number(a).toStdString()
			+ " file " + std::string(file) + ":" + QString::number(b).toStdString()
			+ " line " + QString::number(line).toStdString());
	}
}

void compare(QDateTime const& a, QDateTime const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual) + ":" + a.toString().toStdString()
			+ " file " + std::string(file) + ":" + b.toString().toStdString()
			+ " line " + QString::number(line).toStdString());
	}
}

void compare(char const& a, char const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual) + ":" + QString::number(a).toStdString()
			+ " file " + std::string(file) + ":" + QString::number(b).toStdString()
			+ " line " + QString::number(line).toStdString());
	}
}

void compare(bool const& a, bool const& b, const char * actual, const char * excepted, const char *file, int line) {
	if (a != b) {
		throw std::runtime_error("Excepted " + std::string(excepted)
			+ ", actual " + std::string(actual) + ":" + QString::number(a).toStdString()
			+ " file " + std::string(file) + ":" + QString::number(b).toStdString()
			+ " line " + QString::number(line).toStdString());
	}
}

}

#define COMPARE(actual, expected) \
    compare(actual, expected, #actual, #expected, __FILE__, __LINE__);

#define TEST_START 		TestCounter::instance().inc();
#define TEST_END		TestCounter::instance().dec();
#define WAIT_FOR_TEST	TestCounter::instance().hasMoreTests()

namespace {
	QString generateString(long length) {
        QString excepted;

        if (length < 1025) {
			for (int i = 0; i < 16; i++) {
			  excepted
				  .append(QString::number(i / 10))
				  .append(QString::number(i % 10))
				  .append(" 456789012345678901234567890123456789012345678901234567890123\n");
			}
        } else {
			for (int i = 0; i < 16 * 64; i++) {
			  excepted
				  .append(QString::number(i / 100))
				  .append(QString::number(i / 10 % 10))
				  .append(QString::number(i % 10))
				  .append(" 56789012345678901234567890123456789012345678901234567890123\n");
			}
        }

        excepted.truncate(length);

        return excepted;
	}

	void compareFixedList(QHessian::QHessianReturnParser& parser, int realSize, bool untyped) {
		using namespace QHessian::out;

		qint32 collectionSize;

		if (untyped) {
			parser >> BeginCollection(collectionSize);
		} else {
			parser >> BeginCollection("", "[string", collectionSize);
		}

		COMPARE(collectionSize, realSize)

		for (int i=0; i<collectionSize; ++i) {
			QString value;
			parser >> String(value);

			COMPARE(value, QString::number(i+1));
		}

		parser >> EndCollection();
	}
}

#define EXCEPT_TRUE \
		using namespace QHessian::out; \
		bool success; \
        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender(); \
        parser >> Boolean(success); \
        COMPARE(success, true); \
        parser.deleteLater(); \
		TEST_END

#endif /* QTESTHESSIAN_H_ */
