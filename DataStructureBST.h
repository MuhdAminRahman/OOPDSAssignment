#ifndef DATA_STRUCTURE_BST_H
#define DATA_STRUCTURE_BST_H

template <typename T>
class DataStructureBST
{ 
public:
    // Binary search tree
    virtual void insert(T data) = 0;
    virtual void Delete(T key) = 0;
    virtual void Root(T target) = 0;
    virtual void inorder() = 0;
    virtual void postorder() = 0;
    virtual void preorder() = 0;
};
#endif