/*program to Append last N nodes to beginning*/
#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
Node *AppendLastNToFirst(Node *head, int n, int size)
{
    if (n > 0)
    {
        Node *current = head;
        Node *prev = NULL;
        for (int i = 0; i < size - n; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        Node *temp = current;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = head;
        return temp;
    }
    return head;
}
int main()
{
    Node obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.push(60);
    obj.print();
    Node *head = obj.head;
    int n;
    cin >> n;
    obj.head = AppendLastNToFirst(head, n, obj.sizeoflist());
    obj.print();
}
