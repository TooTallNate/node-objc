node-objc
=========
### Experiment: A bridge between [NodeJS][] and the Objective-C Runtime

## DON'T USE THIS!! This module is deprecated in favor of [NodObjC][]. Use that instead.

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

// Create an NSMutableArray
var NSMutableArray = objc.objc_getClass('NSMutableArray')
  , alloc = objc.sel_registerName('alloc')
  , init = objc.sel_registerName('init')
  , array = objc.objc_msgSend(objc.objc_msgSend(NSMutableArray, alloc), init)

// Add some JS objects to the NSMutableArray instance
var addObject = objc.sel_registerName('addObject:');
objc.objc_msgSend(array, addObject, "Hello World");
objc.objc_msgSend(array, addObject, { foo: 'bar' });

// log the array's contents with NSLog
objc.NSLog(array);
```

[NodeJS]: http://nodejs.org
[NodObjc]: https://github.com/TooTallNate/NodObjC
