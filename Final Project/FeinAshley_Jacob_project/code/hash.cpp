#include "hash.hpp"
#include <iostream>

HashTable::HashTable(int bsize)
{
    this->tableSize = bsize;
    table = new node *[tableSize];
    for (int i = 0; i < bsize; ++i)
    {
        table[i] = 0;
    }
}
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "|| ";
        node *temp = table[i];
        while (temp != 0)
        {
            cout << temp->key << " ";
            temp = temp->next;
        }
    }
}
/**
 * Returns a pointer node in reference to
 * the key given in the hash table
 * @param key the key to search for in the hashtable
 * @return null if not found or a pointer to the key given
 * */
node *HashTable::searchItemChaining(int key)
{
    int index = hashFunction(key);
    //if the index where the key is given is empty, the key must not be found
    if (table[index] == 0)
    {
        return 0;
    }
    else
    {
        node *temp = table[index];
        //iterate through the hash table with nodes, make sure
        //the next node isn't null and that we haven't found the
        //data in the current node's data
        while (temp->key != key && temp->next != 0)
        {
            temp = temp->next;
        }
        return temp;
    }
}
node *HashTable::searchItemLinear(int key)
{
    int index = hashFunction(key);
    int count = 0;
    while (table[index] != 0)
    {
        int count = 0;
        count++;
        //makes sure that we haven't gone out of bounds, and if we have,
        //exit the function because the key has not been found.
        if (count >= tableSize)
            return 0;
        if (table[index]->key == key)
            return table[index];
        index++;
        index %= tableSize;
    }
}

node *HashTable::searchItemQuadratic(int key)
{
    int index = hashFunction(key);
    //search for the next available index using quadratic probing.
    while (table[index] != 0 && table[index]->key != key)
    {
        collisions++;
        index = index + 2 * collisions - 1;
        //makes sure we haven't gone out of bounds, and if we have,
        //the key is not in the hash table and we should return null
        if (index >= tableSize)
            return 0;
    }
    return table[index];
}
bool HashTable::insertItemChaining(int key)
{
    int index = hashFunction(key);
    //checks to see if the key is already in the hashTable
    if (searchItemChaining(key))
    {
        //finds where the node alrady is, and creates a new node next to it
        node *temp = new node;
        temp->key = key;
        temp->next = table[index]->next;
        table[index]->next = temp;
        return false;
    }
    else
    {
        //then the key is not already in the hashtable and can be added
        //so create a new node with the data and add it to the table
        node *temp = new node;
        temp->key = key;
        temp->next = 0;
        table[index] = temp;
        return true;
    }
}

bool HashTable::insertItemLinear(int key)
{
    int index = hashFunction(key);
    //checks to see if the key is already in the hashTable
    if (searchItemLinear(key))
    {
        //finds where the node alrady is, and creates a new node next to it
        node *temp = new node;
        temp->key = key;
        temp->next = table[index]->next;
        table[index]->next = temp;
        return false;
    }
    else
    {
        //then the key is not already in the hashtable and can be added
        //so create a new node with the data and add it to the table
        node *temp = new node;
        temp->key = key;
        temp->next = 0;
        table[index] = temp;
        return true;
    }
}

bool HashTable::insertItemQuadratic(int key)
{
    int index = hashFunction(key);
    //checks to see if the key is already in the hashTable
    if (searchItemQuadratic(key))
    {
        //finds where the node alrady is, and creates a new node next to it
        node *temp = new node;
        temp->key = key;
        temp->next = table[index]->next;
        table[index]->next = temp;
        return false;
    }
    else
    {
        //then the key is not already in the hashtable and can be added
        //so create a new node with the data and add it to the table
        node *temp = new node;
        temp->key = key;
        temp->next = 0;
        table[index] = temp;
        return true;
    }
}

int HashTable::getNumOfCollision()
{
    return collisions;
}
