#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
struct Node
{
    int key;
    Node *next;
};
class LinkedList
{
private:
    //pointer to the head of the linked list
    Node *head;

public:
    //linked list constructor
    LinkedList();
    //insert a key
    void insert(int key);
    //display the linked list
    void display();
    //search the linked list for the given data, returns -1 if not found, otherwise index found
    int search(int key);
};
#endif //   LINKEDLIST_HPP