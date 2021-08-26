#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    int size;
    public:
    Node *head;
    Node()
    {
        head=NULL;
        size=0;
        next = NULL;
    }
    /*method to push data */
    void push(int num)
    {
        size++;
        Node *obj = new Node();
        obj->data = num;
        if (head == NULL)
        {
            head = obj;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = obj;
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
        Node *ptr = head;
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
    /*mehtod to delete node in linked list*/
    void deletion(int val)
    {
        if (val == head->data)
        {
            head = head->next;
        }
        else
        {
            Node *ptr = head;
            Node *help;
            while (ptr->data != val)
            {
                help = ptr;
                ptr = ptr->next;
            }
            help->next = ptr->next;
        }
    }
    /*method to insert node(not at start)*/
    void insertion(int prev, int num)
    {
        if (head == NULL)
        {
            Node *obj = new Node();
            obj->data = num;
            head = obj;
        }
        else
        {
            Node *temp = head;
            while (temp->data != prev)
            {
                temp = temp->next;
            }
            Node *obj = new Node();
            obj->data = num;
            obj->next = temp->next;
            temp->next = obj;
        }
    }
    /*recursive function to reverse linked list*/
    Node *Reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        /*this part will bring us reversed linked list except 1st element*/
        Node *newhead = Reverse(head->next);
        /*we know our head pointing to 1st element of unReversed list has address of tail of Revesed ll*/
        /*so we will put address of our head in tails next*/
        head->next->next=head;
        /*and make our head/1st element to point to NULL*/
        head->next=NULL;
        return newhead;
    }
    /*iterative function to reverse linked list*/
    void Reverse_iter()
    {
        Node* Next=NULL;
        Node* current=head;
        Node* prev=NULL;
        while(current!=NULL)
        {
            Next=current->next;
            current->next=prev;
            prev=current;
            current=Next;
        }
        head=prev;
    }
    /*method to find mid of ll*/
    int midofll()
    {
        int temp = size / 2;
        Node *obj = head;
        for (int i = 0; i < temp; i++)
        {
            obj = obj->next;
        }
        return obj->data;
    }
    /*program to Append last N nodes to beginning*/
    friend Node* AppendLastNToFirst(Node* head,int n,int size);
    /*program to remove duplicates from sorted linked list*/
    friend Node* EliminateDuplicates(Node* head);
    /*program to print reverse of LL*/
    friend void print_reverse(Node* head);
    /*program to check if ll is palindrome*/
    friend bool palindrome(Node* head,int size);
    //program to make all even no after odd no
    friend Node* solve(Node* head);
    //program to delete every n nodes
    friend void delete_every_n(Node* head,int n,int m);
    //program to swap two nodes
    friend Node* swap(Node* head,int i, int j);
    //program to reverse nodes k times
    friend Node* Kreverse(Node* head,int k);
    //bubble sort on linked list
    friend Node* bubblesort(Node* head,int size);
    //merge sort on linked list
    friend Node* mergesort(Node* head);
    //floyd loop 
    friend bool detectLoop(Node *head);
};
