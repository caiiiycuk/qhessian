/*
 * QTokens.h
 *
 *  Created on: 08.10.2010
 *      Author: caiiiycuk
 */

#ifndef QHESSIANTYPES_H
#define QHESSIANTYPES_H

#include <iostream>
#include <QtCore>

namespace QHessian {

enum Type {
//
// Primitive types
//
	BINARY,
	BOOLEAN,
	INTEGER,
	LONG,
	DOUBLE,
	STRING,
	DATE,

//
// Wrapper for collections (list, map, set, array)
//
	COLLECTION,

//
// Tokens
//
	BEGIN_OBJECT,
	END_OBJECT
};

class IProperty {
public:
	IProperty() {};
	virtual ~IProperty() {};

	virtual Type getType() const = 0;

	virtual IProperty* clone() const = 0;
};

template <Type T, typename V>
class Property: public IProperty {
protected:
	QString 	name;
	Type 		type;
	V 			value;

public:
	Property(V value): name(""), type(T), value(value) {};
	Property(const QString& name, V value): name(name), type(T), value(value) {};
	Property(const Property<T, V>& other): name(other.name), type(other.type), value(other.value) {};

	virtual Type getType() const {
		return type;
	}

	virtual V getValue() {
		return value;
	}

	virtual const QString& getName() const {
		return name;
	}

	virtual Property<T, V>* clone() const {
		return new Property<T, V>(*this);
	}

};

template <Type T>
class EmptyProperty: public Property<T, int*> {
public:
	EmptyProperty(): Property<T, int*>("", 0) {};
};

class CollectionWrapper {
protected:
	QList<IProperty* > properties;

public:
	CollectionWrapper &operator>>(const IProperty& property) {
		properties.append(property.clone());
		return *this;
	}

	QList<IProperty*> getProperties() {
		return properties;
	}

};

typedef void (QObject::*CollectionCallback)(CollectionWrapper& collectionWrapper);

class CollectionProperty: public IProperty {
protected:
	QString 			name;
	QObject* 			reciver;
	CollectionCallback  callback;

public:
	CollectionProperty(const QString& name, QObject* reciver, CollectionCallback callback):
		name(name),
		reciver(reciver),
		callback(callback) {
	}

	virtual Type getType() const {
		return COLLECTION;
	}

	virtual IProperty* clone() const {
		return new CollectionProperty(name, reciver, callback);
	}

	virtual const QString& getName() const {
		return name;
	}

	virtual QList<IProperty*> properties() {
		CollectionWrapper wrapper;
		(reciver->*callback)(wrapper);
		return wrapper.getProperties();
	}

};

namespace in {

	typedef Property<BOOLEAN, bool> 					Boolean;
	typedef Property<INTEGER, qint32> 					Integer;
	typedef Property<LONG, qint64> 						Long;
	typedef Property<DOUBLE, qreal> 					Double;
	typedef Property<STRING, QString> 					String;
	typedef Property<DATE, QDateTime> 					DateTime;
	typedef Property<BEGIN_OBJECT, std::string> 		BeginObject;
	typedef EmptyProperty<END_OBJECT> 					EndObject;

}

namespace out {

	typedef Property<BOOLEAN, bool&> 					Boolean;
	typedef Property<INTEGER, qint32&> 					Integer;
	typedef Property<LONG, qint64&> 					Long;
	typedef Property<DOUBLE, qreal&> 					Double;
	typedef Property<STRING, QString&> 					String;
	typedef Property<DATE, QDateTime&> 					DateTime;
	typedef Property<BINARY, QString&>					Binary;
	typedef CollectionProperty 							Collection;
	typedef Property<BEGIN_OBJECT, std::string> 		BeginObject;
	typedef EmptyProperty<END_OBJECT> 					EndObject;

}



//template <typename T, typename V>
//class Property {
//protected:
//	T type;
//	V value;
//
//	friend class QHessianMethodCall;
//	friend class QHessianReturnParser;
//public:
//	Property(T type, V value): type(type), value(value) {};
//	virtual ~Property() {};
//};
//
//
//class Tokenized: public Property<const Token&, const std::string&> {
//public:
//	Tokenized(const Token& type, const std::string& value): Property<const Token&, const std::string&>(type, value) {};
//};
//
//class BeginObject: public Tokenized {
//public:
//	BeginObject(const std::string& objectName): Tokenized(BEGIN_OBJECT, objectName) {};
//};
//
//class EndObject: public Tokenized {
//public:
//	EndObject(): Tokenized(END_OBJECT, "") {};
//};
//
//class Boolean: public Property<std::string, bool&> {
//public:
//	Boolean(bool& value): Property<std::string, bool&>("String", value) {};
////	Boolean(const std::string& type, const bool& value): Property<std::string, bool>(type, value) {};
//};
//
//class Integer: public Property<std::string, qint32&> {
//public:
//	Integer(qint32& value): Property<std::string, qint32&>("Integer", value) {};
////	Integer(const std::string& type, const qint32& value): Property<std::string, qint32>(type, value) {};
//};
//
//class Long: public Property<std::string, qint64&> {
//public:
//	Long(qint64& value): Property<std::string, qint64&>("Long", value) {};
////	Long(const std::string& type, const qint64& value): Property<std::string, qint64>(type, value) {};
//};
//
//class Double: public Property<std::string, qreal&> {
//public:
//	Double(qreal& value): Property<std::string, qreal&>("Double", value) {};
////	Double(const std::string& type, const qreal& value): Property<std::string, qreal>(type, value) {};
//};
//
//class String: public Property<std::string, std::string&> {
//public:
//	String(std::string& value): Property<std::string, std::string&>("String", value) {};
////	String(const std::string& type, const std::string& value): Property<std::string, std::string>(type, value) {};
//};

}

#endif /* QHESSIANTYPES_H */
