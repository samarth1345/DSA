#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
Node *findtail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}
void swap(Node *first, Node *first_prev, Node *second, Node *second_prev)
{
    Node *temp = first->next;
    second_prev->next = first;
    first->next = second->next;
    first_prev->next = second;
    second->next = temp;
}
Node *quicksort(Node *head)
{
    Node *tail = findtail(head);
    Node *temp_1 = head;
    Node *temp_1_prev = head;
    Node *temp_2 = head;
    Node *temp_2_prev = head;
    while (temp_2->next != tail)
    {
        if (temp_2->data > tail->data)
        {
            
        }
    }
}
