#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
Node *bubblesort(Node *head,int size)
{
    for (int i = 0; i < size; i++)
    {
        Node *prev = head;
        Node *prev_2_prev = NULL;
        Node *newhead = head;
        newhead = newhead->next;
        while (newhead != NULL)
        {
            if (prev->data > newhead->data)
            {
                Node *temp = newhead->next;
                if (prev_2_prev == NULL)
                {
                    prev->next = temp;
                    newhead->next = prev;
                    head = newhead;
                }
                else
                {
                    prev_2_prev->next = newhead;
                    newhead->next = prev;
                    prev->next = temp;
                }
            }
            prev_2_prev = prev;
            prev = newhead;
            newhead = newhead->next;
        }
    }
    return head;
}
int main()
{
    Node obj;
    obj.push(1);
    obj.push(2);
    obj.push(9);
    obj.push(3);
    obj.push(100);
    obj.push(5);
    obj.push(8);
    obj.push(6);
    obj.push(0);
    obj.print();
    obj.head = bubblesort(obj.head,obj.sizeoflist());
    obj.print();
}