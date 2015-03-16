# Server specification #

We use standart test implementation form com.caucho.hessian.test:

  * [Test.java](http://code.google.com/p/qhessian/source/browse/qhessian-test-server/src/main/java/com/caucho/hessian/test/Test.java), service link (after server starts) localhost:8080/test1
  * [TestHessian2.java](http://code.google.com/p/qhessian/source/browse/qhessian-test-server/src/main/java/com/caucho/hessian/test/TestHessian2.java), service link (after server starts) localhost:8080/test2

Test includes this tests:

| **Test name** | Description | Parameters | Return value |
|:--------------|:------------|:-----------|:-------------|
| **nullCall** | Does nothing | void | void |
| **hello** | Hello, World | void | string - Hellow, World |
| **subtract** | Subtraction | int a, int b | a-b |
| **echo** | Echos the object to the server | Object | Object |
| **fault** | Throws an application fault | void | void throws IOException |

TestHessian includes this tests:

| **Test name** | Description | Parameters | Return value |
|:--------------|:------------|:-----------|:-------------|
| **methodNull** |trivial null method call | void | void |
| **replyNull** | Result of null | void | void |
| **replyTrue** | Boolean true | void | Object |
| **replyFalse** | Boolean false | void | Object |
| **replyInt\_0** | Result of integer 0 | void | int |
| **replyInt\_1** | Result of integer 1 | void | int |
| **replyInt\_47** | Result of integer 47 | void | int |
| **replyInt\_m16** | Result of integer -16 | void | int |
| **replyInt\_0x30** |  Result of integer 0x30 | void | int |
| **replyInt\_0x7ff** | Result of integer x7ff | void | int |
| **replyInt\_m17** | Result of integer -17 | void | int |
| **replyInt\_m0x800** |  Result of integer -0x800 | void | int |
| **replyInt\_0x800** | Result of integer 0x800 | void | int |
| **replyInt\_0x3ffff** | Result of integer 0x3ffff | void | int |
| **replyInt\_m0x801** | Result of integer -0x801 | void | int |
| **replyInt\_m0x40000** | Result of integer m0x40000 | void | int |
| **replyInt\_0x40000** | Result of integer 0x40000 | void | int |
| **replyInt\_0x7fffffff** | Result of integer 0x7fffffff | void | int |
| **replyInt\_m0x40001** | Result of integer m0x40001 | void | int |
| **replyInt\_m0x80000000** | Result of integer -0x80000000 | void | int |
| **replyLong\_0** | Result of long 0 | void | long |
| **replyLong\_1** | Result of long 1 | void | long |
| **replyLong\_15** | Result of long 15 | void | long |
| **replyLong\_m8** | Result of long -8 | void | long |
| **replyLong\_0x10** | Result of long 0x10 | void | long |
| **replyLong\_0x7ff** | Result of long x7ff | void | long |
| **replyLong\_m9** | Result of long -9 | void | long |
| **replyLong\_m0x800** | Result of long -0x800 | void | long |
| **replyLong\_0x800** | Result of long 0x800 | void | long |
| **replyLong\_0x3ffff** | Result of long 0x3ffff | void | long |
| **replyLong\_m0x801** | Result of long -0x801 | void | long |
| **replyLong\_m0x40000** | Result of long m0x40000 | void | long |
| **replyLong\_0x40000** | Result of long 0x40000 | void | long |
| **replyLong\_0x7fffffff** | Result of long 0x7fffffff | void | long |
| **replyLong\_m0x40001** | Result of long m0x40001 | void | long |
| **replyLong\_m0x80000000** | Result of long -0x80000000 | void | long |
| **replyLong\_0x80000000** | Result of long 0x80000000 | void | long |
| **replyLong\_m0x80000001** | Result of long -0x80000001 | void | long |
| **replyDouble\_0\_0** | Result of double 0.0 | void | double |
| **replyDouble\_1\_0** | Result of double 1.0 | void | double |
| **replyDouble\_2\_0** | Result of double 2.0 | void | double |
| **replyDouble\_127\_0** | Result of double 127.0 | void | double |
| **replyDouble\_m128\_0** | Result of double -128.0 | void | double |
| **replyDouble\_128\_0** | Result of double 128.0 | void | double |
| **replyDouble\_m129\_0** | Result of double -129.0 | void | double |
| **replyDouble\_32767\_0** | Result of double 32767.0 | void | double |
| **replyDouble\_m32768\_0** | Result of double -32768.0 | void | double |
| **replyDouble\_0\_001** | Result of double 0.001 | void | double |
| **replyDouble\_m0\_001** | Result of double -0.001 | void | double |
| **replyDouble\_65\_536** | Result of double 65.536 | void | double |
| **replyDouble\_3\_14159** | Result of double 3.14159 | void | double |
| **replyDate\_0** | date 0 (01-01-1970 00:00 GMT) | void | date |
| **replyDate\_1** | Date by millisecond (05-08-1998 07:51:31.000 GMT) | void | date |
| **replyDate\_2** | Date by minute (05-08-1998 07:51:00.000 GMT) | void | date |
| **replyString\_0** | A zero-length string | void | String |
| **replyString\_null** | A null string | void | String |
| **replyString\_1** |  A one-length string | void | String |
| **replyString\_31** | A 31-length string | void | String |
| **replyString\_32** | A 32-length string | void | String |
| **replyString\_1023** | 1023-length string | void | String |
| **replyString\_1024** | A 1024-length string | void | String |
| **replyString\_65536** | A 65536-length string | void | String |
| **replyBinary\_0** | A zero-length binary | void | Object|
| **replyBinary\_null** | A null string | void | Object|
| **replyBinary\_1** | A one-length string | void | Object|
| **replyBinary\_15** | A 15-length binary | void | Object|
| **replyBinary\_16** | A 16-length binary | void | Object|
| **replyBinary\_1023** | A 1023-length binary | void | Object|
| **replyBinary\_1024** | A 1024-length binary | void | Object|
| **replyBinary\_65536** | A 65536-length binary | void | Object|
| **replyUntypedFixedList\_0** | Zero-length untyped list | void | Object|
| **replyUntypedFixedList\_1** | 1-length untyped list | void | Object|
| **replyUntypedFixedList\_7** | 7-length untyped list | void | Object|
| **replyUntypedFixedList\_8** | 8-length untyped list | void | Object|
| **replyTypedFixedList\_0** | Zero-length typed list (String array) | void | Object|
| **replyTypedFixedList\_1** | 1-length typed list (String array) | void | Object|
| **replyTypedFixedList\_7** | 7-length typed list (String array) | void | Object|
| **replyTypedFixedList\_8** | 8-length typed list (String array) | void | Object|
| **replyUntypedMap\_0** | zero-length untyped map | void | Object|
| **replyUntypedMap\_1** | untyped map with string key | void | Object|
| **replyUntypedMap\_2** | untyped map with int key | void | Object|
| **replyUntypedMap\_3** | untyped map with list key | void | Object|
| **replyTypedMap\_0** | zero-length typed map | void | Object|
| **replyTypedMap\_1** | untyped map with string key | void | Object|
| **replyTypedMap\_2** | typed map with int key | void | Object|
| **replyTypedMap\_3** | typed map with list key | void | Object|
| **replyObject\_0** | Returns a single object | void | Object|
| **replyObject\_16** | Returns 16 object types | void | Object|
| **replyObject\_1** | Simple object with one field | void | Object|
| **replyObject\_2** | Simple two objects with one field | void | Object|
| **replyObject\_2a** | Simple repeated object | void | Object|
| **replyObject\_2b** | Two object with equals | void | Object|
| **replyObject\_3** | Circular object | void | Object|
| **argNull** | Null  | void | Object|
| **argTrue** | Boolean true | void | Object|
| **argFalse** | Boolean false | void | Object|
| **argInt\_0** | Integer 0 | void | Object|
| **argInt\_1** | Integer 1 | void | Object|
| **argInt\_47** | integer 47 | void | Object|
| **argInt\_m16** | Result of integer -16 | void | Object|
| **argInt\_0x30** | Integer 0x30 | void | Object|
| **argInt\_0x7ff** | Result of integer x7ff | void | Object|
| **argInt\_m17** | integer -17 | void | Object|
| **argInt\_m0x800** | Integer -0x800 | void | Object|
| **argInt\_0x800** | Integer 0x800 | void | Object|
| **argInt\_0x3ffff** | Integer 0x3ffff | void | Object|
| **argInt\_m0x801** | Integer -0x801 | void | Object|
| **argInt\_m0x40000** | Integer m0x40000 | void | Object|
| **argInt\_0x40000** | integer 0x40000 | void | Object|
| **argInt\_0x7fffffff** | Integer 0x7fffffff | void | Object|
| **argInt\_m0x40001** | Integer m0x40001 | void | Object|
| **argInt\_m0x80000000** | Result of integer -0x80000000 | void | Object|
| **argLong\_0** | long 0 | void | Object|
| **argLong\_1** | long 1 | void | Object|
| **argLong\_15** | long 15 | void | Object|
| **argLong\_m8** | long -8 | void | Object|
| **argLong\_0x10** | long 0x10 | void | Object|
| **argLong\_0x7ff** | long x7ff | void | Object|
| **argLong\_m9** | long -9 | void | Object|
| **argLong\_m0x800** | long -0x800 | void | Object|
| **argLong\_0x800** | long 0x800 | void | Object|
| **argLong\_0x3ffff** | long 0x3ffff | void | Object|
| **argLong\_m0x801** | long -0x801 | void | Object|
| **argLong\_m0x40000** | long m0x40000 | void | Object|
| **argLong\_0x40000** | long 0x40000 | void | Object|
| **argLong\_0x7fffffff** | long 0x7fffffff | void | Object|
| **argLong\_m0x40001** | long m0x40001 | void | Object|
| **argLong\_m0x80000000** | long -0x80000000 | void | Object|
| **argLong\_0x80000000** | Result of long 0x80000000 | void | Object|
| **argLong\_m0x80000001** | Result of long -0x80000001 | void | Object|
| **argDouble\_0\_0** | double 0.0 | void | Object|
| **argDouble\_1\_0** | double 1.0 | void | Object|
| **argDouble\_2\_0** | double 2.0 | void | Object|
| **argDouble\_127\_0** | double 127.0 | void | Object|
| **argDouble\_m128\_0** |  double -128.0 | void | Object|
| **argDouble\_128\_0** | double 128.0 | void | Object|
| **argDouble\_m129\_0** | double -129.0 | void | Object|
| **argDouble\_32767\_0** | double 32767.0 | void | Object|
| **argDouble\_m32768\_0** | Double -32768.0 | void | Object|
| **argDouble\_0\_001** | double 0.001 | void | Object|
| **argDouble\_m0\_001** | double -0.001 | void | Object|
| **argDouble\_65\_536** | double 65.536 | void | Object|
| **argDouble\_3\_14159** | Result of double 3.14159 | void | Object|
| **argDate\_0** | date 0 (01-01-1970 00:00 GMT) | void | Object|
| **argDate\_1** |  Date by millisecond (05-08-1998 07:51 GMT) | void | Object|
| **argDate\_2** | Date by minute (05-08-1998 07:51 GMT) | void | Object|
| **argString\_0** | A zero-length string | void | Object|
| **argString\_1** | A one-length string | void | Object|
| **argString\_31** | A 31-length string | void | Object|
| **argString\_32** | A 32-length string | void | Object|
| **argString\_1023** | A 1023-length string | void | Object|
| **argString\_1024** | A 1024-length string | void | Object|
| **argString\_65536** | A 65536-length string | void | Object|
| **argBinary\_0** | A zero-length binary | void | Object|
| **argBinary\_1** | A one-length string | void | Object|
| **argBinary\_15** | A 15-length binary | void | Object|
| **argBinary\_16** | A 16-length binary | void | Object|
| **argBinary\_1023** | A 1023-length binary | void | Object|
| **argBinary\_1024** | A 1024-length binary | void | Object|
| **argBinary\_65536** | A 65536-length binary | void | Object|
| **argUntypedFixedList\_0** | Zero-length untyped list | void | Object|
| **argUntypedFixedList\_1** | 1-length untyped list | void | Object|
| **argUntypedFixedList\_7** | 7-length untyped list | void | Object|
| **argUntypedFixedList\_8** | 8-length untyped list | void | Object|
| **argTypedFixedList\_0** | Zero-length typed list (String array) | void | Object|
| **argTypedFixedList\_1** | 1-length typed list (String array) | void | Object|
| **argTypedFixedList\_7** | 7-length typed list (String array) | void | Object|
| **argTypedFixedList\_8** | 8-length typed list (String array) | void | Object|
| **argUntypedMap\_0** | zero-length untyped map | void | Object|
| **argUntypedMap\_1** | untyped map with string key | void | Object|
| **argUntypedMap\_2** | untyped map with int key | void | Object|
| **argUntypedMap\_3** | untyped map with list key | void | Object|
| **argTypedMap\_0** | zero-length typed map | void | Object|
| **argTypedMap\_1** | untyped map with string key | void | Object|
| **argTypedMap\_2** | typed map with int key | void | Object|
| **argTypedMap\_3** | typed map with list key  | void | Object|
| **argObject\_0** | Returns a single object | void | Object|
| **argObject\_16** | Returns 16 object types | void | Object|
| **argObject\_1** | Simple object with one field | void | Object|
| **argObject\_2** | Simple two objects with one field | void | Object|
| **argObject\_2a** | Simple repeated object | void | Object|
| **argObject\_2b** | Two object with equals | void | Object|
| **argObject\_3** | Circular object | void | Object|