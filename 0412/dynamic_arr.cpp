#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 8;
const int CAPACITY_INCREMENT = 8;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
    
public:
    DynamicArray() {
        data = new int[INITIAL_CAPACITY];
        size = 0;
        capacity = INITIAL_CAPACITY;
    }
    
    ~DynamicArray() {
        delete[] data;
    }
    
    void add(int value) {
        if (size == capacity) {
            int newCapacity = capacity + CAPACITY_INCREMENT;
            int* newData = new int[newCapacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size++] = value;
    }
    
    int getSize() {
        return size;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            throw "Index out of bounds";
        }
        return data[index];
    }
};

int main() {
    int n;
    cin >> n;
    DynamicArray arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.add(input);
    }
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.get(i) << " ";
    }
    cout << endl;
    return 0;
}
