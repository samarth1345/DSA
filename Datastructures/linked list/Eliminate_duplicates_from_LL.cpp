/*program to remove duplicates from sorted linked list*/
#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
Node* EliminateDuplicates(Node* head)
{
    Node* current=head;
    Node* prev=NULL;
    while(current->next!=NULL)
    {
        prev=current;
        current=current->next;
        if(prev->data == current->data)
        {
            prev->next=current->next;
        }
    }
    return head;
}
int main()
{
    Node obj;
    obj.push(10);
    obj.push(10);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.push(50);
    obj.print();
    obj.head=EliminateDuplicates(obj.head);
    obj.print();
}