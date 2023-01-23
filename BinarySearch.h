#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include <vector>
#include "DataStructureBST.h"

using namespace std;

template <typename T>
struct Node
    {
        T data;
        Node* right;
        Node* left;
        //Node* root;
        Node(T data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
        
    };

template <typename T>
class BinarySearchTree : public DataStructureBST<T> 
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    virtual void insert(T data);
    virtual void Delete(T key);
    Node<T>* getRoot();
    virtual void Root(T target);
    virtual void inorder();
    virtual void postorder();
    virtual void preorder();

private:
    Node<T>* root;
    BinarySearchTree(Node<T>* r);
    virtual void setRoot(Node<T>* r);
    Node<T>* insertHelper(Node<T>* r, T data);
    Node<T>* deleteNodeHelper(Node<T>* r, T key);
    virtual void rec_inorder(Node<T>* ptr);
    virtual void deleteTree(Node<T>* r);
    Node<T>* minValueNode(Node<T>* r);
    virtual void rec_postorder(Node<T>* ptr);
    virtual void rec_preorder(Node<T>* ptr);
    virtual void Rootpath(Node<T>* r, int target, vector<int>& path);

};

#endif