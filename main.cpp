#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <memory>

#include "DoublyLinkedList.cpp"
#include "Queue.cpp"
#include "Stack.cpp"
// #include operation & var
int main()
{

    // DoublyLinkedList<int> list;
    // Stack<int> list2;
    // Queue<int> list3();

    string name = "test";
    map<string, DataStructure<int> *> DSint;
    DSint[name] = new SinglyLinkedList<int>();
    DSint[name]->AddF(5);
    DSint[name]->AddF(3);
    DSint[name]->AddF(2);
    DSint[name]->AddA(3, 6);
    DSint[name]->print();

    DSint[name]->PtrStart();
    DSint[name]->nextNode();
    // SLL test

    // DataStructure<int> *test = new SinglyLinkedList<int>();

    //  test->AddF(5);
    //  test->AddF(4);
    //  test->DelF();
    //  test->print();

    // test->AddE(1);
    // test->AddE(2);
    // test->print();

    // test->DelE();
    // test->print();

    // test->AddA(6, 5);
    // test->print();

    // test->PtrStart();
    // while (!test->isEnd())
    // {
    //     cout << test->getNode() << " ";
    //     test->nextNode();
    // }
    // cout << endl;

    // test->PtrEnd();
    // while (!test->isHead())
    // {
    //     cout << test->getNode() << " ";
    //     test->prevNode();
    // }
    // cout << endl;

    // Queue test
    /*DataStructureSandQ<int> *test = new Queue<int>(5);
    test->push(5);
    test->push(3);
    test->push(2);
    test->push(1);
    test->push(6);

    test->print();

    test->pop();
    test->print();

    cout << "bool test: ";
    bool c = test->isEmpty();
    cout << c << endl;
    bool d = test->isFull();
    cout << d << endl;

    cout << "element test: ";
    int a = test->first();
    cout << a << endl;
    int b = test->last();
    cout << b << endl;*/

    // Stack test
    //  DataStructureSandQ<int>* test = new Stack<int> ();
    //  test->push(5);
    //  test->push(3);
    //  test->push(2);
    //  test->push(1);
    //  test->push(6);
    //  test->push(7);

    // test->print();
    // test->pop();
    // test->print();

    // cout<<  "bool test: ";
    // bool c = test->isEmpty();
    // cout << c << endl;
    // bool d = test->isFull();
    // cout << d << endl;

    // cout<<  "element test: ";
    // int a = test->first();
    // cout << a << endl;
    // int b = test->last();
    // cout << b << endl;

    // DLL test
    // DataStructure<int>* test = new DoublyLinkedList<int> ();
    //  test->AddF(5);
    //  test->AddF(4);
    //  test->DelF();
    //  test->print();

    // test->AddE(1);
    // test->AddE(2);
    // test->print();

    // test->DelE();
    // test->print();

    // test->AddA(6, 5);
    // test->print();

    // test->PtrStart();
    // while (!test->isEnd())
    // {
    //     cout << test->getNode() << " ";
    //     test->nextNode();
    // }
    // cout << endl;

    // test->PtrEnd();
    // while (!test->isHead())
    // {
    //     cout<< test->getNode() << " ";
    //     test->prevNode();
    // }
    // cout << endl;
}

void insert(T data)
{
    root = insertHelper(root, data);
}

Node<T> *insertHelper(Node<T> *r, T data)
{
    if (r == nullptr)
    {
        return new Node<T>(data);
    }

    if (data < r->data)
    {
        r->left = insertHelper(r->left, data);
    }
    else if (data > r->data)
    {
        r->right = insertHelper(r->right, data);
    }

    return r;
}