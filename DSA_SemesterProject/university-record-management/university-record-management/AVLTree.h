// TEMPLATE FOR AVL TREE
#ifndef AVLTREES_H
#define AVLTREES_H

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// defining template class for avl trees
template <typename T>
class AVLTree
{
private:
    struct avl_node
    {
        T key; // object to student or book
        int height;
        avl_node *left;
        avl_node *right;
        // constructor  for node of the avl tree
        avl_node(T key) : key(key), height(1), left(nullptr), right(nullptr) {}
    };
    avl_node *root;
    // helper functions not intended to be called directly
    // to determine is tree is empty
    bool isEmpty(avl_node *) const;
    // function to determine height of the tree
    int height(avl_node *);
    // function to determine balance factor of a node
    int balance_factor(avl_node *);
    // rotation functions
    avl_node *left_rotate(avl_node *);
    avl_node *right_rotate(avl_node *);
    // determine the minimum value node from the avl tree
    avl_node *minValue_node(avl_node *);
    // private declarations
    avl_node *insert(avl_node *, T);
    avl_node *remove(avl_node *, T);
    bool boolSearch(avl_node *, T);
    void print_inOrder(avl_node *);               // function to print the AVL tree elements in sorted order
    void getValuesPriv(avl_node *, vector<T>& ); // function to return all the values of the avl tree
    T *search(avl_node *, const T &);

public:

    // public constructor for avl tree
    AVLTree() : root(nullptr) {}

    // main functions for the public interface
    // input parameters root node and template key data
    
    // public insert method
    bool isEmpty() const
    {
        return isEmpty(root);
    }

    void insert(T key)
    {
        root = insert(root, key);
    }

    // public remove method
    void remove(T key)
    {
        root = remove(root, key);
    }

    // public search method with boolean return value
    bool boolSearch(T key)
    {
        return boolSearch(root, key);
    }

    // public function to print the AVL tree elements in sorted order
    void print_inOrder()
    {
        print_inOrder(root);
        std::cout << std::endl;
    }

    // public interface to return all values of the avl tree
    vector<T> getValues()
    {
        vector<T> values;
        getValuesPriv(root, values);
        return values;
    }

    // public search method that returns searched node
    T *search(const T &key)
    {
        return search(root, key);
    }

    // Function to retrieve the root value of the AVL tree
    T getRootValue()
    {
        if (root)
        {
            return root->key;
        }
        else
        {
            throw std::runtime_error("AVL Tree is empty.");
        }
    }
};

template <typename T>
int AVLTree<T>::height(avl_node *node)
{
    if (node == nullptr)
        return 0;
    else
        return node->height;
}

template <typename T>
bool AVLTree<T>::isEmpty(avl_node *root) const
{
    return root == nullptr;
}

template <typename T>
int AVLTree<T>::balance_factor(avl_node *node)
{
    if (node == nullptr)
        return 0;
    else
        return height(node->left) - height(node->right);
}

template <typename T>
typename AVLTree<T>::avl_node *AVLTree<T>::left_rotate(avl_node *x)
{
    avl_node *y = x->right; // y is right child of x
    avl_node *T2 = y->left; // T2 is left child of y

    // Perform rotation
    y->left = x;   // make x as left child of y
    x->right = T2; // make T2 as right child of x

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1; // update height of x
    y->height = max(height(y->left), height(y->right)) + 1; // update height of y

    // Return new root
    return y; // now y is the root after rotation
}

template <typename T>
typename AVLTree<T>::avl_node *AVLTree<T>::right_rotate(avl_node *y)
{
    avl_node *x = y->left;   // x is left child of y
    avl_node *T2 = x->right; // T2 is right child of x

    // Perform rotation
    x->right = y; // make y as right child of x
    y->left = T2; // make T2 as left child of y

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1; // update height of y
    x->height = max(height(x->left), height(x->right)) + 1; // update height of x

    // Return new root
    return x; // now x is the root after rotation
}

template <typename T>
typename AVLTree<T>::avl_node *AVLTree<T>::minValue_node(avl_node *node)
{
    avl_node *current = node;
    // loop through the tree to reach the leftmost leaf node
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

template <typename T>
typename AVLTree<T>::avl_node *AVLTree<T>::insert(avl_node *node, T key)
{
    if (node == nullptr)
        return new avl_node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Equal keys are not allowed in BST

    // update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // get the balance factor
    int balance = balance_factor(node);

    // if the insertion causes imbalance
    // there are 4 cases

    // left left case
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    // right right case
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    // left right case
    if (balance > 1 && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // right left case
    if (balance < -1 && key < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    // return the node pointer
    return node;
}

template <typename T>
typename AVLTree<T>::avl_node *AVLTree<T>::remove(avl_node *root, T key)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else
    {
        // node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr))
        {
            avl_node *temp = root->left ? root->left : root->right;

            // no child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else               // one child case
                *root = *temp; // copy the contents of the non-empty child

            delete temp;
        }
        else
        {
            // node with two children: get the inorder
            // successor (smallest in the right subtree)
            avl_node *temp = minValue_node(root->right);

            // copy the inorder successor's data to this node
            root->key = temp->key;

            // delete the inorder successor
            root->right = remove(root->right, temp->key);
        }
    }

    // if the tree had only one node then return
    if (root == nullptr)
        return root;

    // update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // get the balance factor
    int balance = balance_factor(root);

    // if this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && balance_factor(root->left) >= 0)
        return right_rotate(root);

    // Left Right Case
    if (balance > 1 && balance_factor(root->left) < 0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && balance_factor(root->right) <= 0)
        return left_rotate(root);

    // Right Left Case
    if (balance < -1 && balance_factor(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

template <typename T>
bool AVLTree<T>::boolSearch(avl_node *root, T key)
{
    // base cases: root is null or key is present at root
    if (root == nullptr || root->key == key)
        return root != nullptr;

    // Key is greater than root's key
    if (root->key < key)
        return boolSearch(root->right, key);

    // Key is smaller than root's key
    return boolSearch(root->left, key);
}

template <typename T>
void AVLTree<T>::print_inOrder(avl_node *node)
{
    if (node != nullptr)
    {
        print_inOrder(node->left);
        std::cout << node->key << " ";
        print_inOrder(node->right);
    }
}

template <typename T>
void AVLTree<T>::getValuesPriv(avl_node *node, vector<T> &values)
{
    if (node != nullptr)
    {
        // inorder traversal
        getValuesPriv(node->left, values);
        values.push_back(node->key);
        getValuesPriv(node->right, values);
    }
}

template <typename T>
T *AVLTree<T>::search(avl_node *node, const T &key)
{
    if (node == NULL)
    {
        return NULL; // key not found
    }
    if (key < node->key)
    {
        return search(node->left, key);
    }
    else if (key > node->key)
    {
        return search(node->right, key);
    }
    else
    {
        return &(node->key);
    }
}

#endif