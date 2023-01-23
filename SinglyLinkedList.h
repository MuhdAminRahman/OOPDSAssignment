#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include "DataStructure.h"

using namespace std;

template <typename T>
class SinglyLinkedList : public DataStructure<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head;
    Node *pointer;

public:
    SinglyLinkedList();
    void Delete();
    void AddF(T data);
    void DelF();
    void AddE(T data);
    void DelE();
    void AddA(T target, T data);
    void PtrStart();
    void PtrEnd();
    T getNode();
    void nextNode();
    void prevNode();
    bool isHead();
    bool isEnd();
    void sort();
    bool search(T data);
    void print();
};

#endif