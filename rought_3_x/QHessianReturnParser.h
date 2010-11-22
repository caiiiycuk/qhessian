/*
 * ReplyWathcer.h
 *
 *  Created on: 25.07.2010
 *      Author: caiiiycuk
 */

#ifndef QHESSIANRETURNPARSER_H_
#define QHESSIANRETURNPARSER_H_

#include <QtCore>
#include <QNetworkReply>
#include "QHessianTypes.h"

#include <stdexcept>

namespace QHessian {

class QHessianReturnParser: public QObject {
	Q_OBJECT
protected:
	QNetworkReply* reply;

	QList<IProperty*> properties;

	char* replyArray;
	int   replyOffset;
	int   replySize;

	bool errorState;
	bool lastReadWasNull;

	//
	// Except reads from input stream and trhow exception if not equals
	//
    int  read();
	char readChar();

	void expect(int expectedTag, int actualTag, const QString& details);
	void expect(int expectedTag, const QString& details);
	void expect(int expectedTag);

	void expectString(const QString&);
	void expectStdString(const std::string&);

    //tags reader
    void readNext(IProperty& properties);
    void readFault();

    // Reads boolean
    void readBool(bool& value);

    // Reads 32-bit integer.
    void readInt(qint32& value);

    // Reads 64-bit integer.
    void readLong(qint64& value);

    // Reads double.
	void readDouble(qreal& value);

    // Reads UTF-8 encoded string, and appends to value.
    void readString(QString& string);
    void readString(std::string& value);

    // reads bytes chunk for binary
    void readByteChunk(std::string& bytes);
    void readBytes(QString& bytes);

    // collections
    void readCollection(out::BeginCollection& collection);

    // maps
    void readMap(out::BeginMap& map);


	//
	// Peek - dont move a read pointer
	//
    int  peek();

    //
    // check is char c equals to next char in array, and if equals, read it
    //
    bool peek(char c);

    Q_DISABLE_COPY(QHessianReturnParser);

public:
	QHessianReturnParser(QNetworkReply* reply);
	virtual ~QHessianReturnParser();

	//
	// try to parse property
	//
	QHessianReturnParser &operator>>(const IProperty&);

	//
	// return true if server response can be parsed as this
	// property
	//
	bool peek(const IProperty&);

	//
	// return true if null value was arrived from server
	// in last request
	//
	bool wasNull() const;

public slots:
	virtual void finished();
	virtual void error(QNetworkReply::NetworkError code);

signals:
	void error(int code, const QString& message);
	void ready();


};

}

#endif /* QHESSIANRETURNPARSER_H_ */
