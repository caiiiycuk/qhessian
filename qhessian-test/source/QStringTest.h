/*
 * QFruitTest.h
 *
 *  Created on: 22.11.2010
 *      Author: caiiiycuk
 */

#ifndef QSTRINGTEST_H_
#define QSTRINGTEST_H_

#include "QTestHessian.h"

#include <stdexcept>
#include <QtCore>
#include <QtCore/QObject>

class QStringTest: public QObject {
Q_OBJECT
public:
	QStringTest() {
		replyCall();
		argCall();
	}

	void replyCall() {
		TEST_START
		QHessian::QHessianMethodCall call("replyRussianString");
		call.invoke(networkManager,
				stringUrl,
				this,
				SLOT(replyString()),
				SLOT(error(int, const QString&)));
	}

	void argCall() {
		TEST_START
		QHessian::QHessianMethodCall call("argRussianString");
		call << QHessian::in::String("Мама мыла раму. Съешь этих мягких BULOK.");
		call.invoke(networkManager,
				stringUrl,
				this,
				SLOT(argReply()),
				SLOT(error(int, const QString&)));
	}

public slots:

	void replyString() {
		QString reply;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> String(reply);
		parser.deleteLater();

		COMPARE(reply, QString("Мама мыла раму. Съешь этих мягких BULOK."))

		TEST_END
	}

	void argReply() {
		EXCEPT_TRUE
	}

	void error(int, const QString& string) {
		throw std::runtime_error(string.toStdString());
	}
};

#endif /* QSTRINGTEST_H_ */
