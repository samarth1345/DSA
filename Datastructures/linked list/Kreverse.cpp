#include <bits/stdc++.h>
#include "SinglyLinkedList.cpp"
using namespace std;
Node* Kreverse(Node* head,int k)
{
    if(head->next == NULL || head==NULL)
    {
        return head;
    }
    /*Reversing iteratively for length k*/
    Node* Next=NULL;
    Node* current=head;
    Node* prev=NULL;
    int count=0;
    while(current!=NULL && count<k)
    {
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
        count++;
    }
    /************************************/
    /*getting newhead recursively*/
    if(Next!=NULL)
    {
        Node* newhead=Kreverse(Next,k);
        head->next=newhead;
    }
    /*returning New head for list*/
    return prev;                         
}
int main()
{
    Node obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4); 
    obj.push(5); 
    obj.push(6); 
    obj.push(7); 
    obj.push(8); 
    obj.push(9); 
    obj.print();
    obj.head=Kreverse(obj.head,2);
    obj.print();
}