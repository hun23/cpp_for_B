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