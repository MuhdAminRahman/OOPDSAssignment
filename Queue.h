#ifndef QUEUE_H
#define QUEUE_H

#include <stack>
#include <cstddef>

#include "DataStructureSandQ.h"
#include "SinglyLinkedList.cpp"
using namespace std;

template <typename T>
class Queue : public DataStructureSandQ<T>
{
private:
    SinglyLinkedList<T> list;
    size_t size = 0;
    const size_t capacity;

public:
    // Queue();
    Queue(size_t capacity) : capacity(capacity) { size = 0; }
    void push(T k);
    void pop();
    T first();
    T last();
    bool isFull();
    bool isEmpty();
    bool search(T k);
    void sort();
    void print();
};

#endif