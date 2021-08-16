#include <iostream>
using namespace std;
class Circularll
{
    public:
    int data;
    Circularll *next;
    int size;
    public:
    Circularll *head;
    Circularll *tail;
    Circularll()
    {
        head=NULL;
        size=0;
        next = NULL;
    }
    /*method to push data */
    void push(int num)
    {
        size++;
        Circularll *obj = new Circularll();
        obj->data = num;
        if (head == NULL)
        {
            head = obj;
        }
        else
        {
            Circularll *ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = obj;
        }
        obj->next=head;
        tail=obj;
    }
    /*method to check if empty*/
    bool empty()
    {
        if (head != NULL)
        {
            return false;
        }
        return true;
    }
    /*method to print linked list*/
    void print()
    {
        Circularll *ptr = head;
        while (ptr->next!= head)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout <<ptr->data<< endl;
    }
    /*method to get size of linked list*/
    int sizeoflist()
    {
        return this->size;
    }
    /*mehtod to delete Circularll in linked list*/
    void deletion(int val)
    {
        if (val == head->data)
        {
            head = head->next;
            tail->next=head;
        }
        else
        {
            Circularll *ptr = head;
            Circularll *help;
            while (ptr->data != val)
            {
                help = ptr;
                ptr = ptr->next;
            }
            help->next = ptr->next;
        }
    }
    /*method to insert Circularll(not at start)*/
    void insertion(int prev, int num)
    {
        if (head == NULL)
        {
            Circularll *obj = new Circularll();
            obj->data = num;
            head = obj;
        }
        else
        {
            Circularll *temp = head;
            while (temp->data != prev)
            {
                temp = temp->next;
            }
            Circularll *obj = new Circularll();
            obj->data = num;
            obj->next = temp->next;
            temp->next = obj;
        }
    }
    /*recursive function to reverse linked list*/
    Circularll *Reverse(Circularll* head)
    {
        if (head == NULL || head->next == this->head)
        {
            return head;
        }
        /*this part will bring us reversed linked list except 1st element*/
        Circularll *newhead = Reverse(head->next);
        /*we know our head pointing to 1st element of unReversed list has address of tail of Revesed ll*/
        /*so we will put address of our head in tails next*/
        head->next->next=head;
        /*and make our head/1st element to point to NULL*/
        head->next=newhead;
        tail=head;
        return newhead;
    }
    /*iterative function to reverse linked list*/
    void Reverse_iter()
    {
        Circularll* Next=NULL;
        Circularll* current=head;
        Circularll* prev=head;
        while(current->next!=head)
        {
            Next=current->next;
            current->next=prev;
            prev=current;
            current=Next;
        }
        current->next=prev;
        tail=head;
        head->next=current;
        head=current;
    }
    /*method to find mid of ll*/
    int midofll()
    {
        int temp = size / 2;
        Circularll *obj = head;
        for (int i = 0; i < temp; i++)
        {
            obj = obj->next;
        }
        return obj->data;
    }
};
