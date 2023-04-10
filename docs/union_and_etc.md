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
Const object can be declared on references. *Const* prevents modification.
```cpp
#include <iostream>
using namespace std;
int main() {
  char c = 'A';
  const char & r = c;
  r = 'B' //error
  r = 'C' //success
  return 0;
}
```
Reference are made to alias variables, such that it can't directly reference a constant.  
```cpp
#include <iostream>
using namespace std;
int main() {
  const int & rci = 100; // success
  int& ri = 100; //error
  return 0;
}
```
However in the case above, in ```const int& rci``` a temporal constant is declared and referenced afterwards.
Because ```int& ri``` is vulnerable to change, which leads to various problems, only const object constants are allowed to be declared as a constants' reference.

```cpp 
#include <iostream>
using namespace std;
int main() {
  char c = 'A';
  const int& rci = c; // success
  int& ri = c; //error
  return 0;
}
```
Likewise the case for referencing const 100, only ```const int& rci = c``` is allowed in the syntax.

### typedef
typedef is used to create aliases for types.
Most used for structures with very long names e.g. MyStructureHasVeryLongNameForIdentity.
Used secondhand for articulating the definition of type.
> "With just the int USER_ID_TYPE, it is difficult to know its contents. However, if we create an alias for USER_ID_TYPE, we could refactor it to be much more verbose ; 
> ```typedef unsigned char* uc_ptr;``` 

For future refactoring it also can be phrased as the following.
```cpp
typedef short ID_TYPE;

ID_TYPE id1 = (ID_TYPE)0;
ID_TYPE id2 = (ID_TYPE)0;
```

## Lists, structure, pointer; other features
### Structure: Bit Fields
If we use bit fields, We could refactor the structures' memory space to to our needs.
e.g. member 'a' takes 3bits, member 'b' takes 4bits.
```cpp
struc Flags
{
  int a : 3;
  int b : 4;
  bool c : 1;
}
```
Bit fields only allow int types, and ```struc Flags``` only take up 8bits == 1byte
If we'd like to add unused bits in between;
```cpp
struc Flags
{
  int a : 3;
  int b : 4;
  int : 5;
  bool c : 1;
}
```
Bit fields can be used for bitwise operation. The following code is on 16-bit color.
```cpp
#include <iostream>
#include <bitset>
using namespace std;
struct Pixel16
{
  unsigned int blue : 5;
  unsigned int green : 6;
  unsigned int red : 5;
};
union Convert16
{
  Pixel16 pixel;
  unsigned short us;
};
int main() {
  unsigned short color = 0x1234;
  Convert16 convert;
  convert.us = color;
  cout << "color = " << bitset<16>(color) << "(" << color << ")" << endl;                              //color = 0001001000110100(4660)
  cout << "red  = " << bitset<16>(convert.pixel.red) << "(" << convert.pixel.red << ")" << endl;       //red  = 0000000000000010(2)
  cout << "green  = " << bitset<16>(convert.pixel.green) << "(" << convert.pixel.green << ")" << endl; //green  = 0000000000010001(17)
  cout << "blue  = " << bitset<16>(convert.pixel.blue) << "(" << convert.pixel.blue << ")" << endl;    //blue  = 0000000000010100(20)
  return 0;
}
```

### Structure:Structure
Defining structure in structure
```cpp
struct A
{
  int i;
  float f;
}

struct B
{
  A a;
  char c;
}

int main() {
  B b;
  b.a.f= 30.0f
}
```
### Multidimensional arrays
```int arr[10][5]``` is similar to ```int arr[50]```
memory for arr[1][0] is allocated after the memory for arr[0][4].
To initialize a 2d array it is normal to use a double for syntax.
```cpp
for (int i = 0; i < 10; ++i)
  for (int j = 0; j < 5; ++j)
    arr[i][j] = 10;
```

### Pointer pointing pointer
```cpp
char c = '1';
char* pc = &c;
char ** ppc = &pc;
```
from the syntax the following is true
- *ppc == pc;
- **ppc = c;


