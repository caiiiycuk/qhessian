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
// Null type
//
	NULL_VALUE,
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
// Wrapper for collections (list, array)
//
	BEGIN_COLLECTION,
	END_COLLECTION,

//
// Wrapper for maps
//
	BEGIN_MAP,
	HAS_MORE_MAP,
	END_MAP,
//
// Objects
//
	BEGIN_OBJECT,
	END_OBJECT,

//
// References
//
	REF
};

class IProperty {
protected:
	bool _null;
public:
	IProperty():_null(false) {};
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

class BeginMapProperty: public IProperty {
protected:
	QString 	name;
	QString		typeName;

public:
	BeginMapProperty(): name(""), typeName("") {
	}

	BeginMapProperty(QString name, QString typeName): name(name), typeName(typeName) {
	}

	BeginMapProperty(const BeginMapProperty& other): name(other.name), typeName(other.typeName) {
	}

	virtual const QString& getTypeName() const {
		return typeName;
	}

	virtual const QString& getName() const {
		return name;
	}

	virtual Type getType() const {
		return BEGIN_MAP;
	}

	virtual IProperty* clone() const {
		return new BeginMapProperty(*this);
	}
};

template <Type T, typename V>
class TypedProperty: public Property<T, V> {
protected:
	QString typeName;

public:
	TypedProperty(V value): Property<T, V>(value), typeName("") {
	}

	TypedProperty(const QString& name, V value): Property<T, V>(name, value), typeName("") {
	}

	TypedProperty(const QString& name, const QString& typeName, V value): Property<T, V>(name, value), typeName(typeName) {
	}

	TypedProperty(const TypedProperty<T, V>& other): Property<T, V>(other), typeName(other.typeName) {
	};

	virtual const QString& getTypeName() const {
		return typeName;
	}

	virtual Property<T, V>* clone() const {
		return new TypedProperty<T, V>(*this);
	}
};

namespace in {

	typedef EmptyProperty<NULL_VALUE> 					Null;

	typedef Property<BOOLEAN, bool> 					Boolean;
	typedef Property<INTEGER, qint32> 					Integer;
	typedef Property<LONG, qint64> 						Long;
	typedef Property<DOUBLE, qreal> 					Double;
	typedef Property<STRING, QString> 					String;
	typedef Property<DATE, QDateTime> 					DateTime;
	typedef Property<BINARY, QByteArray>				Binary;

	typedef TypedProperty<BEGIN_COLLECTION, qint32>		BeginCollection;
	typedef EmptyProperty<END_COLLECTION>				EndCollection;

	typedef BeginMapProperty							BeginMap;
	typedef EmptyProperty<END_MAP>						EndMap;


	typedef Property<BEGIN_OBJECT, std::string> 		BeginObject;
	typedef EmptyProperty<END_OBJECT> 					EndObject;

	typedef Property<REF, qint32> 						Ref;
}

namespace out {

	typedef Property<BOOLEAN, bool&> 					Boolean;
	typedef Property<INTEGER, qint32&> 					Integer;
	typedef Property<LONG, qint64&> 					Long;
	typedef Property<DOUBLE, qreal&> 					Double;
	typedef Property<STRING, QString&> 					String;
	typedef Property<DATE, QDateTime&> 					DateTime;
	typedef Property<BINARY, QByteArray&>					Binary;

	typedef TypedProperty<BEGIN_COLLECTION, qint32&>	BeginCollection;
	typedef EmptyProperty<END_COLLECTION>				EndCollection;

	typedef BeginMapProperty							BeginMap;
	typedef Property<HAS_MORE_MAP, bool&>				HasMoreMap;
	typedef EmptyProperty<END_MAP>						EndMap;

	typedef Property<BEGIN_OBJECT, std::string> 		BeginObject;
	typedef EmptyProperty<END_OBJECT> 					EndObject;

	typedef Property<REF, qint32&> 						Ref;

}

}

#endif /* QHESSIANTYPES_H */
