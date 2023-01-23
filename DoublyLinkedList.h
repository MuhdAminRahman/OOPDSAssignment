#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "DataStructure.h"

using namespace std;

template <typename T>
class DoublyLinkedList : public DataStructure<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };

    Node *head;
    Node *tail;
    Node *pointer;

public:
    DoublyLinkedList();
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