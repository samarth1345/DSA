#include <bits/stdc++.h>
#include "SinglyLinkedList.cpp"
using namespace std;
bool detectLoop(Node *head)
{
    while (head != NULL && head->data != -1)
    {
        head->data = -1;
        head = head->next;
    }
    if (head == NULL)
    {
        return false;
    }
    return true;
}