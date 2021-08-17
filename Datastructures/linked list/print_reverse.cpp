/*program to print reverse of LL using recursion*/
#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
void print_reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        cout<<head->data<<" ";
        return;
    }
    print_reverse(head->next);
    cout<<head->data<<" ";
}
int main()
{
    Node obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.print();
    print_reverse(obj.head);
}