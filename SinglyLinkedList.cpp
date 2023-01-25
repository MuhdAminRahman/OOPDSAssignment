#include "SinglyLinkedList.h"

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = NULL;    // initialize head to null
    pointer = NULL; // initialize pointer to null
}

template <typename T>
void SinglyLinkedList<T>::Delete()
{
    Node *temp = head; // create a temp variable to iterate through the list
    while (temp != NULL)
    {
        head = temp->next; // set head to the next element in the list
        delete temp;       // delete the current element
        temp = head;       // set temp to the new head
    }
}

template <typename T>
void SinglyLinkedList<T>::AddF(T data)
{
    Node *temp = new Node; // create a new node
    temp->data = data;     // set the data of the new node
    temp->next = head;     // set the next of the new node to the current head
    head = temp;           // set the new node as the head
}

template <typename T>
void SinglyLinkedList<T>::DelF()
{
    if (head != NULL) // check if the list is not empty
    {
        Node *temp = head; // create a temp variable to store the current head
        head = head->next; // set the head to the next element in the list
        delete temp;       // delete the current head
    }
}

template <typename T>
void SinglyLinkedList<T>::AddE(T data)
{
    Node *temp = new Node; // create a new node
    temp->data = data;     // set the data of the new node
    temp->next = NULL;     // set the next of the new node to null
    if (head == NULL)      // check if the list is empty
    {
        head = temp; // set the new node as the head
    }
    else
    {
        Node *temp2 = head; // create a temp variable to iterate through the list
        while (temp2->next != NULL)
        {
            temp2 = temp2->next; // set temp2 to the next element in the list
        }
        temp2->next = temp; // set the next of the last element to the new node
    }
}

template <typename T>
void SinglyLinkedList<T>::DelE()
{
    if (head != NULL) // check if the list is not empty
    {
        if (head->next == NULL) // check if the list has only one element
        {
            delete head; // delete the head
            head = NULL; // set the head to null
        }
        else
        {
            Node *temp = head; // create a temp variable to iterate through the list

            while (temp->next->next != NULL)
            {
                temp = temp->next; // set temp to the next element in the list
            }
            delete temp->next; // delete the last element
            temp->next = NULL; // set the next of the new last element to null
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::AddA(T target, T data)
{
    Node *temp = new Node;    // create a new node
    temp->data = data;        // set the data of the new node
    if (head->data == target) // check if the head is the target
    {
        temp->next = head->next; // set the next of the new node to the next of the head
        head->next = temp;       // set the next of the head to the new node
    }
    else
    {
        Node *temp2 = head; // create a temp variable to iterate through the list
        while (temp2->next->data != target)
        {
            temp2 = temp2->next; // set temp2 to the next element in the list
        }
        temp->next = temp2->next->next; // set the next of the new node to the next of the target
        temp2->next->next = temp;       // set the next of the target to the new node
    }
}

template <typename T>
void SinglyLinkedList<T>::PtrStart()
{
    pointer = head; // set the pointer to the head
}

template <typename T>
void SinglyLinkedList<T>::PtrEnd()
{
    pointer = head; // set the pointer to the head
    if (pointer != NULL)
    {
        while (pointer->next != NULL)
        {
            pointer = pointer->next; // set the pointer to the next element in the list
        }
    }
}
template <typename T>
T SinglyLinkedList<T>::getNode()
{
    if (pointer != NULL) // check if the pointer is not null
    {
        return pointer->data; // return the data of the node at the pointer
    }
    else
    {
        throw "Error: pointer is null";
    }
}

template <typename T>
void SinglyLinkedList<T>::nextNode()
{
    if (pointer != NULL) // check if the pointer is not null
    {
        pointer = pointer->next; // set the pointer to the next node
    }
    else
    {
        throw "pointer is null";
    }
}

template <typename T>
void SinglyLinkedList<T>::prevNode()
{
    if (pointer != NULL && head != pointer) // check if the pointer is not null and not at the head
    {
        Node *temp = head; // create a temp variable to iterate through the list
        while (temp->next != pointer)
        {
            temp = temp->next; // set temp to the next element in the list
        }
        pointer = temp; // set the pointer to the previous node
    }
    else
    {
        throw "pointer is null or at head";
    }
}

template <typename T>
bool SinglyLinkedList<T>::isHead()
{
    return pointer == head; // check if the pointer is at the head
}

template <typename T>
bool SinglyLinkedList<T>::isEnd()
{
    return pointer->next == NULL; // check if the pointer is at the end of the list
}

template <typename T>
void SinglyLinkedList<T>::print()
{
    Node *temp = head; // create a temp variable to iterate through the list
    while (temp != NULL)
    {
        cout << temp->data << " "; // print the data of the current element
        temp = temp->next;         // set temp to the next element in the list
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
    while (swapped) // iterates while swapped is true
    {
        swapped = false; // Sets swapped to false for each iteration
        current = head;
        while (current->next != NULL)
        {
            if (current->data > current->next->data) // Compares the current node's data to the next node's data
            {
                T tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = true; // Sets swapped to true to indicate that a swap has been made
            }
            current = current->next; // Moves the pointer to the next node
        }
    }
}
template <typename T>
bool SinglyLinkedList<T>::search(T data)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == data) // check if the current element data is equal to the search data
        {
            return true;// return true if found
        }
        current = current->next;// set current to the next element in the list
    }
    return false;// return false if not found
}
