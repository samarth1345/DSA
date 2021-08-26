#include <bits/stdc++.h>
#include "SinglyLinkedList.cpp"
using namespace std;
bool detectLoop(Node *head)
{
    Node* fast=head;
    Node* slow=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}