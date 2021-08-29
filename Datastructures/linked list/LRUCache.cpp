#include <iostream>
using namespace std;
class LRUCache
{
    int value;
    int key;
    int frequency;
    int count;
    int capacity;
    LRUCache *next = NULL;
    LRUCache *head = NULL;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        frequency = 0;
        count = 0;
    }
    void put(int key, int value)
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
            newobj->next=head;
            head=newobj;
        }
        else
        {
            newobj->next=head->next;
            head=newobj;
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
                temp->frequency++;
                afterget(temp, prev);
                return temp->value;
            }
            prev = temp;
            temp = temp->next;
        }
        return -1;
    }
    void afterget(LRUCache *temp, LRUCache *prev_temp)
    {
        LRUCache *temp_2 = head;
        LRUCache *prev = NULL;
        LRUCache *Next = NULL;
        while (temp_2->frequency < temp->frequency && temp_2 != NULL)
        {
            prev = temp_2;
            temp_2 = temp_2->next;
        }
        if (prev != NULL)
        {
            prev->next = temp;
        }
        if (temp_2 != NULL)
        {
            temp->next = temp_2;
        }
    }
};
int main()
{
    LRUCache *obj = new LRUCache(3);
    obj->put(1, 2);
    obj->put(2, 1);
    obj->put(3, 4);
    cout << obj->get(2)<<endl;
    cout << obj->get(2)<<endl;
    cout << obj->get(3)<<endl;
    obj->put(4, 3);
}