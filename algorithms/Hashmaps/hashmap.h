#include <string>
#include <math.h>
#include <iostream>
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
        map_array<T> *head = array[index];
        if (head == NULL)
        {
            map_array<T> *newnode= new map_array<T>;
            newnode->key = key;
            newnode->value = value;
            array[index] = newnode;
        }
        else
        {
            map_array<T> *prevnode = NULL;
            while(head != NULL)
            {
                if(head->key == key)
                {
                    head->value=value;
                }
                prevnode=head;
                head=head->next;
            }
            if(head == NULL)
            {
                map_array<T> *temp = new map_array<T>;
                temp->key=key;
                temp->value=value;
                prevnode->next=temp;
            }
        }
    }
    T at(string key)
    {
        int index = hashcode(key);
        index = index % 20;
        map_array<T> *newnode = array[index];
        while (newnode != NULL)
        {
            if (newnode->key == key)
            {
                return newnode->value;
            }
            newnode = newnode->next;
        }
        return 0;
    }
    void delete_key(string key)
    {

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
            current_size--;
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
