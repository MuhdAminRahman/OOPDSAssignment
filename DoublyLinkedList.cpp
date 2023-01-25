#include "DoublyLinkedList.h"

// Constructor for the DoublyLinkedList class.
// Initializes the head, tail, and pointer pointers to nullptr.
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), pointer(nullptr) {}

// Method to delete all the nodes in the list
template <typename T>
void DoublyLinkedList<T>::Delete()
{
    // Iterates through the list starting at the head
    while (head != nullptr)
    {
        // Creates a temporary pointer to the current head
        Node *temp = head;
        // Moves the head pointer to the next node
        head = head->next;
        // Deletes the current node
        delete temp;
    }
}

// Method to add a new node with data to the front of the list
template <typename T>
void DoublyLinkedList<T>::AddF(T data)
{
    // Creates a new node
    Node *new_node = new Node;
    // Sets the new node's data to the passed in data
    new_node->data = data;
    // Sets the new node's prev pointer to nullptr
    new_node->prev = nullptr;
    // Sets the new node's next pointer to the current head
    new_node->next = head;

    // If the head pointer is not nullptr, sets the current head's prev pointer to the new node
    if (head != nullptr)
    {
        head->prev = new_node;
    }
    // Sets the head pointer to the new node
    head = new_node;

    // If the tail pointer is nullptr, sets the tail pointer to the new node
    if (tail == nullptr)
    {
        tail = new_node;
    }
}

// Method to delete the first node in the list
template <typename T>
void DoublyLinkedList<T>::DelF()
{
    // If the head pointer is nullptr, returns
    if (head == nullptr)
    {
        return;
    }

    // Creates a temporary pointer to the current head
    Node *temp = head;
    // Moves the head pointer to the next node
    head = head->next;

    // If the new head pointer is not nullptr, sets the new head's prev pointer to nullptr
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    // Deletes the current node
    delete temp;

    // If the head pointer is nullptr, sets the tail pointer to nullptr
    if (head == nullptr)
    {
        tail = nullptr;
    }
}

// Method to add a new node with data to the end of the list
template <typename T>
void DoublyLinkedList<T>::AddE(T data)
{
    // Creates a new node
    Node *new_node = new Node;
    // Sets the new node's data to the passed in data
    new_node->data = data;
    // Sets the new node's next pointer to nullptr
    new_node->next = nullptr;
    // Sets the new node's prev pointer to the current tail
    new_node->prev = tail;

    // If the tail pointer is not nullptr, sets the current tail's next pointer to the new node
    if (tail != nullptr)
    {
        tail->next = new_node;
    }

    // Sets the tail pointer to the new node
    tail = new_node;

    // If the head pointer is nullptr, sets the head pointer to the new node
    if (head == nullptr)
    {
        head = new_node;
    }
}

// Method to delete the last node in the list
template <typename T>
void DoublyLinkedList<T>::DelE()
{
    // If the tail pointer is nullptr, returns
    if (tail == nullptr)
    {
        return;
    }

    // Creates a temporary pointer to the current tail
    Node *temp = tail;

    // Moves the tail pointer to the previous node
    tail = tail->prev;

    // If the new tail pointer is not nullptr, sets the new tail's next pointer to nullptr
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    // Deletes the current node
    delete temp;

    // If the tail pointer is nullptr, sets the head pointer to nullptr
    if (tail == nullptr)
    {
        head = nullptr;
    }
}

// Method to add a new node with data after a node with target data
template <typename T>
void DoublyLinkedList<T>::AddA(T target, T data)
{
    // Creates a current pointer set to the head of the list
    Node *current = head;

    // Iterates through the list until the current pointer is nullptr or the current node's data matches the target data
    while (current != nullptr && current->data != target)
    {
        current = current->next;
    }

    // If the current pointer is nullptr, the target data was not found and the function returns
    if (current == nullptr)
    {
        return;
    }
    // Creates a new node
    Node *new_node = new Node;
    // Sets the new node's pointers and data to the current node
    new_node->data = data;
    new_node->prev = current;
    new_node->next = current->next;

    // If the current node's next pointer is not nullptr, sets the next node's prev pointer to the new node
    if (current->next != nullptr)
    {
        current->next->prev = new_node;
    }

    // Sets the current node's next pointer to the new node
    current->next = new_node;
}

// Method to set the pointer to the first node in the list
template <typename T>
void DoublyLinkedList<T>::PtrStart()
{
    pointer = head;
}

// Method to set the pointer to the last node in the list
template <typename T>
void DoublyLinkedList<T>::PtrEnd()
{
    pointer = tail;
}

// Method to return the data of the node that the pointer is currently pointing to
template <typename T>
T DoublyLinkedList<T>::getNode()
{
    // If the pointer is nullptr, returns an empty value of type T(int,string,float,double)
    if (pointer == nullptr)
    {
        return T();
    }

    // Returns the data of the node that the pointer is currently pointing to
    return pointer->data;
}

// Method to move the pointer to the next node in the list
template <typename T>
void DoublyLinkedList<T>::nextNode()
{
    // If the pointer is not nullptr, moves the pointer to the next node in the list
    if (pointer != nullptr)
    {
        pointer = pointer->next;
    }
}

// Method to move the pointer to the previous node in the list
template <typename T>
void DoublyLinkedList<T>::prevNode()
{
    // If the pointer is not nullptr, moves the pointer to the previous node in the list
    if (pointer != nullptr)
    {
        pointer = pointer->prev;
    }
}

// Method to check if the pointer is pointing to the first node in the list
template <typename T>
bool DoublyLinkedList<T>::isHead()
{
    return pointer == head;
}

// Method to check if the pointer is pointing to the last node in the list
template <typename T>
bool DoublyLinkedList<T>::isEnd()
{
    return pointer == tail;
}

// Method to print the list
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

// Method to search the list for a node with data equal to the passed in data
template <typename T>
bool DoublyLinkedList<T>::search(T data)
{
    Node *ptr = head;
    // if the pointer is not nullptr, go through each node from the head to the tail until it find a match, if there's no match it returns false
    while (ptr != nullptr)
    {
        //returns true if there's a match
        if (ptr->data == data)
        {
            return true;
        }
        ptr = ptr->next;
    }
    //returns false if there's no match
    return false;
}

// Method to sort the list in ascending order
template <typename T>
void DoublyLinkedList<T>::sort()
{
    // If the head pointer is nullptr, the list is empty and the function returns
    if (head == nullptr)
    {
        return;
    }

    // Variable to keep track of whether any swaps have been made during the iteration
    bool swapped;

    // Pointer to iterate through the list
    Node *ptr1 = head;

    // Pointer to keep track of the last node in the list
    Node *lptr = nullptr;

    // Continues to iterate through the list until no swaps have been made
    do
    {
        // Sets swapped to false for each iteration
        swapped = false;

        ptr1 = head;

        // Iterates through the list until the last node
        while (ptr1->next != lptr)
        {
            // Compares the current node's data to the next node's data
            if (ptr1->data > ptr1->next->data)
            {
                // Swaps the data of the current node and the next node
                T temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                // Sets swapped to true to indicate that a swap has been made
                swapped = true;
            }
            // Moves the pointer to the next node
            ptr1 = ptr1->next;
        }
        // Sets the last node to the current node
        lptr = ptr1;
    } while (swapped);
}