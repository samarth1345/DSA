#include <iostream>
using namespace std;
class Doublyll
{
    public:
    int data;
    Doublyll *next;
    Doublyll *prev;
    int size;
    public:
    Doublyll *head;
    Doublyll()
    {
        head=NULL;
        size=0;
        next = NULL;
        prev=NULL;
    }
    /*method to push data */
    void push(int num)
    {
        size++;
        Doublyll *obj = new Doublyll();
        obj->data = num;
        if (head == NULL)
        {
            head = obj;
        }
        /*In new node made address of previous object would be stored in obj->pre*/
        else
        {
            Doublyll *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = obj;
            obj->prev=ptr;
        }
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
        Doublyll *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    /*method to get size of linked list*/
    int sizeoflist()
    {
        return this->size;
    }
    /*mehtod to delete Doublyll in linked list*/
    void deletion(int val)
    {
        if (val == head->data)
        {
            head = head->next;
            head->prev=NULL;
        }
        else
        {
            Doublyll *ptr = head;
            Doublyll *help;
            while (ptr->data != val)
            {
                help = ptr;
                ptr = ptr->next;
            }
            help->next = ptr->next;
            /*just one step extra from single ll element next to element TBD has to change its prev address*/
            ptr->next->prev=help;
        }
    }
    /*method to insert Doublyll(not at start)*/
    void insertion(int prev, int num)
    {
        if (head == NULL)
        {
            Doublyll *obj = new Doublyll();
            obj->data = num;
            head = obj;
        }
        else
        {
            Doublyll *temp = head;
            while (temp->data != prev)
            {
                temp = temp->next;
            }
            Doublyll *obj = new Doublyll();
            obj->data = num;          /*value added in new node*/
            obj->next = temp->next;   /*new node's next has been given value next in temp*/
            temp->next->prev=obj;     /*new node's address added in element next to it*/
            temp->next = obj;         /*new node's address added in element prev to it*/
            obj->prev=temp;           /*new node's prev has required address*/
        }
    }
    /*recursive function to reverse linked list*/
    Doublyll *Reverse(Doublyll* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        /*this part will bring us reversed linked list except 1st element*/
        Doublyll *newhead = Reverse(head->next);
        /*we will put address of next element to head in prev of head*/
        head->prev=head->next;
        /*we know our head pointing to 1st element of unReversed list has address of tail of Revesed ll*/
        /*so we will put address of our head in tails next*/
        head->next->next=head;
        /*and make our head/1st element to point to NULL*/
        head->next=NULL;
        return newhead;
    }
    /*iterative function to reverse linked list:just reversing prev and next*/
    void Reverse_iter()
    {
        Doublyll* help=NULL;
        Doublyll* store=NULL;
        Doublyll* current=head;
        while(current!=NULL)
        {
           store=current;
           help=current->next;
           current->next=current->prev;
           current->prev=help;;
           current=help;
        }
        head=store;
    }
    /*method to find mid of ll*/
    int midofll()
    {
        int temp = size / 2;
        Doublyll *obj = head;
        for (int i = 0; i < temp; i++)
        {
            obj = obj->next;
        }
        return obj->data;
    }
};