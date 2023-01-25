#include "BinarySearch.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
    root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* r){
    root = r;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    deleteTree(root);
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRoot() {
        return root;
}

template <typename T>
void BinarySearchTree<T>::Rootpath(Node<T>* r, int target, vector<int>& path){
    if (!r) return;
    path.push_back(r->data);
    if (r->data == target) {
        cout << "root of " << r->data << " is "<< endl;
        for (auto i : path) cout << i << " > " ;
    cout << "\b\b " << endl;
        return;
    }
    Rootpath(r->left, target, path);
    if (!path.empty() && path.back() == target) return;
    Rootpath(r->right, target, path);
    if (!path.empty() && path.back() == target) return;
    path.pop_back();
}

template <typename T>
void BinarySearchTree<T>::Root(T target){
    vector<int> path;
    Rootpath(getRoot(), target, path);
}

template <typename T>
void BinarySearchTree<T>::setRoot(Node<T>* r) {
    root = r;
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* r){
    if (r == nullptr) return;
    deleteTree(r->left);
    deleteTree(r->right);
    delete r;
}


template <typename T>
void BinarySearchTree<T>::insert(T data){
    root = insertHelper(root, data);
}


template <typename T>
Node<T>* BinarySearchTree<T>::insertHelper(Node<T>* r, T data) {
        if (r == nullptr) {
            return new Node<T>(data);   
        }

        if (data < r->data) {
            r->left = insertHelper(r->left, data);
        } else if (data > r->data) {
            r->right = insertHelper(r->right, data);
        }

        return r;
    }


template <typename T>
void BinarySearchTree<T>::rec_inorder(Node<T>* ptr){
    if (ptr == nullptr) return;
    rec_inorder(ptr->left);
    cout << ptr->data << ":";
    rec_inorder(ptr->right);
}

template <typename T>
void BinarySearchTree<T>::inorder(){
    cout << "\nInorder traversal:" << endl;
    rec_inorder(root);
    cout << "\b " << endl;
    cout << endl;
}

template <typename T>
void BinarySearchTree<T>::rec_postorder(Node<T>* ptr){
    if (ptr == nullptr) return;
    rec_postorder(ptr->left);
    rec_postorder(ptr->right);
    cout << ptr->data << ":";
}

template <typename T>
void BinarySearchTree<T>::postorder(){
    cout << "\nPostorder traversal:" << endl;
    rec_postorder(root);
    cout << "\b " << endl;
    cout << endl;
}

template <typename T>
void BinarySearchTree<T>::rec_preorder(Node<T>* ptr){
    if (ptr == nullptr) return;
    cout<<ptr->data<<":";
    rec_preorder(ptr->left);
    rec_preorder(ptr->right);
}

template <typename T>
void BinarySearchTree<T>::preorder(){
    cout << "\nPreorder traversal:" << endl;
    rec_preorder(root);
    cout << "\b " << endl;
    cout << endl;
}


template <typename T>
void BinarySearchTree<T>::Delete(T key){
    root = deleteNodeHelper(root, key);
}

template <typename T>
Node<T>* BinarySearchTree<T>::deleteNodeHelper(Node<T>* r, T key){
    if (r == nullptr) return r;

        if (key < r->data) {
            r->left = deleteNodeHelper(r->left, key);
        } 
        else 
            if (key > r->data) 
            {
                r->right = deleteNodeHelper(r->right, key);
            } 
            else 
            {
                if (r->left == nullptr) 
                {
                    Node<T>* temp = r->right;
                    delete r;
                    return temp;
                } 
                else 
                if (r->right == nullptr) 
                {
                    Node<T>* temp = r->left;
                    delete r;
                    return temp;
                }
                Node<T>* temp = minValueNode(r->right);
                r->data = temp->data;
                r->right = deleteNodeHelper(r->right, temp->data);
        }
        return r;
}

template <typename T>
Node<T>* BinarySearchTree<T>::minValueNode(Node<T>* r) {
    Node<T>* current = r;
        while (current->left != nullptr)
            current = current->left;
        return current;
}

