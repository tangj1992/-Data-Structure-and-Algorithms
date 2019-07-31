#ifndef SINGLELIST_ARRAYSTACK_H
#define SINGLELIST_ARRAYSTACK_H

#include <iostream>
using namespace std;
/**
 * 顺序栈
 */
 class ArrayStack{
 private:
     /**
      * 存储数组
      */
     int* items;
     /**
      * 当前元素个数
      */
     unsigned int size;
     /**
      * 栈容量
      */
     unsigned int capacity;

 public:
     explicit ArrayStack(unsigned int capacity);
     ~ArrayStack();
     bool push(int value);
     int pop();
     unsigned int getSize();

 private:
     ArrayStack& operator= (const ArrayStack& source);
 };
 void testArrayStack();

#endif //SINGLELIST_ARRAYSTACK_H
