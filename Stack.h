#ifndef STACK_H
#define STACK_H


#include <iostream>
#include <string>

#include "DataStructureSandQ.h"

using namespace std;
 
#define SIZE 5
// Class
// To represent stack using template by class
// taking class in template
template <class T> 
class Stack : public DataStructureSandQ<T>
{
    // Public access modifier
public:
    // Empty constructor
    Stack();
    void push(T k);
    void pop();
    T first();
    T last();
    bool isFull();
    bool isEmpty();
    bool search(T k);
    void sort();
    void print();
private:
    // Taking data member top
    int top;
 
    // Initialising stack(array) of given size
    T st[SIZE];
    T element;
};
 

 
#endif