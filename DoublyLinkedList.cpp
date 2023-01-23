#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), pointer(nullptr) {}

template <typename T>
void DoublyLinkedList<T>::Delete()
{
    while (head != nullptr)
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
    if (head != nullptr)
    {
        head->prev = new_node;
    }
    head = new_node;
    if (tail == nullptr)
    {
        tail = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::DelF()
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
    if (head == nullptr)
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
    if (tail != nullptr)
    {
        tail->next = new_node;
    }
    tail = new_node;
    if (head == nullptr)
    {
        head = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::DelE()
{
    if (tail == nullptr)
    {
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    delete temp;
    if (tail == nullptr)
    {
        head = nullptr;
    }
}

template <typename T>
void DoublyLinkedList<T>::AddA( T target,T data)
{
    Node *current = head;
    while (current != nullptr && current->data != target)
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
void DoublyLinkedList<T>::PtrStart()
{
    pointer = head;
}

template <typename T>
void DoublyLinkedList<T>::PtrEnd()
{
    pointer = tail;
}

template <typename T>
T DoublyLinkedList<T>::getNode()
{
    if (pointer == nullptr)
    {
        return T();
    }
    return pointer->data;
}

template <typename T>
void DoublyLinkedList<T>::nextNode()
{
    if (pointer != nullptr)
    {
        pointer = pointer->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::prevNode()
{
    if (pointer != nullptr)
    {
        pointer = pointer->prev;
    }
}

template <typename T>
bool DoublyLinkedList<T>::isHead()
{
    return pointer == head;
}

template <typename T>
bool DoublyLinkedList<T>::isEnd()
{
    return pointer == tail;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
template <typename T>
bool DoublyLinkedList<T>::search(T data)
{
    Node* ptr = head;
    while (ptr != nullptr) {
        if (ptr->data == data) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
template <typename T>
void DoublyLinkedList<T>::sort()
{
    if (head == nullptr)
        return;
    bool swapped;
    Node* ptr1 = head;
    Node* lptr = nullptr;
    do
    {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                T temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}