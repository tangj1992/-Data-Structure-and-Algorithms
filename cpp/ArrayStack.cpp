#include "ArrayStack.h"

ArrayStack::ArrayStack(unsigned int capacity) {
    this->capacity = capacity;
    this->items = new int[capacity];
    this->size = 0;
}
ArrayStack::~ArrayStack() {
    delete[] items;
}
ArrayStack& ArrayStack::operator= (const ArrayStack& source){
    return *this;
}
bool ArrayStack::push(int value) {
    if (size == capacity){
        return false;
    }
    items[size++] = value;

    return true;
}

int ArrayStack::pop() {
    if (size == 0){
        return -1;
    }
    return items[--size];
}
unsigned int ArrayStack::getSize(){
    return size;
}


void testArrayStack(){
    ArrayStack arrayStack(10);
    for (int i = 0; i < 10; ++i) {
        arrayStack.push(i);
    }

    if (arrayStack.getSize() == 0){
        cout << "stack is empty" << endl;
    }else {
        cout << "stack:[" ;

        while (arrayStack.getSize() > 0) {
            cout << arrayStack.pop();
            if (arrayStack.getSize() > 0){
                cout << ",";
            }
        }

        cout << "]" << endl;
    }

}