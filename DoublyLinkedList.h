#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList
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
    ~DoublyLinkedList();

    void AddF(T data); //add element to the front of the list
    void DelF(); //delete element from the front of the list
    void AddE(T data); //add element to the back of the list
    void DelE(); //delete element from the back of the list
    void AddA(T data, T target); //add element after a node(target) in the list
    void PtrStart(); //points to the head of the list
    void PtrEnd(); //points to the tail of the list
    T getNode(); //returns the data of the node pointed by a pointer
    void nextNode(); //moves the pointer to the next node
    void prevNode(); //moves the pointer to the previous node
    bool isHead(); //returns true if pointer is at the head of the list
    bool isEnd(); //returns true if pointer is at the tail of the list
    void Print(); //prints the list
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), pointer(nullptr) {} // default constructer

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() //destructor
{
    while (head != nullptr) //while llist is not empty remove the each node from the head
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::AddF(T data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->prev = nullptr;
    new_node->next = head;
    if (head != nullptr) // if the list is not empty, to prevent from losing the previous nodes the existing head node points to the new node
    {
        head->prev = new_node;
    }
    head = new_node; // the new node replaces the head and also if the list is empty the new node is the head
    if (tail == nullptr)// if the list was empty the new node is also the tail
    {
        tail = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::DelF()
{
    if (head == nullptr) //if the list is empty it breaks from the function
    {
        return;
    }
    Node *temp = head;
    head = head->next; //the next node is the new head
    if (head != nullptr)// if the list is not empty the new head has no previous node
    {
        head->prev = nullptr;
    }
    delete temp;
    if (head == nullptr) // if the list is now empty, the head and tail points to nullptr
    {
        tail = nullptr;
    }
}
template <typename T>
void DoublyLinkedList<T>::AddE(T data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = tail;
    if (tail != nullptr) // if the list is not empty, the tail points at the new node
    {
        tail->next = new_node;
    }
    tail = new_node; // the new node is now the tail
    if (head == nullptr) // if the list is empty, the new node is also the head
    {
        head = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::DelE()
{
    if (tail == nullptr) // if the list is empty, it breaks from the function
    {
        return;
    }
    Node *temp = tail;
    tail = tail->prev; // the node before the tail is now the tail
    if (tail != nullptr) // if the list is not empty, the new tail points to nullptr excluding the previous tail
    {
        tail->next = nullptr;
    }
    delete temp; // deletes the previous tail
    if (tail == nullptr) // if the list is now empty, both the head and tail points to nullptr
    {
        head = nullptr;
    }
}

template <typename T>
void DoublyLinkedList<T>::AddA(T data, T target)
{
    Node *current = head;
    while (current != nullptr && current->data != target) // 
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        return;
    }
    Node *new_node = new Node;
    new_node->data = data;
    new_node->prev = current;
    new_node->next = current->next;
    if (current->next != nullptr)
    {
        current->next->prev = new_node;
    }
    current->next = new_node;
}
template <typename T>
void DoublyLinkedList<T>::PtrStart() // points to the head of the list
{
    pointer = head;
}

template <typename T>
void DoublyLinkedList<T>::PtrEnd() // points to the tail of the list
{
    pointer = tail;
}

template <typename T>
T DoublyLinkedList<T>::getNode() // returns the value/data of the node
{
    if (pointer == nullptr) // if the list is empty returns nothing
    {
        return T();
    }
    return pointer->data;
}

template <typename T>
void DoublyLinkedList<T>::nextNode() // moves the pointer to the next node
{
    if (pointer != nullptr)
    {
        pointer = pointer->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::prevNode() //moves the pointer to the previous node
{
    if (pointer != nullptr)
    {
        pointer = pointer->prev;
    }
}

template <typename T>
bool DoublyLinkedList<T>::isHead() // if the pointer is at the head, returns true
{
    return pointer == head;
}

template <typename T>
bool DoublyLinkedList<T>::isEnd() // if the pointer is at the tail, returns true
{
    return pointer == tail;
}

template <typename T>
void DoublyLinkedList<T>::Print() // prints out the nodes in the list using current as the pointer 
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

#endif
