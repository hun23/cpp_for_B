# Function
In C++, a function is a named block of code that performs a specific task. It is a reusable piece of code that can be called from other parts of a program. C++ functions can take arguments as inputs and can return values as outputs.

Functions in C++ are declared using a function prototype, which specifies the function name, the type of the return value, and the types of any input arguments. The function body contains the actual code that performs the desired task.

By the end of the context the goal is to be able decipher codes like this.
```cpp
// data compression
// pBufIn: input Data
// pBufOut : output Data
// nActualDataLength: data_size(in, out)
// return : success boolean
const bool INVALID_ARGUMENT = false;
const bool NULL = false;

int Compress( const char* pBufIn, char* pBufOut, int& nActualDataLength)
{
  if (NULL == pBufIn || NULL == pBufOut || 0 == nActualDataLength)
    return INVALID_ARGUMENT;
  int OK = 1;
  int nOutputDataLength = 0;
  for (int i = 0; i < nActualDataLength; ++i){
    // data compressing code
  }
  nActualDataLength = nOutputDataLength;
  return OK;
}
```

## Basic usage of functions
```cpp
#include <iostream>
using namespace std;

void PrintMessage(void) {
  cout << "Hi, I'm your first function!!!\n";
}

int main(void)
{
  PrintMessage();
  return 0;
}
```
PrintMessage is declared as a function to print ```"Hi, I'm your first function!!!\n"``` in the terminal.
Although PrintMessage is declared beforehand, program always begins in the main() function.
However, if main() was declared prior to the PrintMessage() the interpreter wouldn't have been able to distinguish what PrintMessage() operand is meaning.

## Function return value;
Once we have left the main scope into a function. We could return with a value.
```cpp
#include <iostream>
using namespace std;

int Three(void) {
  return 3;
}

int main(void)
{
  int ret = Three();
  cout << "ret = " << ret << endl;
  return 0;
}
```

## Using variable in another function scope
```cpp
void sub();
int main()
{
  int a = 3;
  sub();
  return 0;
}
void sub()
{
  ++a; // ERROR
}
```
Error occurs in the 10th line because in c++ we couldn't approach another variable defined within a distinct scope.

# Arguemnt passing
## Arguement passing basics
In C++, arguments can be passed to functions by value, by reference, or by pointer.
To use a function effectively we have to pass on arguments to a function.
Such that the we could get the value of 5! and 7! distinctively using the same function.
```cpp
#include <iostream>
using namespace std;

int Factorial(int n);

int main(void)
{
  int rst;
  rst = Factorial(5);
  cout << "result = " << rst << endl;
  return 0;
}

int Factorial(int n)
{
  int result = 1;
  for (int i = 1; i <= n; ++i)
    result *= i;
  return result;
}
```

## Principal of argument passing
### Rules of argument passing
```cpp
int max(int a, int b)
{
  return a>b? a:b;
}

int main()
{
  int ret = max(3,5);
  return 0;
}
```
This is equivalent to the syntax
```cpp
int max(int a, int b) {
  int a = 3;
  int b = 5;
  int max_value;
  if (a>b)
    max_value = a;
  else
    max_value = b;
  return max_value;
}
```
In c++ these variables(a.k.a parameters) are newly defined inside the function.

### Passing parameters using pointers
[Eucleadian_Algorithms](/docs/euclidian_algorithms.md/)
```cpp

#include <iostream>
using namespace std;

void GCD_LCM(int a, int b, int* pgcd, int* plcm)
{
  int z;
  int x = a;
  int y = b;
  while (true)
  {
    z = x%y;
    if (0==z)
      break;
    x = y;
    y = z;
  }
  *pgcd = y;
  *plcm = a*b/y;
}

int main(void)
{
  int gcd = 0;
  int lcm = 0;
  GCD_LCM(78696, 19332, &gcd, &lcm); //36
  cout << "GCD = " << gcd << endl;
  cout << "LCM = " << lcm << endl;
  return 0;
}
```
- define function parameter as a pointer
- pass the memory location of the variable which you wish to store the result
- within the function store the data in the designated memory location

### Passing parameters using reference
```cpp

#include <iostream>
using namespace std;

void GCD_LCM(int a, int b, int& gcd, int& lcm)
{
  int z;
  int x = a;
  int y = b;
  while (true)
  {
    z = x%y;
    if (0==z)
      break;
    x = y;
    y = z;
  }
  gcd = y;
  lcm = a*b/y;
}

int main(void)
{
  int gcd = 0;
  int lcm = 0;
  GCD_LCM(78696, 19332, gcd, lcm); //36
  cout << "GCD = " << gcd << endl;
  cout << "LCM = " << lcm << endl;
  return 0;
}
```
```int& gcd``` and  ```int& lcm``` doesn't take up another space of memory when initialized. Thus directly refering to ```int gcd``` and ```int lcm```.

### Comparing pointers and reference for passing parameters
Differences between using pointers and reference
- Nullability: A pointer can be null, meaning it does not point to a valid memory address. A reference cannot be null, and must always refer to a valid object.
- Reassignment: A pointer can be reassigned to point to a different memory location, while a reference cannot be reassigned to refer to a different object.

However using pointers could be faulty, and in general using reference to pass parameters is a little more convenient.
Here are some issues a null pointer could cause:
- Segmentation fault: If a null pointer is dereferenced, it can cause a segmentation fault, which is a memory access violation that can crash the program. This can happen if the program tries to read or write data from a memory location that is not allocated, resulting in an operating system signal.
- Memory leaks: If a function returns a null pointer and the caller does not check for the null value, the program may continue to run, but may result in a memory leak. This can happen if the null pointer is used to allocate memory dynamically and the program does not free the memory when it is no longer needed. This can cause the program to run out of memory over time, leading to degraded performance or crashes.
- Undefined behavior: If a function returns a null pointer and the caller uses it without checking for null, it can lead to undefined behavior, which means that the program can behave in an unpredictable way. For example, it may produce incorrect output, crash, or corrupt data.

To avoid such issues we could use the such as of the following.
```cpp
bool CDM_LCD(int a, int b, int* pgcd, int* plcm)
{
  if (NULL == pgcd || NULL == plcm)
    return false;
  // run code
  return true;
}
```

### Passing arrays
Passing arrays are identical to passing pointers.
```cpp
#include <iostream>
using namespace std;

void UsingArray (char arr[]) ;

int main()
{
  char array[20] = "Hello, World!";
  UsingArray(array);                       // In UsingArray() : Hello, World!
  cout << "In main() : " << array << endl; // In main() : Hello, World?
  return 0;
}

void UsingArray(char arr[])
{
  cout << "In UsingArray() : " << arr << endl;
  arr[12] = '?'; 
  return;
}
```
There are few points remember
1. Where the variables are listed, the size of array is not required.
1. The changes made in the function called is conserved outside the scope.
These functionalities stem from the fact that array types are actually pointers.
