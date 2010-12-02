/*
 * QFruitTest.h
 *
 *  Created on: 22.11.2010
 *      Author: caiiiycuk
 */

#ifndef QFRUITTEST_H_
#define QFRUITTEST_H_

#include "QTestHessian.h"

#include <stdexcept>
#include <QtCore>
#include <QtCore/QObject>

class QFruitTest: public QObject {
Q_OBJECT
public:
	QFruitTest() {
		fruitCall();
	}

	void fruitCall() {
		TEST_START
		QHessian::QHessianMethodCall call("getFruits");
		call.invoke(networkManager, fruitUrl, this, SLOT(replyFruit()), SLOT(error(int, const QString&)));
	}

public slots:

	void replyFruit() {
		qint32 fruitCount;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> BeginCollection(fruitCount);

		qint32 objectReaded = 0;

		for (int i=0; i<fruitCount; i++) {
			//
			// Read next fruit
			//
			QString enumType;

			//
			// Apple
			//
			if (parser.peek(BeginObject("name.caiiiycuk.test.Apple"))) {
				qreal 	weight;
				QString color;

				parser
					>> Double("weight", weight)
						//
						// Enum object
						//
						>> BeginObject("color", "name.caiiiycuk.test.AppleColor")
						>> String("name", color)
						>> EndObject()
					>> EndObject();


				COMPARE(weight, qreal(i == 0 ? 1 : 2));
				COMPARE(color, QString(i == 0 ? "RED" : "GREEN"));

				objectReaded++;
				continue;
			}

			//
			// Banana
			//
			if (parser.peek(BeginObject("name.caiiiycuk.test.Banana"))) {
				qreal 	weight;
				QString bananaSize;

				parser
					>> Double("weight", weight)
						>> BeginObject("bananaSize", "name.caiiiycuk.test.BananaSize")
						>> String("name", bananaSize)
						>> EndObject()
					>> EndObject();

				COMPARE(weight, qreal(i == 2 ? 5 : 2.5f));
				COMPARE(bananaSize, QString(i == 2 ? "HUGE" : "LITTLE"));

				objectReaded++;
				continue;
			}

			//
			// name.caiiiycuk.test.PlasticApple
			//
			if (parser.peek(BeginObject("name.caiiiycuk.test.PlasticApple"))) {
				qreal 	weight;
				qint32  colorRef;

				parser
					>> Double("weight", weight)
					//
					// REF to enum 4 == RED, 2 == GREEN (hardcoded on server just for test)
					//
					>> Ref("color", colorRef)
					>> EndObject();


				COMPARE(weight, qreal(i == 4 ? 0.2f : 0.2f));
				COMPARE(colorRef, i == 4 ? 4 : 2);

				objectReaded++;
				continue;
			}
		}

		parser >> EndCollection();
		parser.deleteLater();

		COMPARE(objectReaded, 6)

		TEST_END
	}

	void error(int, const QString& string) {
		throw std::runtime_error(string.toStdString());
	}
};

#endif /* QFRUITTEST_H_ */
