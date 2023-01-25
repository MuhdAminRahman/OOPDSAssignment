#include "Queue.h"

template <typename T>
void Queue<T>::push(T element)
{
    if (size == capacity)// check if the queue is full
    {
        throw overflow_error("Queue is full");// throw an exception if full
    }
    list.AddE(element);// add the element to the end of the list
    size++;// increment the size of the queue
}

template <typename T>
void Queue<T>::pop()
{
    if (isEmpty())// check if the queue is empty
    {
        throw underflow_error("Queue is empty");// throw an exception if empty
    }
    list.DelF();// delete the first element of the list
    size--;// decrement the size of the queue
}

template <typename T>
T Queue<T>::first()
{
    T firstelement;// check if the queue is empty
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");// throw an exception if empty
    }
    list.PtrStart();// set the pointer to the first element
    return list.getNode();// return the first element
}
template <typename T>
T Queue<T>::last()
{
    T lastelement;
    if (isEmpty())// check if the queue is empty
    {
        throw underflow_error("Queue is empty");// throw an exception if empty
    }
    list.PtrEnd();// set the pointer to the last element
    return list.getNode();// return the last element
}

template <typename T>
bool Queue<T>::isFull()
{
    return size == capacity;// check if the queue is full
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return size == 0;// check if the queue is empty
}

template <typename T>
bool Queue<T>::search(T element)
{
    if (isEmpty())// check if the queue is empty
    {
        throw underflow_error("Queue is empty");// throw an exception if empty
    }
    return list.search(element);// call the search method on the list
}

template <typename T>
void Queue<T>::sort()
{
    if (isEmpty())// check if the queue is empty
    {
        throw underflow_error("Queue is empty");// throw an exception if empty
    }
    list.sort();// call the sort method on the list
}

template <typename T>
void Queue<T>::print()
{
    if (isEmpty())// check if the queue is empty
    {
        throw underflow_error("Queue is empty");// throw an exception if empty
    }
    list.print();// call the print method on the list
}