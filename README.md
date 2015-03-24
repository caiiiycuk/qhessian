# qhessian
Qt && C++ implementation of the hessian protocol

QHessian is based on Qt Framework. That means that **you need only qt framework to use all features of hessian**. 
No code generation needed to work with qhessian.

Comparsion of c++ implementations:

| Project | Code generation | Libraries |
|:--------|:--------------|:----------|
| [hessianorb project](http://code.google.com/p/hessianorb) | Yes | CURL |
| [hessiancpp project](http://sourceforge.net/projects/hessiancpp/) | No | SSLPP |
| qhessian | No | Qt |

## Preparing a project

* Get a local copy of the qhessian repository with command 
  ```
  git clone clone https://github.com/caiiiycuk/qhessian.git
  ```

* Add include macro into your source file line 
  ```c++
  #include "{$path}/QHessian.h"
  ```

## Using QHessian

To call a remote method you need to:
  1. Create ```QHessianMethodCall``` object
  1. Set the method paramters with operator ```<<```
  1. Invoke method

Example of calling method with signature ```int substract(int a, int b)```:
```c++
{
  using namespace QHessian::in;
  QHessian::QHessianMethodCall call("substract");
  call << Integer(5) << Integer(4);
  call.invoke(networkManager, url, reciver, SLOT(replySubtractCall()), SLOT(error(int, const QString&)));
}
```

Where:
* ```networkManager``` - is instance of QNetworkAccessManager
* ```url``` - url to hessian service
* ```reciver``` - is QObject that receives reply or error 
* ```replyMyMethodCall``` -  will be invoked with server response
* ```error(int, const QString&)``` - will be invoked to process error

To parse server response you need to:
  1. Get an instance of ```QHessian::QHessianReturnParser```
  1. Parse results with operator ```>>```

Example of result parsing:
```c++
void replySubtractCall() {
  qint32 result;

  using namespace QHessian::out;

  QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
  parser >> Integer(result); // 1
  parser.deleteLater();
}
```

### QHessian::QHessianReturnParser ```peek``` method

You should use ```peek``` when you don't know what type or property goes next in response stream. 
For example: service can return untyped object. This object may be a Apple or Banana or anything else. 
To determine type use ```peek``` method:

```c++
	if (parser.peek(BeginObject("Apple"))) {
		//can parse Apple type
	} else if (parser.peek(BeginObject("Banana"))) {
		//can parse Banana type
	}
```

## Properties

QHessian types (or properties) are just wrappers for hessian's object serialization types. 
Properties are divided into two namespaces:
* `QHessian::out` - contain properties that wrap responses
* `QHessian::in` - contain properties that wrap requests

In both namespaces there are properties:
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

## Quality assurance ##
See [QHessian Quality assurance](http://code.google.com/p/qhessian/wiki/QHessian_QA) wiki page.

In repo available a standalone test server: qhessian/qhessian-test-server/assembled/qhessian-test-server-jar-with-dependencies.jar. To run this server type in console java -jar qhessian-test-server-jar-with-dependencies.jar.

If server was succesfully started then project qhessian/qhessian-test must pass all test.

## Getting started ##
See [Guide](http://code.google.com/p/qhessian/wiki/Guide), [FAQ](http://code.google.com/p/qhessian/wiki/FAQ) page.

## Implementation compatible with Hessian 3.x && Hessian 4.x ##

Implementation compatiblie with Hessian 3.x && 4.x versions can be found in folder qhessian of QHessian repository.
