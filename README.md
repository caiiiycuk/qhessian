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

## Snippets
  * [Q.1](README.md#q1) How to call void method()
  * [Q.2](README.md#q2) How to read **Null**
  * [Q.3](README.md#q3) How to read **Boolean**
  * [Q.4](README.md#q4) How to read **Integer**
  * [Q.5](README.md#q5) How to read **Long**
  * [Q.6](README.md#q6) How to read **Double**
  * [Q.7](README.md#q7) How to read **Date**
  * [Q.8](README.md#q8) How to read **String**
  * [Q.9](README.md#q9) How to read **Binary**
  * [Q.10](README.md#q10) How to read **untyped collection**
  * [Q.11](README.md#q11) How to read **typed collection**
  * [Q.12](README.md#q12) How to read **untyped map**
  * [Q.13](README.md#q13) How to read **typed map**
  * [Q.14](README.md#q14) How to read **Object**
  * [Q.15](README.md#q15) How to read **references**
  * [Q.16](README.md#q16) How to read **multi-typed object**
  * [Q.17](README.md#q17) How to write **Null**
  * [Q.18](README.md#q18) How to write **Boolean**
  * [Q.19](README.md#q19) How to write **Integer**
  * [Q.20](README.md#q20) How to write **Long**
  * [Q.21](README.md#q21) How to write **Double**
  * [Q.22](README.md#q22) How to write **Date**
  * [Q.23](README.md#q23) How to write **String**
  * [Q.24](README.md#q24) How to write **Binary**
  * [Q.25](README.md#q25) How to write **untyped collection**
  * [Q.26](README.md#q26) How to write **typed collection** (String`[``]`)
  * [Q.27](README.md#q27) How to write **untyped map**
  * [Q.28](README.md#q28) How to write **typed map** (hashtable)
  * [Q.29](README.md#q29) How to write **Object**
  * [Q.30](README.md#q30) How to write **references**
  * [Q.31](README.md#q31) How to call int method(int, int)

## Q.1
### How to call void method()
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  /**<br>
   * Does nothing.<br>
   */<br>
  public void nullCall();<br>
</code></pre>
</td>
<td>
<pre><code>	void nullCall() {<br>
		QHessian::QHessianMethodCall call("nullCall");<br>
		call.invoke(networkManager, <br>
			serviceUrl, <br>
			this, <br>
			SLOT(replyCall()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyCall() {<br>
	}<br>
};<br>
</code></pre>
</td>
</tr>
</table>

## Q.2
### How to read **Null**
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public String replyNull()<br>
  {<br>
    return null;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyNullCall() {<br>
		QHessian::QHessianMethodCall call("replyNull");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyNull()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyNull() {<br>
        	QString result;<br>
<br>
	        using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
		parser &gt;&gt; String(result); <br>
		parser.wasNull(); // == true<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.3
### How to read **Boolean**
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public Object replyTrue()<br>
  {<br>
    return true;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyTrueCall() {<br>
		QHessian::QHessianMethodCall call("replyTrue");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyTrue()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyTrue() {<br>
        	bool boolean;<br>
<br>
	        using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
		parser &gt;&gt; Boolean(boolean); // true<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.4 ##
### How to read **Integer** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public int replyInt_m0x801()<br>
  {<br>
    return -0x801;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyInt_m0x801Call() {<br>
		QHessian::QHessianMethodCall call("replyInt_m0x801");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyInt_m0x801()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyLong_m0x801() {<br>
        	qint32 int;<br>
<br>
        	using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
	        parser &gt;&gt; Long(int); // -0x801<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.5 ##
### How to read **Long** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public long replyLong_m0x801()<br>
  {<br>
    return -0x801;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyLong_m0x801Call() {<br>
		QHessian::QHessianMethodCall call("replyLong_m0x801");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyLong_m0x801()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyLong_m0x801() {<br>
        	qint64 longInt;<br>
<br>
        	using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
	        parser &gt;&gt; Long(longInt); // -0x801<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.6 ##
### How to read **Double** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public double replyDouble_3_14159()<br>
  {<br>
    return 3.14159;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyDouble_3_14159Call() {<br>
		QHessian::QHessianMethodCall call("replyDouble_3_14159");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyDouble_3_14159()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyDouble_3_14159() {<br>
        	qreal real;<br>
<br>
        	using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
        	parser &gt;&gt; Double(real); // 3.14159<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.7 ##
### How to read **Date** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public Date replyDate_1()<br>
  {<br>
    long time = 894621091000L;<br>
<br>
    return new Date(time);<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyDate_1Call() {<br>
		QHessian::QHessianMethodCall call("replyDate_1");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyDate_1()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyDate_1() {<br>
        	QDateTime date;<br>
<br>
        	using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
        	parser &gt;&gt; DateTime(date); //894621091000LL<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.8 ##
### How to read **String** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  /**<br>
   * return "Hello, World"<br>
   */<br>
  public String hello();<br>
</code></pre>
</td>
<td>
<pre><code>	void helloCall() {<br>
		QHessian::QHessianMethodCall call("hello");<br>
		call.invoke(networkManager, <br>
			serviceUrl, <br>
			this,<br>
			SLOT(replyHelloCall()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyHelloCall() {<br>
		QString hello;<br>
<br>
		using namespace QHessian::out;<br>
<br>
		QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
		parser &gt;&gt; String(hello);<br>
        	parser.deleteLater();<br>
<br>
                // Now hello == "Hello, World"<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.9 ##
### How to read Binary ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public byte[] replyBinary_1()<br>
  {<br>
    return toBinary("0");<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyBinary_1Call() {<br>
		QHessian::QHessianMethodCall call("replyBinary_1");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyBinary_1()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyBinary_1() {<br>
        	QByteArray binary;<br>
<br>
        	using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
        	parser &gt;&gt; Binary(binary);<br>
        	parser.deleteLater();<br>
<br>
        	//now binary contains '0'<br>
<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.10 ##
### How to read **untyped collection** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public List&lt;String&gt; replyUntypedFixedList_8() {<br>
    List&lt;String&gt; list = new ArrayList&lt;String&gt;();<br>
<br>
    list.add("1");<br>
    list.add("2");<br>
    list.add("3");<br>
    list.add("4");<br>
    list.add("5");<br>
    list.add("6");<br>
    list.add("7");<br>
    list.add("8");<br>
<br>
    return list;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyUntypedFixedList_8Call() {<br>
		QHessian::QHessianMethodCall call("replyUntypedFixedList_8");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyUntypedFixedList_8()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyUntypedFixedList_8() {<br>
		using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
<br>
		qint32 collectionSize;<br>
<br>
		parser &gt;&gt; BeginCollection(collectionSize);<br>
<br>
		for (int i=0; i&lt;collectionSize; ++i) {<br>
			QString value;<br>
			parser &gt;&gt; String(value); //1 2 3 4 5 6 7 8<br>
		}<br>
<br>
		parser &gt;&gt; EndCollection();<br>
<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.11 ##
### How to read **typed collection** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public Object replyTypedFixedList_8()<br>
  {<br>
    return new String[] { "1", <br>
	"2", <br>
	"3", <br>
	"4",<br>
	"5", <br>
	"6", <br>
	"7", <br>
	"8" };<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyTypedFixedList_8Call() {<br>
		QHessian::QHessianMethodCall call("replyTypedFixedList_8");<br>
		call.invoke(networkManager,<br>
			urlTest2, <br>
			this, <br>
			SLOT(replyTypedFixedList_8()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyTypedFixedList_8() {<br>
		using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
<br>
		qint32 collectionSize;<br>
		parser &gt;&gt; BeginCollection("", "[string", collectionSize); //[string - type name<br>
<br>
		for (int i=0; i&lt;collectionSize; ++i) {<br>
			QString value;<br>
			parser &gt;&gt; String(value); // 1 2 3 4 5 6 7 8<br>
		}<br>
		parser &gt;&gt; EndCollection();<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.12 ##
### How to read **untyped map** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public Object replyUntypedMap_1()<br>
  {<br>
    HashMap map = new HashMap();<br>
    map.put("a", 0);<br>
    map.put("b", 1);<br>
<br>
    return map;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyUntypedMap_1Call() {<br>
		QHessian::QHessianMethodCall call("replyUntypedMap_1");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyUntypedMap_1()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyUntypedMap_1() {<br>
		using namespace QHessian::out;<br>
<br>
		QString key;<br>
		qint32  value;<br>
		bool	hasMore;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
        	parser &gt;&gt; BeginMap();<br>
		while ((parser &gt;&gt; HasMoreMap(hasMore), hasMore)) {<br>
			parser &gt;&gt; String(key); // a b<br>
			parser &gt;&gt; Integer(value); // 0 1<br>
		}<br>
	    	parser &gt;&gt; EndMap();<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.13 ##
### How to read **typed map** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public Object replyTypedMap_1()<br>
  {<br>
    Map map = new Hashtable();<br>
    map.put("a", 0);<br>
    map.put("b", 1);<br>
<br>
    return map;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyTypedMap_1Call() {<br>
		QHessian::QHessianMethodCall call("replyTypedMap_1");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyTypedMap_1()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyTypedMap_1() {<br>
		using namespace QHessian::out;<br>
<br>
		QString key;<br>
		qint32  value;<br>
		bool	hasMore;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
        	parser &gt;&gt; BeginMap("", "java.util.Hashtable");<br>
		while ((parser &gt;&gt; HasMoreMap(hasMore), hasMore)) {<br>
			parser &gt;&gt; String(key); // a b<br>
			parser &gt;&gt; Integer(value); // 0 1<br>
		}<br>
	    	parser &gt;&gt; EndMap();<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.14 ##
### How to read **Object** ###
Object class:
```
package com.caucho.hessian.test;

public class TestObject implements java.io.Serializable {
  private Integer _value;

  public TestObject(Integer value)
  {
    _value = value;
  }

  public Object getValue()
  {
    return _value;
  }
}
```

<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public Object replyObject_1()<br>
  {<br>
    return new TestObject(0);<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code><br>
	void replyObject_1Call() {<br>
		QHessian::QHessianMethodCall call("replyObject_1");<br>
		call.invoke(networkManager,<br>
			urlTest2, <br>
			this, <br>
			SLOT(replyObject_1()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyObject_1() {<br>
		using namespace QHessian::out;<br>
<br>
		qint32 _value;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
        	parser<br>
        		&gt;&gt; BeginObject("", "com.caucho.hessian.test.TestObject")<br>
        			&gt;&gt; Integer("_value", _value) //_value == 0<br>
        		&gt;&gt; EndObject();<br>
        	parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>



## Q.15 ##
### How to read **references** ###
From hessian docs:
<blockquote>
An integer referring to a previous list, map, or object instance. As each list, map or object is read from the input stream, it is assigned the integer position in the stream, i.e. the first list or map is '0', the next is '1', etc. A later ref can then use the previous object. Writers MAY generate refs. Parsers MUST be able to recognize them.<br>
<br>
ref can refer to incompletely-read items. For example, a circular linked-list will refer to the first link before the entire list has been read.<br>
<br>
A possible implementation would add each map, list, and object to an array as it is read. The ref will return the corresponding value from the array. To support circular structures, the implementation would store the map, list or object immediately, before filling in the contents.<br>
<br>
Each map or list is stored into an array as it is parsed. ref selects one of the stored objects. The first object is numbered '0'.<br>
</blockquote>

Object class:
```
package com.caucho.hessian.test;

import java.io.IOException;
import java.util.*;

/**
 * Cons-cell for testing
 */
public class TestCons implements java.io.Serializable {
  private Object _first;
  private Object _rest;

  public TestCons()
  {
  }

  public TestCons(Object first)
  {
    _first = first;
  }

  public TestCons(Object first, Object rest)
  {
    _first = first;
    _rest = rest;
  }

  public Object getFirst()
  {
    return _first;
  }

  public void setFirst(Object first)
  {
    _first = first;
  }

  public Object getRest()
  {
    return _rest;
  }

  public void setRest(Object rest)
  {
    _rest = rest;
  }

}

```

<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public Object replyObject_3()<br>
  {<br>
    TestCons cons = new TestCons();<br>
<br>
    cons.setFirst("a");<br>
    cons.setRest(cons);<br>
    <br>
    return cons;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void replyObject_3Call(){<br>
		QHessian::QHessianMethodCall call("replyObject_3");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(replyObject_3()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyObject_3(){<br>
		using namespace QHessian::out;<br>
<br>
        	QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
<br>
        	QString first;<br>
        	qint32  ref;<br>
<br>
		parser 	&gt;&gt; BeginObject("", "com.caucho.hessian.test.TestCons");<br>
<br>
		//<br>
		// _first Object is string<br>
		//<br>
		if (parser.peek(Ref("_first", ref))) {			//optional<br>
			throw std::runtime_error("unexcepted ref");	//optional<br>
		}							//optional<br>
		parser	&gt;&gt; String("_first", first); // first == a<br>
<br>
		//<br>
		// _rest if ref to first (0) object<br>
		//<br>
		if (!parser.peek(Ref("_rest", ref))) { //ref == 0<br>
			throw std::runtime_error("must be ref");<br>
		}<br>
		parser	&gt;&gt; EndObject();<br>
<br>
		parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.16 ##
### How to read **multi-typed object** ###

Java classes:
```
package name.caiiiycuk.test;

/* Fruit (root of hierarchy)*/

public class Fruit implements Serializable {

	private static final long serialVersionUID = 6697223799952319341L;
	
	private final float  weight;
	
	public Fruit(float weight) {
		this.weight = weight;
	}
	
	public float getWeight() {
		return weight;
	}
	
}

/* Fruit -> Apple */

enum AppleColor {
	RED,
	GREEN
}

public class Apple extends Fruit {

	private static final long serialVersionUID = 7908387468053290925L;
	

	private final AppleColor color;

	public Apple(float weight, AppleColor color) {
		super(weight);
		this.color = color;
	}
	
	public AppleColor getColor() {
		return color;
	}
	
}

/* Fruit -> Banana */

enum BananaSize {
	HUGE, LITTLE
}

public class Banana extends Fruit {

	private static final long serialVersionUID = 1180374660481214068L;
	
	private final BananaSize bananaSize;
	
	public Banana(float weight, BananaSize bananaSize) {
		super(weight);
		this.bananaSize = bananaSize;
	}
	
	public BananaSize getBananaSize() {
		return bananaSize;
	}

}

/* Fruit -> Apple -> PlasticApple */

public class PlasticApple extends Apple {

	private static final long serialVersionUID = -8613694398769613071L;
	
	public PlasticApple(float weight, AppleColor color) {
		super(weight, color);
	}

}
```

<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>	@Override<br>
	public List&lt;Fruit&gt; getFruits() {<br>
		List&lt;Fruit&gt; fruitPack = new ArrayList&lt;Fruit&gt;();<br>
		<br>
		fruitPack.add(new Apple(1.0f, AppleColor.RED));<br>
		fruitPack.add(new Apple(2.0f, AppleColor.GREEN));<br>
		fruitPack.add(new Banana(5.0f, BananaSize.HUGE));<br>
		fruitPack.add(new Banana(2.5f, BananaSize.LITTLE));<br>
		fruitPack.add(new PlasticApple(0.2f, AppleColor.GREEN));<br>
		fruitPack.add(new PlasticApple(0.2f, AppleColor.RED));<br>
		<br>
		return fruitPack;<br>
	}<br>
</code></pre>
</td>
<td>
<pre><code>	void fruitCall() {<br>
		QHessian::QHessianMethodCall call("getFruits");<br>
		call.invoke(networkManager, <br>
			fruitUrl, <br>
			this, <br>
			SLOT(replyFruit()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replyFruit() {<br>
		qint32 fruitCount;<br>
<br>
		using namespace QHessian::out;<br>
<br>
		QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
<br>
		parser &gt;&gt; BeginCollection(fruitCount);<br>
<br>
		qint32 objectReaded = 0;<br>
<br>
		for (int i=0; i&lt;fruitCount; i++) {<br>
			//<br>
			//  Check for Apple<br>
			//<br>
			if (parser.peek(BeginObject("name.caiiiycuk.test.Apple"))) {<br>
				qreal 	weight;<br>
				QString color;<br>
<br>
				parser<br>
					&gt;&gt; Double("weight", weight)<br>
						//<br>
						// Enum object<br>
						//<br>
						&gt;&gt; BeginObject("color",<br>
							"name.caiiiycuk.test.AppleColor")<br>
						&gt;&gt; String("name", color)<br>
						&gt;&gt; EndObject()<br>
					&gt;&gt; EndObject();<br>
<br>
<br>
				//weight == 1, 2;<br>
				//color == "RED", "GREEN";<br>
				continue;<br>
			}<br>
<br>
			//<br>
			// Check For Banana<br>
			//<br>
			if (parser.peek(BeginObject("name.caiiiycuk.test.Banana"))) {<br>
				qreal 	weight;<br>
				QString bananaSize;<br>
<br>
				parser<br>
					&gt;&gt; Double("weight", weight)<br>
						&gt;&gt; BeginObject("bananaSize",<br>
							"name.caiiiycuk.test.BananaSize")<br>
						&gt;&gt; String("name", bananaSize)<br>
						&gt;&gt; EndObject()<br>
					&gt;&gt; EndObject();<br>
<br>
				//weight == 5, 2.5f<br>
				//bananaSize, == "HUGE", "LITTLE"<br>
				continue;<br>
			}<br>
<br>
			//<br>
			// Check for PlasticApple<br>
			//<br>
			if (parser.peek(BeginObject("name.caiiiycuk.test.PlasticApple"))) {<br>
				qreal 	weight;<br>
				qint32  colorRef;<br>
<br>
				parser<br>
					&gt;&gt; Double("weight", weight)<br>
					//<br>
					// REF to enum 4 == RED, 2 == GREEN <br>
					// (hardcoded on server just for test)<br>
					//<br>
					&gt;&gt; Ref("color", colorRef)<br>
					&gt;&gt; EndObject();<br>
<br>
<br>
				//weight == 0.2f, 0.2f<br>
				//colorRef == 4, 2<br>
				continue;<br>
			}<br>
		}<br>
<br>
		parser &gt;&gt; EndCollection();<br>
		parser.deleteLater();<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.17 ##
### How to write **Null** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argNull(Object value)<br>
  {<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void argNullCall() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argNull");<br>
		call &lt;&lt; Null();<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argNull()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.18 ##
### How to write **Boolean** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argBoolean(Boolean value);<br>
</code></pre>
</td>
<td>
<pre><code>	void argBooleanCall() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argBoolean");<br>
		call &lt;&lt; Boolean(true);<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argBoolean()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.19 ##
### How to write **Integer** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argInt(Integer value);<br>
</code></pre>
</td>
<td>
<pre><code>	void argIntCall() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argInt");<br>
		call &lt;&lt; Integer(3145);<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argInt()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.20 ##
### How to write **Long** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argLong(Long value);<br>
</code></pre>
</td>
<td>
<pre><code>	void argLongCall() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argLong");<br>
		call &lt;&lt; Long(3145);<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argLong()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.21 ##
### How to write **Double** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argDouble(Double value);<br>
</code></pre>
</td>
<td>
<pre><code>	void argLongCall() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argDouble");<br>
		call &lt;&lt; Double(3.145);<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argDouble()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.22 ##
### How to write **Date** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argDate_1(Date value);<br>
</code></pre>
</td>
<td>
<pre><code>	void argDate_1Call() {<br>
		QDateTime date;<br>
<br>
		TEST_START<br>
<br>
		using namespace QHessian::in;<br>
<br>
		date.setMSecsSinceEpoch(894621091000LL);<br>
		QHessian::QHessianMethodCall call("argDate_1");<br>
		call &lt;&lt; DateTime(date);<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argDate_1()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.23 ##
### How to write **String** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argString_31(String value);<br>
</code></pre>
</td>
<td>
<pre><code>	void argString_31Call() {<br>
		TEST_START<br>
<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argString_31");<br>
		call &lt;&lt; String("0123456789012345678901234567890");<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argString_31()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.24 ##
### How to write **Binary** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  public void argBinary_16(byte[] v);<br>
</code></pre>
</td>
<td>
<pre><code>	void argBinary_16Call() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argBinary_16");<br>
		call &lt;&lt; Binary(QString("0123456789012345").toAscii());<br>
		call.invoke(networkManager,<br>
			urlTest2, <br>
			this, <br>
			SLOT(argBinary_16()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.25 ##
### How to write **untyped collection** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>public void argUntypedFixedList_7(List v);<br>
</code></pre>
</td>
<td>
<pre><code>	void argUntypedFixedList_7Call() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argUntypedFixedList_7");<br>
		call &lt;&lt; BeginCollection(7)<br>
				&lt;&lt; String("1")<br>
				&lt;&lt; String("2")<br>
				&lt;&lt; String("3")<br>
				&lt;&lt; String("4")<br>
				&lt;&lt; String("5")<br>
				&lt;&lt; String("6")<br>
				&lt;&lt; String("7")<br>
			 &lt;&lt; EndCollection();<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argUntypedFixedList_7()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.26 ##
### How to write **typed collection** (String`[``]`) ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>public void argTypedFixedList_7(String[] v);<br>
</code></pre>
</td>
<td>
<pre><code>	void argUntypedFixedList_7Call() {<br>
		using namespace QHessian::in;<br>
<br>
		QHessian::QHessianMethodCall call("argTypedFixedList_7");<br>
		call &lt;&lt; BeginCollection("", "[string", 7) //[string is your type<br>
				&lt;&lt; String("1")<br>
				&lt;&lt; String("2")<br>
				&lt;&lt; String("3")<br>
				&lt;&lt; String("4")<br>
				&lt;&lt; String("5")<br>
				&lt;&lt; String("6")<br>
				&lt;&lt; String("7")<br>
			 &lt;&lt; EndCollection();<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argTypedFixedList_7()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>


## Q.27 ##
### How to write **untyped map** ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>public void argUntypedMap_2(Map&lt;Integer,String&gt; v);<br>
</code></pre>
</td>
<td>
<pre><code>	void argUntypedMap_2Call() {<br>
		using namespace QHessian::in;<br>
		QHessian::QHessianMethodCall call("argUntypedMap_2");<br>
		call &lt;&lt; BeginMap()<br>
			&lt;&lt; Integer(0) &lt;&lt; String("a") // key == 0, value == a<br>
			&lt;&lt; Integer(1) &lt;&lt; String("b") // key == 1, value == b<br>
		     &lt;&lt; EndMap();<br>
		call.invoke(networkManager,<br>
			urlTest2, <br>
			this, <br>
			SLOT(argUntypedMap_2()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
<br>
</code></pre>
</td>
</tr>
</table>


## Q.28 ##
### How to write **typed map** (hashtable) ###
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>public void argUntypedMap_2(Hashtable&lt;Integer,String&gt; v);<br>
</code></pre>
</td>
<td>
<pre><code>	void argUntypedMap_2Call() {<br>
		using namespace QHessian::in;<br>
		QHessian::QHessianMethodCall call("argTypedMap_2");<br>
		call &lt;&lt; BeginMap("", "java.util.Hashtable")<br>
			&lt;&lt; Integer(0) &lt;&lt; String("a") // key == 0, value == a<br>
			&lt;&lt; Integer(1) &lt;&lt; String("b") // key == 1, value == b<br>
		     &lt;&lt; EndMap();<br>
		call.invoke(networkManager,<br>
			urlTest2, <br>
			this, <br>
			SLOT(argTypedMap_2()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
<br>
</code></pre>

</td>
</tr>
</table>

## Q.29 ##
### How to write **Object** ###
Object class:
```
package com.caucho.hessian.test;

/**
 * Empty object for short-encoding testing
 */
public class TestObject implements java.io.Serializable {
  private Integer _value;

  public TestObject()
  {
  }

  public TestObject(Object value)
  {
    _value = value;
  }

  public Integer getValue()
  {
    return _value;
  }
}

```

<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>public void argObject_1(TestObject v);<br>
</code></pre>
</td>
<td>
<pre><code>	void argObject_1Call() {<br>
		using namespace QHessian::in;<br>
		QHessian::QHessianMethodCall call("argObject_1");<br>
		call &lt;&lt; BeginObject("com.caucho.hessian.test.TestObject")<br>
			&lt;&lt; Integer("_value", 0)<br>
		     &lt;&lt; EndObject();<br>
		call.invoke(networkManager, <br>
			urlTest2, <br>
			this, <br>
			SLOT(argObject_1()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.30 ##
### How to write **references** ###

From hessian docs:
<blockquote>
An integer referring to a previous list, map, or object instance. As each list, map or object is read from the input stream, it is assigned the integer position in the stream, i.e. the first list or map is '0', the next is '1', etc. A later ref can then use the previous object. Writers MAY generate refs. Parsers MUST be able to recognize them.<br>
<br>
ref can refer to incompletely-read items. For example, a circular linked-list will refer to the first link before the entire list has been read.<br>
<br>
A possible implementation would add each map, list, and object to an array as it is read. The ref will return the corresponding value from the array. To support circular structures, the implementation would store the map, list or object immediately, before filling in the contents.<br>
<br>
Each map or list is stored into an array as it is parsed. ref selects one of the stored objects. The first object is numbered '0'.<br>
</blockquote>

Object class:
```
package com.caucho.hessian.test;

/**
 * Empty object for short-encoding testing
 */
public class TestObject implements java.io.Serializable {
  private Integer _value;

  public TestObject()
  {
  }

  public TestObject(Object value)
  {
    _value = value;
  }

  public Integer getValue()
  {
    return _value;
  }
}
```
<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>public void TestObject(List&lt;TestObject&gt; v);<br>
</code></pre>
</td>
<td>
<pre><code>	void argObject_2aCall() {<br>
		using namespace QHessian::in;<br>
		QHessian::QHessianMethodCall call("argObject_2a");<br>
		// first object (index 0)<br>
		call &lt;&lt; BeginCollection(2) 	<br>
  			 // secong object (first is list) (index 1)<br>
			 &lt;&lt; BeginObject("com.caucho.hessian.test.TestObject") 	<br>
				&lt;&lt; Integer("_value", 0)<br>
			 &lt;&lt; EndObject()			<br>
			 // ref to com.caucho.hessian.test.TestObject	<br>
			 &lt;&lt; Ref(1)			<br>
		 &lt;&lt; EndCollection();<br>
		call.invoke(networkManager,<br>
			urlTest2, <br>
			this, <br>
			SLOT(argObject_2a()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
</code></pre>
</td>
</tr>
</table>

## Q.31 ##
### How to call int method(int, int) ###

<table cellpadding='0' border='1' cellspacing='0'>
<tr>
<td>Java <b>server</b> example</td><td>QHessian <b>client</b> example</td>
</tr>
<tr>
<td valign='top'>
<pre><code>  /**<br>
   * Subtraction<br>
   */<br>
  public int subtract(int a, int b)<br>
  {<br>
    return a - b;<br>
  }<br>
</code></pre>
</td>
<td>
<pre><code>	void subtractCall() {<br>
		QHessian::QHessianMethodCall call("subtract"); // a-b<br>
<br>
		using namespace QHessian::in;<br>
<br>
		call &lt;&lt; Integer(105)  // a<br>
			 &lt;&lt; Integer(100); // b<br>
<br>
		call.invoke(networkManager, <br>
			urlTest1, <br>
			this, <br>
			SLOT(replySubtractCall()), <br>
			SLOT(error(int, const QString&amp;)));<br>
	}<br>
/*...*/<br>
	void replySubtractCall() {<br>
		qint32 result;<br>
<br>
		using namespace QHessian::out;<br>
<br>
		QHessian::QHessianReturnParser&amp; parser = <br>
			*(QHessian::QHessianReturnParser*) QObject::sender();<br>
		parser &gt;&gt; Integer(result);<br>
        	parser.deleteLater();<br>
<br>
		//now result == 5<br>
	}<br>
<br>
</code></pre>
</td>
</tr>
</table>

## Quality assurance ##
See [QHessian Quality assurance](http://code.google.com/p/qhessian/wiki/QHessian_QA) wiki page.

In repo available a standalone test server: qhessian/qhessian-test-server/assembled/qhessian-test-server-jar-with-dependencies.jar. To run this server type in console java -jar qhessian-test-server-jar-with-dependencies.jar.

If server was succesfully started then project qhessian/qhessian-test must pass all test.

## Getting started ##
See [Guide](http://code.google.com/p/qhessian/wiki/Guide), [FAQ](http://code.google.com/p/qhessian/wiki/FAQ) page.

## Implementation compatible with Hessian 3.x && Hessian 4.x ##

Implementation compatiblie with Hessian 3.x && 4.x versions can be found in folder qhessian of QHessian repository.
