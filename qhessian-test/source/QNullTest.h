/*
 * QFruitTest.h
 *
 *  Created on: 22.11.2010
 *      Author: caiiiycuk
 */

#ifndef QNULLTEST_H_
#define QNULLTEST_H_

#include "QTestHessian.h"

#include <stdexcept>
#include <QtCore>
#include <QtCore/QObject>

class QNullTest: public QObject {
Q_OBJECT
public:
	QNullTest() {
		nullCall();
	}

	void nullCall() {
		TEST_START
		QHessian::QHessianMethodCall call("readNull");

		using namespace QHessian::in;

		call
			<< BeginObject("", "name.caiiiycuk.test.TypeWithNull")
				<< Boolean("b", true)
				<< Null("bNull")
				<< Integer("i", 0)
				<< Null("iNull")
				<< Long("l", 0l)
				<< Null("lNull")
				<< Double("d", 0.0)
				<< Null("dNull")
				<< DateTime("t", QDateTime())
				<< Null("tNull")
				<< String("s", "ok")
				<< Null("sNull")
				<< Null("listNull")
				<< Null("mapNull")
				<< Null("oNull")
				<< Null("coNull")
			<< EndObject();


		call.invoke(networkManager,
				nullUrl,
				this,
				SLOT(argReply()),
				SLOT(error(int, const QString&)));
	}

public slots:

	void argReply() {
		EXCEPT_TRUE
	}

	void error(int, const QString& string) {
		throw std::runtime_error(string.toStdString());
	}
};

#endif /* QNULLTEST_H_ */
