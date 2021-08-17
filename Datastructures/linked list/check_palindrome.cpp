#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
bool palindrome(Node* head,int size)
{
    //creating two LL and pushing first half of given LL and second half
    Node obj1;
    Node obj2;
    for(int i=0;i<size/2;i++)
    {
        obj1.push(head->data);
        head=head->next;
    }
    while(head!=NULL)
    {
        obj2.push(head->data);
        head=head->next;
    }
    //adjustment for odd size LL
    if(size%2!=0)
    {
        obj2.head=obj2.head->next;
    }
    //reversing 2nd half to compare LL's
    obj2.Reverse_iter();
    Node* head1=obj1.head;
    Node* head2=obj2.head;
    while(head1!=NULL)
    {
        if(head1->data != head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
int main()
{
    Node obj;
    obj.push(1);
    obj.push(3);
    obj.push(2);
    obj.print();
    if(palindrome(obj.head,obj.sizeoflist()))
    {
        cout<<"palindrome"<<endl;
    }
    else
    {
        cout<<"not palindrome"<<endl;
    }
}