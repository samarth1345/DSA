#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
Node *merge(Node *head1, Node *head2)
{
    Node *newnode = new Node();
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            newnode->push(head1->data);
            head1 = head1->next;
        }
        else
        {
            newnode->push(head2->data);
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
    {
        while (head1 != NULL)
        {
            newnode->push(head1->data);
            head1 = head1->next;
        }
    }
    else if (head2 != NULL)
    {
        while (head2 != NULL)
        {
            newnode->push(head2->data);
            head2 = head2->next;
        }
    }
    return newnode->head;
}
Node *findmid(Node *head)
{
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    for (int i = 1; i < size / 2; i++)
    {
        head = head->next;
    }
    return head;
}
Node *mergesort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = findmid(head);
    Node *head2 = temp->next;
    temp->next = NULL;
    Node *Newhead1 = mergesort(head);
    Node *Newhead2 = mergesort(head2);
    Node *Newhead = merge(Newhead1, Newhead2);
    return Newhead;
}
int main()
{
    Node obj;
    obj.push(101);
    obj.push(10);
    obj.push(5);
    obj.push(20);
    obj.push(3);
    obj.push(2);
    obj.head = mergesort(obj.head);
    obj.print();
}