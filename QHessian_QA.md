# QHessian Quality assurance #

Each QHessian implementation must pass these tests:

Primitive types (Group 1):
  * read/write raw binary data
  * read/write boolean
  * read/write 64-bit millisecond date
  * read/write 64-bit double
  * read/write 32-bit int
  * read/write 64-bit long
  * read/write null
  * read/write UTF8-encoded string

Recursive types (Group 2):
  * read/write lists and arrays
  * read/write maps and dictionaries
  * read/write objects
  * read/write refs for shared and circular object references.

Hessian 2.0 addtitional tests (Group 3):
  * read/write object/list reference maps
  * read/write class definition reference maps
  * read/write type (class name) reference maps

## Implementation ##

See [JettyTestServer](JettyTestServer.md) implementation of these tests