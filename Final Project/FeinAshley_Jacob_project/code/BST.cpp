#include "BST.hpp"
#include <iostream>

BST::BST()
{
    root = 0;
}
//a helper function for insert to insert a node into a binary search tree
bool insertRecursive(Node *&temp, int data)
{
    Node *tempAdd = new Node;
    tempAdd->left = 0;
    tempAdd->right = 0;
    tempAdd->key = data;
    //if the current node's data = the given value, then we should exit
    //because the data is already in the tree
    if (temp->key == data)
        return false;
    //keep going left if the data is less than the current node's data
    if (data < temp->key)
    {
        //if the left node is null and the data is less than the given data, we have found our node to add to
        if (temp->left == 0)
        {
            temp->left = tempAdd;
            return true;
        }
        //if not, keep traversing left
        else
        {
            return insertRecursive(temp->left, data);
        }
    }
    else if (data > temp->key)
    {
        //if the right node is null, we've found our node to add to
        if (temp->right == 0)
        {
            temp->right = tempAdd;
            return true;
        }
        //if not, keep traversing right
        else
        {
            return insertRecursive(temp->right, data);
        }
    }
    return false;
}
//insert the given data into the bst
bool BST::insert(int data)
{
    if (root == 0)
    {
        Node *temp = new Node;
        temp->key = data;
        temp->left = 0;
        temp->right = 0;
        root = temp;
        return true;
    }
    bool returnValue = insertRecursive(root, data);
    return returnValue;
}
void inOrderTraversalR(Node *temp)
{
    if (temp == 0)
        return;
    inOrderTraversalR(temp->left);
    std::cout << temp->key << " ";
    inOrderTraversalR(temp->right);
}
void preOrderTraversalR(Node *temp)
{
    if (temp == 0)
        return;
    std::cout << temp->key << " ";
    preOrderTraversalR(temp->left);
    preOrderTraversalR(temp->right);
}
void postOrderTraversalR(Node *temp)
{
    if (temp == 0)
        return;
    postOrderTraversalR(temp->left);
    postOrderTraversalR(temp->right);
    std::cout << temp->key << " ";
}
void BST::preOrderTraversal()
{
    preOrderTraversalR(root);
}
void BST::postOrderTraversal()
{
    postOrderTraversalR(root);
}
void BST::inOrderTraversal()
{
    inOrderTraversalR(root);
}
Node *searchRecursive(Node *temp, int data)
{
    if (temp->key < data)
    {
        //if the right node is null, the node is not in the tree, return 0.
        if (temp->right == 0)
            return 0;
        else
            return searchRecursive(temp->right, data);
    }
    if (temp->key > data)
    {
        //if the left node is null, the node is not in the tree and we should return null;
        if (temp->left == 0)
            return 0;
        else
            return searchRecursive(temp->left, data);
    }
}
Node *BST::search(int data)
{
    if (root == 0 || root->key == data)
        return root;
    Node *returnNode = searchRecursive(root, data);
    return returnNode;
}