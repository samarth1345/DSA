//For a given singly linked list of integers, 
//arrange the elements such that all the even numbers are placed after the odd numbers. 
//The relative order of the odd and even terms should remain unchanged.
#include<iostream>
#include"SinglyLinkedList.cpp"
using namespace std;
Node* solve(Node* head)
{
    Node* OddH=NULL;
    Node* OddT=NULL;
    Node* EvenH=NULL;
    Node* EvenT=NULL;
    while(head!=NULL)
    {
        if(head->data % 2!=0)
        {
            if(OddH==NULL)
            {
                OddH=OddT=head;
            }
            else
            {
                OddT->next=head;
                OddT=head;
            }
        }
        else
        {
            if(EvenH==NULL)
            {
                EvenH=EvenT=head;
            }
            else
            {
                EvenT->next=head;
                EvenT=head;
            }
        }
        head=head->next;
    }
    OddT->next=EvenH;
    EvenT->next=NULL;
    return OddH;
}
int main()
{
    Node obj;
    obj.push(1);
    obj.push(4);
    obj.push(5);
    obj.push(2); 
    obj.print();
    obj.head=solve(obj.head);
    obj.print();
}