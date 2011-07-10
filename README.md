node-objc
=========
### A bridge between [NodeJS][] and the Objective-C Runtime


This module offers a low-level interface to the Objective-C runtime. It is
meant to be as close to a 1:1 mapping of Apple's low-level runtime APIs as
possible.

The low-level APIs are _not nice_ to use. This module is written with the
intention of being used with more high-level libraries. For instance, a module
could be written using this module that exposes an `Array` subclass, but
that is actually backed back an `NSMutableArray` (you would never _want_ to do
that but that should help show the capabilities).

This module also takes care of marshalling JavaScript data types to and from
Objective-C classes. The matchup between types and classes looks like:

    String   <-->  NSString
    Number   <-->  NSNumber
    Date     <-->  NSDate
    Object   <-->  NSDictionary
    Boolean  <-->  BOOL
    Function <-->  Method


Example
-------

``` javascript
var objc = require('objc');

// create an NSString from a JavaScript String
var NSString = objc.objc_getClass('NSString')
  , stringSelector = objc.sel_registerName('stringWithUTF8String:')
  , helloStr   = 'Hello World!'
  , helloNsStr = objc.objc_msgSend(NSString, stringSelector, helloStr)

// log the string with NSLog
obj.NSLog(helloNsStr);
```

[NodeJS]: http://nodejs.org
