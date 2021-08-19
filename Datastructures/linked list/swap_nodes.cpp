#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
Node* swap(Node *head, int i, int j)
{
    Node *current = head;
    Node *prev;
    Node *prev_1;
    Node *current_1;
    for (int x = 0; x < j; x++)
    {
        if (x == i)
        {
            prev_1 = prev;
            current_1 = current;
        }
        prev = current;
        current = current->next;
    }
    if (i == 0)
    {   head=current;
        Node *temp = current->next;
        current->next = current_1->next;
        prev->next = current_1;
        current_1->next = temp;
    }
    else
    {
        prev_1->next = current;
        prev->next = current_1;
        Node *temp = current->next;
        current->next = current_1->next;
        current_1->next = temp;
    }
    return head;
}
int main()
{
    Node obj;
    obj.push(0);
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(6);
    obj.push(7);
    obj.push(8);
    obj.print();
    obj.head=swap(obj.head, 0, 8);
    obj.print();
}