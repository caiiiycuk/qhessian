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

public slots:
	void replyNullCall() {
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
		COMPARE(key, 0)
		COMPARE(value, QString("a"))

		parser >> HasMoreMap(hasMore);
		parser >> Integer(key);
		parser >> String(value);

		COMPARE(hasMore, true)
		COMPARE(key, 1)
		COMPARE(value, QString("b"))

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

	void error(int, const QString& string) {
		throw std::runtime_error("QHessian error: " + string.toStdString());
	}
};

#endif /* QCAUCHOTEST_H_ */
