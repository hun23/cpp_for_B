# Pointer and lists
It is important to understand the relationship between pointers and lists. Pointers are variables that hold memory addresses, and they are frequently used to manipulate data structures such as lists.

A list is a collection of elements stored in contiguous memory locations. Each element in the list contains a value and a pointer to the next element in the list. The first element in the list is called the head, and the last element is called the tail.

In order to traverse a list, you need to use pointers to keep track of the current element and the next element. You start at the head of the list and follow the pointers to visit each element in turn until you reach the end of the list. You can also use pointers to insert or delete elements from the list.

In addition, pointers can be used to create a dynamic list, where the size of the list can change during the execution of a program. This is because memory for the list can be allocated dynamically, and pointers can be used to link the elements together.

Overall, understanding the relationship between pointers and lists is essential for working with data structures and implementing efficient algorithms that manipulate them.

## Addition and subtraction of pointers
### Addition
Create a pointer pointing at the fifth index of arrays[10]
```
int arrays[10];
int* p = &arrays[5];
```

In order to point at arrays[6]
```
p = &arrays[6];
```
or
```
p++; // p += 1; p = p + 1;
```
Pointer addition is an operation that can be performed on a pointer to access memory locations that are located after the current memory location.

In C++, pointer addition is defined using the overloaded "+" operator for pointers. When performing pointer addition, the compiler adds an integer value to the pointer's memory address, and the resulting memory address is used to access the corresponding memory location.

In the case of a pointer defined as int*, which is a pointer to an integer, the pointer addition operation would add an offset in terms of the size of the data type that the pointer points to (in this case, the size of an int). For example, if we have an int* pointer variable pointing to the memory location 0x1000, and we perform the operation "pointer + 1", the resulting memory address would be 0x1004 (assuming that the size of an int is 4 bytes).

Note that pointer arithmetic is only valid within the bounds of the memory allocated to the pointer. Attempting to access memory locations outside of the allocated memory can result in undefined behavior, such as a segmentation fault.

### Subtraction
```
int array[10];
int* p = &array[5];
p-- // p -= 1; p = p - 1;
```
#### Subtration between pointers
```
short sarray[10];
int* ps1 = &sarray[3];
int* ps2 = &sarray[7];
cout << ps2-ps1 << endl; // 4
```
You could have expected a 8 since 8 would be the difference between the memory address.
However the subtraction between pointers return the value divided by the size of pointer.
Such that the result is equal to the defined space between the two pointers.


