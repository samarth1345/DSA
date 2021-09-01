//with singly linked list(not the most efficient one)
//for get and put in O(1) hashing is required 
#include <iostream>
using namespace std;
class LRUCache
{
    int value;
    int key;
    int count;
    int capacity;
    LRUCache *next = NULL;
    LRUCache *head = NULL;
    LRUCache *prev = NULL;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        count = 0;
    }
    void put(int key, int value)
    {
        if (!chechkey(key, value))
        {
            LRUCache *newobj = new LRUCache(1);
            newobj->key = key;
            newobj->value = value;
            if (head == NULL)
            {
                count++;
                head = newobj;
            }
            else if (count < capacity)
            {
                count++;
                newobj->next = head;
                head = newobj;
            }
            else
            {
                LRUCache *temp = head;
                LRUCache *prev = NULL;
                while (temp->next != NULL)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if (prev == NULL)
                {
                    head = newobj;
                }
                else
                {
                    prev->next = NULL;
                    newobj->next = head;
                    head = newobj;
                }
            }
        }
    }
    int get(int key)
    {
        LRUCache *temp = head;
        LRUCache *prev = NULL;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                putAtHead(temp, prev);
                return temp->value;
            }
            prev = temp;
            temp = temp->next;
        }
        return -1;
    }
    void putAtHead(LRUCache *current, LRUCache *prev)
    {
        if (prev != NULL)
        {
            prev->next = current->next;
            current->next = head;
            head = current;
        }
    }
    void print()
    {
        LRUCache *temp = head;
        while (temp != NULL)
        {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool chechkey(int key, int value)
    {
        LRUCache *prev = NULL;
        LRUCache *temp = head;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                temp->value = value;
                putAtHead(temp, prev);
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }
};
int main()
{
    LRUCache *obj = new LRUCache(2);
    cout << obj->get(2) << endl;
    obj->put(2, 6);
    cout << obj->get(1) << endl;
    obj->put(1, 5);
    obj->put(1, 2);
    //obj->print();
    cout << obj->get(1) << endl;
    cout << obj->get(2) << endl;
}