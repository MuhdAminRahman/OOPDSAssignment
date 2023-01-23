#include "SinglyLinkedList.h"

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = NULL;
    pointer = NULL;
}

template <typename T>
void SinglyLinkedList<T>::Delete()
{
    Node *temp = head;
    while (temp != NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
}

template <typename T>
void SinglyLinkedList<T>::AddF(T data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

template <typename T>
void SinglyLinkedList<T>::DelF()
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void SinglyLinkedList<T>::AddE(T data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

template <typename T>
void SinglyLinkedList<T>::DelE()
{
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::AddA(T target, T data)
{
    Node *temp = new Node;
    temp->data = data;
    if (head->data == target)
    {
        temp->next = head->next;
        head->next = temp;
    }
    else
    {
        Node *temp2 = head;
        while (temp2->next->data != target)
        {
            temp2 = temp2->next;
        }
        temp->next = temp2->next->next;
        temp2->next->next = temp;
    }
}

template <typename T>
void SinglyLinkedList<T>::PtrStart()
{
    pointer = head;
}

template <typename T>
void SinglyLinkedList<T>::PtrEnd()
{
    pointer = head;
    if (pointer != NULL)
    {
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
    }
}
template <typename T>
T SinglyLinkedList<T>::getNode()
{
    if (pointer != NULL)
    {
        return pointer->data;
    }
    else
    {
        throw "Error: pointer is null";
    }
}

template <typename T>
void SinglyLinkedList<T>::nextNode()
{
    if (pointer != NULL)
    {
        pointer = pointer->next;
    }
    else
    {
        throw "Error: pointer is null";
    }
}

template <typename T>
void SinglyLinkedList<T>::prevNode()
{
    if (pointer != NULL && head != pointer)
    {
        Node *temp = head;
        while (temp->next != pointer)
        {
            temp = temp->next;
        }
        pointer = temp;
    }
    else
    {
        throw "Error: pointer is null or at head";
    }
}

template <typename T>
bool SinglyLinkedList<T>::isHead()
{
    return pointer == head;
}

template <typename T>
bool SinglyLinkedList<T>::isEnd()
{
    return pointer->next == NULL;
}

template <typename T>
void SinglyLinkedList<T>::print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
template <typename T>
void SinglyLinkedList<T>::sort()
{
    // bubble sort algorithm
    bool swapped = true;
    Node *temp = head;
    Node *current = NULL;
    while (swapped)
    {
        swapped = false;
        current = head;
        while (current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                T tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = true;
            }
            current = current->next;
        }
    }
}
template <typename T>
bool SinglyLinkedList<T>::search(T data) {
        Node *current = head;
        while (current != NULL) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
