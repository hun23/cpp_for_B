# Dynamic Memory Allocation
In general, allocation of memory means calling data from memory, or declaring the amount of memory to be used on runtime.
e.g.
```cpp
int* p;
int length;
cin >> length;
p = new int[length];
```

## Basic syntax for memory allocation
```cpp
#include <iostream>
using namespace std;

int main() {
	int size;
	cout << "input size of array :";
	cin >> size;
	
	int* arr = new int[size];

	cout << "enter integer\n";
	for (int i = 0; i < size; ++i)\
		cin >> arr[i];
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	float ave = (float)sum / (float)size;
	cout << "sum = " << sum << ", ave = " << ave << "\n";
	delete[] arr;
	return 0;
}
```

First the part where the code allocates new memory
`int* arr= new int[size];`
The part where code frees the allocated memory
`delete[] arr`

- Create : memory allocation type and size of has to be defined. And the computer would return the location of the memory
- Use : from the returned memory location we could use it similar to a pointer
- Delete : after done using the memory has to be freed again

## Operands new, delete, new[], delete[]
Long story short
- new, delete dynamically allocates a single variable
- new[], delete[] dynamically allocates a array
```cpp
int main() {
  int* p = new int;
  *p = 337;
  delete p;
  return 0;
}
```

## Basic rule for allocating memroy
1. Use new, delete & new[], delete[] as pairs
  - as explained before new and new[] are different operands. Thus using new & delete[] or new[] & delete leads to problems.
2. Deleting null pointer is safe
  ```cpp
  char* p = NULL;
  delete p; // or delete[] p;
  ```
  - When a NULL pointer is passed through delete, nothing is actually done. 
3. Freed memory should not be freed again

# Using dynamic memory allocation
## Things only can be done by DMA
The following function returns a reversed string.
```cpp
#include <iostream>
using namespace std;

char* ReverseString(const char* src, int len) {
	char* reverse = new char[len+1];
	for (int i = 0; i < len; ++i)
		reverse[i] = src[len - i - 1];
	reverse[len] = NULL;
	return reverse;
}

int main() {
	char original[] = "FELIXTHECAT";
	char* copy = ReverseString(original, sizeof(original)-1);
	
	cout << original << "\n";
	cout << copy << "\n";
	delete[] copy;
	copy = NULL;
	return 0;
}
```
We could know that the result of the following code is different from the one above. This is because reverse pointer is pointing at a already deleted memory.
> The code still runs because ReverseString function returns a char* pointer. 
```cpp
#include <iostream>
using namespace std;

char* ReverseString(const char* src, int len) {
	char reverse[11];
	for (int i = 0; i < len; ++i)
		reverse[i] = src[len - i - 1];
	return reverse;
}

int main() {
	char original[] = "FELIXTHECAT";
	char* copy = ReverseString(original, sizeof(original)/sizeof(char)-1);
	
	cout << original << "\n";
	cout << copy << "\n";
	return 0;
}
```
