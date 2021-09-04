#include <string>
#include <math.h>
#include<iostream>
using namespace std;
template <typename T>
class map_array
{
public:
    string key;
    T value;
    map_array *next;
    map_array()
    {
        next = NULL;
    }
};
template <typename T>
class ourmap
{
    int current_size;
    int bucket_size;
    map_array<T> **array;

    int hashcode(string key)
    {
        int i = 0;
        int index = 0;
        while (key[i] != '\0')
        {
            index += (int)key[i] * pow(3, i);
            i++;
        }
        return index;
    }

public:
    ourmap()
    {
        this->bucket_size = 20;
        current_size = 0;
        array = new map_array<T> *[bucket_size];
        for (int i = 0; i < bucket_size; i++)
        {
            array[i] = NULL;
        }
    }
    void insert(string key, T value)
    {
        current_size++;
        int index = hashcode(key);
        index = index % 20;
        if (array[index] == NULL)
        {
            map_array<T> *newnode = new map_array<T>;
            newnode->key = key;
            newnode->value = value;
            newnode->next = NULL;
            array[index] = newnode;
        }
        else
        {
            map_array<T> *newnode = array[index];
            if (newnode->key == key)
            {
                newnode->value = value;
            }
            else
            {
                map_array<T> *newnode_2 = new map_array<T>;
                newnode_2->key = key;
                newnode_2->value = value;
                newnode_2->next = NULL;
                newnode->next = newnode_2;
            }
        }
    }
    T at(string key)
    {
        int index = hashcode(key);
        index = index % 20;
        map_array<T> *newnode = array[index];
        while(newnode != NULL)
        {
            if(newnode->key == key)
            {
                return newnode->value;
            }
            newnode=newnode->next;
        }
        return 0;
    }
    void delete_key(string key)
    {
        current_size--;
        int index = hashcode(key);
        index = index % 20;
        map_array<T> *newnode = array[index];
        map_array<T> *prevnode = NULL;
        while (newnode->key != key && newnode != NULL)
        {
            prevnode = newnode;
            newnode = newnode->next;
        }
        if (newnode != NULL)
        {
            if (prevnode == NULL)
            {
                array[index] = newnode->next;
            }
            else
            {
                prevnode->next = newnode->next;
            }
        }
    }
    int getsize()
    {
        return current_size;
    }
};
