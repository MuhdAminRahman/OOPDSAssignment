#include "BinarySearch.h"

// constructor to initialize the root node to null
template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
    // Initialize the root of the tree to null
    root = nullptr;
}

// constructor to initialize the root node to a given node
template <typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* r){
    // Initialize the root of the tree with the given node
    root = r;
}

// destructor to delete the tree
template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    //Delete the entire tree
    deleteTree(root);
}

// getter method for root
template <typename T>
Node<T>* BinarySearchTree<T>::getRoot() {
    //return the root of the tree
    return root;
}

// prints the path of the root of a target node
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

// helper function to call Rootpath
template <typename T>
void BinarySearchTree<T>::Root(T target){
    vector<int> path;
    Rootpath(getRoot(), target, path);
}

// setter method for root
template <typename T>
void BinarySearchTree<T>::setRoot(Node<T>* r) {
    root = r;
}

// deletes the tree starting from the given node
template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* r){
    if (r == nullptr) return;
    deleteTree(r->left);
    deleteTree(r->right);
    delete r;
}

// inserts a new node with the given data
template <typename T>
void BinarySearchTree<T>::insert(T data){
    root = insertHelper(root, data);
}

// helper function to insert a new node
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


//traverse the tree in in-order 
template <typename T>
void BinarySearchTree<T>::rec_inorder(Node<T>* ptr){
    if (ptr == nullptr) return;
    rec_inorder(ptr->left);
    cout << ptr->data << ":";
    rec_inorder(ptr->right);
}

//function to calls rec_inorder and print the tree in-order
template <typename T>
void BinarySearchTree<T>::inorder(){
    cout << "\nInorder traversal:" << endl;
    rec_inorder(root);
    cout << "\b " << endl;
    cout << endl;
}

//traverse the tree in post-order
template <typename T>
void BinarySearchTree<T>::rec_postorder(Node<T>* ptr){
    if (ptr == nullptr) return;
    rec_postorder(ptr->left);
    rec_postorder(ptr->right);
    cout << ptr->data << ":";
}

//function to calls rec_inorder and print the tree post-order
template <typename T>
void BinarySearchTree<T>::postorder(){
    cout << "\nPostorder traversal:" << endl;
    rec_postorder(root);
    cout << "\b " << endl;
    cout << endl;
}

//traverse the tree in pre-order
template <typename T>
void BinarySearchTree<T>::rec_preorder(Node<T>* ptr){
    if (ptr == nullptr) return;
    cout<<ptr->data<<":";
    rec_preorder(ptr->left);
    rec_preorder(ptr->right);
}

//function to calls rec_inorder and print the tree pre-order
template <typename T>
void BinarySearchTree<T>::preorder(){
    cout << "\nPreorder traversal:" << endl;
    rec_preorder(root);
    cout << "\b " << endl;
    cout << endl;
}

// Delete a node with the given data
template <typename T>
void BinarySearchTree<T>::Delete(T key){
    root = deleteNodeHelper(root, key);
}

// helper function to delete a node
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

//finds the node with the minimum value in the subtree rooted at that node.
template <typename T>
Node<T>* BinarySearchTree<T>::minValueNode(Node<T>* r) {
    Node<T>* current = r;
        while (current->left != nullptr)
            current = current->left;
        return current;
}

