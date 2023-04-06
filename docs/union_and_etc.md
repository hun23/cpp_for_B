# Union and Others
## Union
A union is a user-defined data type that allows you to store different data types in the same memory location.
```cpp
#include <iostream>

using namespace std;

union MyUnion
{
  int i;
  void* p;
};

int main(int argc, char const *argv[])
{
  MyUnion uni;
  cout << "&uni.i = " << &uni.i << endl;  //&uni.i = 0x5ffe98
  cout << "&uni.p = " << &uni.p << endl;  //&uni.p = 0x5ffe98
  uni.i = 0x12345678;
  cout << hex;
  cout << "uni.i = " << uni.i << endl;  //uni.i = 12345678
  cout << "uni.p = " << uni.p << endl;  //uni.p = 0x12345678
  uni.p = (void*)0x87654321;
  cout << "uni.i = " << uni.i << endl;  //uni.i = 87654321
  cout << "uni.p = " << uni.p << endl;  //uni.p = 0x87654321
  return 0;
}
```
Since all the variables are stored at same memory location, the memory of the union is defined by the largest data type.

## Enumeration
Enumeration (enum) is a user-defined data type that consists of a set of named constant values. Enums are useful for creating sets of related constants that can be used throughout a program.

```cpp
#include <iostream>

using namespace std;

enum {RED, GREEN, BLUE};

struct Color {
  int color;
  // + other members;
};

int main(int argc, char const *argv[])
{
  Color c;
  if (RED == c.color)
  {
    // run code;
  }
  return 0;
}
```
```enum {RED, GREEN, BLUE}``` equals ``` enum {RED = 0, GREEN = 1, BLUE = 2 }```
such that we could configurate enumration bow the following.
``` enum {RED, GREEN, BLUE = 3 } ```
Enumeration is initialized by ```BLUE=3```, such that
``` enum {RED, GREEN = 4, BLUE } ``` equals ``` enum {RED, GREEN = 4, BLUE = 5 } ```

### Enumeration and integers
``` enum {RED, GREEN, BLUE} ``` Will be used for the Following
By default, the underlying type of an enumeration (enum) is int.
> It's different from the conventional integer variables that we've learned. 
1. ```color1 = RED + BLUE``` : enumeration can't be used for operations such as addition. 
2. ```RED = 3``` : other variables aren't allowed to be inserted into enumerations.
> It's still available for the following operations. This is due to the fact that enumeration symbols are considered implicit integers.
1. ```int n = GREEN``` : type conversion of GREEN to int
  - ```int n = GREEN + 2``` : ```n = 3``` is defined
2. ```Color color3 = (Color)2``` : color3 is BLUE
  - ```Color color4 = (Color)50000``` : result is unknown

## Reference
A reference is an alias for an existing variable.
```int& ref = target;```
Pointers, described beforehand, are used to point other variables. However, pointers needs its own memory to store the memory location.
Reference on the otherhand consists only of the name.
```cpp
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int target = 20;
  int& ref = target;
  cout << "ref     = " << ref << endl;     // ref     = 20 
  cout << "target  = " << target << endl;  // target  = 20
  cout << "&ref    = " << &ref << endl;    // &ref    = 0x5ffe94
  cout << "&target = " << &target << endl; // &target = 0x5ffe94
  ref = 100;
  cout << "ref     = " << ref << endl;     // ref     = 100
  cout << "target  = " << target << endl;  // target  = 100
  return 0;
}
```

### Reference configuration
Reference can't be configured to reference other variables.
Thus to make another alias using the same name, the reference has to be innitialized.
```cpp
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  float a = 100.0f; // a = 100.0f
  float b = 12.34f; // a = 100.0f, b = 12.34f
  float& r = a;     // a = 100.0f, b = 12.34f, r = 100.0f
  r = 200.0f;       // a = 200.0f, b = 12.34f, r = 200.0f
  r = b;            // a = 12.34f, b = 12.34f, r = 12.34f 
  r = 56.78f;       // a = 56.78f, b = 12.34f, r = 56.78f
  return 0;
}
```

### Reference and const
