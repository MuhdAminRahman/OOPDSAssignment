#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

template <typename T>
class DataStructure
{ 
public:
    //general functions
    virtual void Delete()=0;
    virtual bool search(T k)=0;
    virtual void sort()=0;
    // virtual void clone();
    virtual void print()=0;

    //DLL funcitons
    virtual void AddF(T data)=0;
    virtual void DelF()=0;
    virtual void AddE(T data)=0;
    virtual void DelE()=0;
    virtual void AddA(T target, T data)=0;
    virtual void PtrStart()=0;
    virtual void PtrEnd()=0;
    virtual T getNode()=0;
    virtual void nextNode()=0;
    virtual void prevNode()=0;
    virtual bool isHead()=0;
    virtual bool isEnd()=0;

};
#endif