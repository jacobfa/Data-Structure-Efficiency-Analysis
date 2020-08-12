#ifndef BST_HPP
#define BST_HPP
#include <iostream>

struct Node
{
    int key;
    Node *left;
    Node *right;
};
class BST
{
private:
    Node *root;

public:
    BST();
    //insert the given data into the bst (returns false if addition was unsuccessful)
    bool insert(int data);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    //returns a node with the given data or null if nothing found
    Node *search(int data);
};
#endif //  BST_HPP