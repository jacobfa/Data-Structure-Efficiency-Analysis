#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    head = 0;
}
void LinkedList::insert(int data)
{
    Node *addNode = new Node;
    addNode->key = data;
    addNode->next = 0;
    Node *temp = head;
    //if the head is null, then this is where we add
    if (head == 0)
    {
        head = addNode;
        return;
    }
    else
    {
        //traverse through the linked list to find the next
        //empty node
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = addNode;
    }
}
void LinkedList::display()
{
    Node *temp = new Node;
    temp = head;
    //display all nodes in the linked list
    while (temp != 0)
    {
        std::cout << temp->key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
/**
 * Search the linked list for the given data
 * @param data the data to search for
 * @return -1 if not found, otherwise the index found.
 * */
int LinkedList::search(int data)
{
    Node *temp = head;
    int index = 0;
    while (temp != 0)
    {
        if (temp->key == data)
            return index;
        temp = temp->next;
    }
    return -1;
}