#include "Queue.h"

template <typename T>
void Queue<T>::push(T element)
{
    if (size == capacity)
    {
        throw overflow_error("Queue is full");
    }
    list.AddE(element);
    size++;
}

template <typename T>
void Queue<T>::pop()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    list.DelF();
    size--;
}

template <typename T>
T Queue<T>::first()
{
    T firstelement;
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    list.PtrStart();
    return list.getNode();
}
template <typename T>
T Queue<T>::last()
{
    T lastelement;
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    list.PtrEnd();
    return list.getNode();
}

template <typename T>
bool Queue<T>::isFull()
{
    return size == capacity;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
bool Queue<T>::search(T element)
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    return list.search(element);
}

template <typename T>
void Queue<T>::sort()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    list.sort();
}

template <typename T>
void Queue<T>::print()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    list.print();
}