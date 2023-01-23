#ifndef DATA_STRUCTURE_S_AND_Q_H
#define DATA_STRUCTURE_S_AND_Q_H

template <typename T>
class DataStructureSandQ
{ 
public:
    //general functions
    virtual bool search(T k)=0;
    virtual void sort()=0;
    virtual void print()=0;

    //Stack and Queue functions
    virtual void push(T k)=0;
    virtual void pop()=0;
    virtual bool isFull()=0;
    virtual bool isEmpty()=0;
    virtual T first()=0;
    virtual T last()=0;
};
#endif