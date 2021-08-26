#include <bits/stdc++.h>
#include "SinglyLinkedList.cpp"
using namespace std;
void removeLoop(Node *head)
{
    Node *prev = NULL;
    while (head != NULL && head->data != -1)
    {
        prev = head;
        head->data = -1;
        head = head->next;
    }
    if (head != NULL)
    {
        prev->next = NULL;
    }
}