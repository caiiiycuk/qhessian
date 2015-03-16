# Introduction #

QHessian is C++ implementation of hessian binary web service protocol. QHessian is fully based on Qt Framework meaning that you'll need **only qt framework to use all features of qhessian**. No codegeneration needed to work with qhessian.

Known c++ implementations of hessian binary web service protocol:
| Project | Codegenration | Libraries |
|:--------|:--------------|:----------|
| [hessianorb project](http://code.google.com/p/hessianorb) | Yes | CURL |
| [hessiancpp project](http://sourceforge.net/projects/hessiancpp/) | No | SSLPP |
| QHessian | No | Qt |

# QHessian Properties #

QHessian properties are just wrappers for hessian's object serialization types. Properties are devided into two groups. QHessian::out contains properties that wraps hessian responses and QHessian::in contains properties that wraps requests.

Available properties:
  * **`Null`**: Null represents a null pointer.
  * **`Boolean`**: Wraps the boolean data type. Has only two possible values: true and false. Use this data type for simple flags that track true/false conditions
  * **`Integer`**: Wraps the int data type. Int is a 32-bit signed two's complement integer. It has a minimum value of -2,147,483,648 and a maximum value of 2,147,483,647 (inclusive).
  * **`Long`**: Wraps the long data type. Long is a 64-bit signed two's complement integer. It has a minimum value of -9,223,372,036,854,775,808 and a maximum value of 9,223,372,036,854,775,807 (inclusive).
  * **`Double`**: Wraps The double (and float) data type. Double is a double-precision 64-bit IEEE 754 floating point.
  * **`String`**: Wraps the UTF8-encoded string.
  * **`DateTime`**: Represents a specific instant in time, with millisecond precision.
  * **`Binary`**: Wraps the binary data. Typically an array of byte.
  * **`BeginCollection`**: This proeprty is a marker for collection start.
  * **`EndCollection`**: This property is a marker for collection end.
  * **`BeginMap`**: This property is a marker for map begin.
  * **`HasMoreMap`**: This property is a marker for available elements in map.
  * **`EndMap`**: This property is a marker for end map.
  * **`BeginObject`**:  This property is a marker for begin object.
  * **`EndObject`**:  This property is a marker for end object.
  * **`Ref`**: This proerpty is a marker for shared and circular object references.

Each propety optionally has 'name', 'value' and 'type' attributes.

# Preparing a project #

  1. Get a local copy of the qhessian repository with command <blockquote>hg clone <a href='https://qhessian.googlecode.com/hg/'>https://qhessian.googlecode.com/hg/</a> qhessian </blockquote>
  1. Insert in your source file line <blockquote>#include "{$path}/QHessian.h"</blockquote>

# Using QHessian #

To call a remote method with qhessian all you need to do is:
  1. Create QHessianMethodCall object
  1. Set the method paramters with operator <<
  1. Invoke call method

Example of calling **int substract(int a, int b)**:

```
{
	using namespace QHessian::in;
	QHessian::QHessianMethodCall call("substract");
	call << Integer(5) << Integer(4);
	call.invoke(networkManager, url, reciver, SLOT(replySubtractCall()), SLOT(error(int, const QString&)));
}
```

Where:
  * **networkManager** is instance of QNetworkAccessManager
  * **url** is URL where service located
  * **reciver** is QObject that receives reply of method or error if occurred. SLOT(replyMyMethodCall()) gets the result of invoking.  SLOT(error(int, const QString&)) - for catching errors.

Parsing of result is also simple:
  1. Get an instance of QHessian::QHessianReturnParser
  1. Parse results with operator >>

Example of result parsing:
```
	void replySubtractCall() {
		qint32 result;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> Integer(result); // 1
		parser.deleteLater();
	}
```

## Using QHessian::QHessianReturnParser **peek** method ##

A peek method is used when you don`t know what type or property may be parsed. For example if service method return untyped object. This object may be a Apple or Banana or anything else. To determine what type excepted use peek method

```
	if (parser.peek(BeginObject("Apple"))) {
		//can parse Apple type
	} else if (parser.peek(BeginObject("Banana"))) {
		//can parse Banana type
	}
```

With parse you can check any property of qhessian.

Also see [FAQ](http://code.google.com/p/qhessian/wiki/FAQ), [Guide (RU)](http://code.google.com/p/qhessian/wiki/Guide_RU)