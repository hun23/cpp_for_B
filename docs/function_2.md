# Overloading
Function overloading allows you to define multiple functions with the same name but with different parameters. When a function is called with a particular set of arguments, the C++ compiler determines which overloaded function to invoke based on the number, types, and order of the arguments. This allows you to define multiple functions with similar functionality but different input parameters.

Function overloading is determined at compile-time and is resolved based on the function's signature, which includes the function's name, parameter types, and const/volatile qualifiers. The return type and access modifiers do not play a role in function overloading.
e.g.
```cpp
int max(int a, int b);
float max(float a, float b);
```

## Overloading rules
```cpp
int VariableReturnType(char c, int i);
double VariableReturnType(char c, double i);

VariableReturnType('A', 100);
VariableReturnType('A', 100.12);
```
The computer calles the function with the closest type of parameter.

### Not to do
If only the return type is different, both signature would be identical thus making it impossible to interpret.
```cpp
int VariableReturnType(char c, int i);
double VariableReturnType(char c, int i);
```
```cpp
void VariableReturnType(int i);
void VariableReturnType(int& i);
```

## Call appropriate function
When passing to an arguement to a function the type doesn't necesserally have to be the perfect match. The following function would work as just as well.
```cpp
void CallMe(int n);
int main() {
  CallMe('A');
  return 0;
}
```
There are internal rules to call the most fitting function;
1. Exact Match
2. Promotion
3. Standard Conversion
4. User-defined Conversions
```cpp
void WhichOne(float f);  // exact match         : 1st to be called
void WhichOne(double d); // Promotion           : 2nd to be called
void WhichOne(int c);    // Standard Conversion : 3rd to be called

int main() {
  WhichOne(3.5f);
  return 0;
}
```

## Default Arguments
Default arguments are arguments passed when we have not declared positional arguments.
```cpp
bool SetFramesPerSec(int fps = 10) { // default fps is set to 10
  return true;
}

int main () {
  SetFramesPerSec();  // set on default fps
  SetFramesPerSec(5); // set on fps 5
  return 0;
}
```
C++ has set some rules on declaring default arguments.
For multimple arguments;
```cpp
void DefaultArgs1(int a, int b = 2, int c = 3); // Correct : default arguments are on the right
void DefaultArgs2(int a, int b, int c = 3); // Correct : default arguments are on the right

// Syntax Error
void DefaultArgs3(int a = 1, int b = 1, int c);  
void DefaultArgs4(int a = 1, int b, int c = 3); 
void DefaultArgs5(int a = 1, int b, int c); 

int main() {
  DefaultArgs1(100, 200); // == DefaultArgs1(a = 100, b = 200, c = 3);
  return 0;
}
```

## Using default arguments and overloading 
Default arguments and function overloading can cause some problems if not used carefully. Here are some common issues:
1. Ambiguity: If you have overloaded functions with default arguments, it can lead to ambiguity in function calls. When calling an overloaded function with no default arguments, the compiler will choose the best match based on the arguments provided. However, if you call a function with fewer arguments than required, the compiler may choose the wrong function.
```cpp
void Ambiguous(int x, int y = 0);
void Ambiguous(int x);

Ambiguous(10); // Which function will be called?
```
> In this case, it is not clear which function will be called because both match the function call. This can lead to compilation errors or unexpected behavior.
2. Unexpected behavior: When using default arguments, it is important to remember that they are filled in at compile-time. This means that if you change the default value, you need to recompile all the code that calls the function with the default argument. If you don't do this, you may get unexpected behavior.

# Recursion
Recursion is a technique where a function calls itself.
## Basic Recursion
```cpp
void RecursiveCall() {
  RecursiveCall(); // calling itself
}

int main () {
  RecursiveCall();
  return 0;
}
```
From the code you could notice the recursion repeating itself. From that, defining the condition to stop the recursion process is would be the essential.
```cpp
#include <stdio.h>
using namespace std;
void WhilePositive(int n)
{
  printf("n = %d\n", n);
  if (n < 0) 
    return;
  WhilePositive(n-1);
  printf("n = %d\n", n);
}

int main()
{
  WhilePositive(10);
  return 0;
}
```
From the output we could observe how the recursion stack and function scope works. 

## Implementing recursion
The following code a function converting decimal to binary using recursion.
```cpp
#include <stdio.h>
using namespace std;
void Convert2Bin (int dec)
{
  if (dec <= 0) return;

  Convert2Bin (dec / 2);
  printf("%d", dec%2);
}

int main()
{
  Convert2Bin(13);
  return 0;
}
```

# Function Pointer
Similar to variables, functions also need memory to be stored within a computer. The interpreter translates the code we've written to machine language and stores it within the memory storage. The function pointers are pointing at the functions memory address.

## Basic usage of function pointer
```cpp
#include <stdio.h>
using namespace std;
void Dog() {
  printf("Woof.\n");
}
void Cat() {
  printf("Meow.\n");
}
int main()
{
  void (*p) ();
  p = &Dog;
  (*p) ();
  p = &Cat;
  (*p) ();
  return 0;
}
```

## declare function pointer through typedef 
typedef makes pointing functions simple. The following two codes works the same.
```cpp
int (*Func1) (int, int);
int (*Func2) (int, int);
void (*Func3) (int);
void (*Func4) (int);
int (*Func5) (int, int);
```

```cpp
typedef int (*FN_TYPE1) (int, int);
typedef void (*FN_TYPE2) (int);

FN_TYPE1 Func1;
FN_TYPE1 Func2;
FN_TYPE2 Func3;
FN_TYPE2 Func4;
FN_TYPE1 Func5;
```

## Implmenting function pointer
```cpp
#include <stdio.h>
using namespace std;

void  ForWindows9x();
void  ForWindowsNT();
bool   IsWindows9x();
void ImportantFunc();

int main()
{
	ImportantFunc();
	return 0;
}

void  ForWindows9x() {
	printf("Function for Windows 9x\n");
}

void  ForWindowsNT() {
	printf("Function for Windows NT\n");
}

bool   IsWindows9x() {
	return false; // return false for testing; means windows is NT
}

void ImportantFunc() {
	if (IsWindows9x()) ForWindows9x();
	else ForWindowsNT();
	// Do Something
	if (IsWindows9x()) ForWindows9x();
	else ForWindowsNT();
}
```
Let's refactor this code through function pointers
```cpp
#include <stdio.h>
using namespace std;

typedef void (*SYSTEM_FUNC) ();

void  ForWindows9x();
void  ForWindowsNT();
bool   IsWindows9x();
void ImportantFunc(SYSTEM_FUNC);

int main()
{
	SYSTEM_FUNC pfn;

	if (IsWindows9x())
		pfn = &ForWindows9x;
	else
		pfn = &ForWindowsNT;
	ImportantFunc(pfn);
	return 0;
}

void  ForWindows9x() {
	printf("Function for Windows 9x\n");
}

void  ForWindowsNT() {
	printf("Function for Windows NT\n");
}

bool   IsWindows9x() {
	return false; // return false for testing; means windows is NT
}

void ImportantFunc(SYSTEM_FUNC pfnSyst) {
	(*pfnSyst) ();
	// Do Something
	(*pfnSyst) ();
}
```