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
}

class QCauchoTest: public QObject {
Q_OBJECT
public:
	QCauchoTest() {
		methodNull();
		replyNull();

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

public slots:
	void replyNullCall() {
		TEST_END
	}

	void replyBinary_0() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 0);

		TEST_END
	}

	void replyBinary_null() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 0); //means null

		TEST_END
	}

	void replyBinary_1() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 1);
        COMPARE(binary.at(0).toAscii(), '0');

		TEST_END
	}

	void replyBinary_15() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 15);
        COMPARE(binary, QString("012345678901234"));

		TEST_END
	}

	void replyBinary_16() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 16);
        COMPARE(binary, QString("0123456789012345"));

		TEST_END
	}

	void replyBinary_1023() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 1023);
        COMPARE(binary, generateString(1023));

		TEST_END
	}

	void replyBinary_1024() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 1024);
        COMPARE(binary, generateString(1024));

		TEST_END
	}

	void replyBinary_65536() {
        QString binary;

        using namespace QHessian::out;

        QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
        parser >> Binary(binary);
        parser.parse();

        COMPARE(binary.length(), 65536);
        COMPARE(binary, generateString(65536));

		TEST_END
	}

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QCAUCHOTEST_H_ */
