//You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
//Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. 
//Continue the same until the end of the linked list.
#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
Node *delete_every_n(Node *head, int n, int m)
{
    Node *temp = head;
    Node *prev = NULL;
    int x = 0;
    while (temp != NULL)
    {
        if (x == n)
        {

            for (int i = 0; i < m; i++)
            {
                if (temp == NULL)
                {
                    prev->next = NULL;
                    break;
                }
                temp = temp->next;
            }
            prev->next = temp;
            x = 0;
        }
        else
        {
            prev = temp;
            temp = temp->next;
            x++;
        }
    }
    return head;
}
int main()
{
    Node obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(6);
    obj.push(7);
    obj.push(8);
    obj.print();
    obj.head = delete_every_n(obj.head, 1, 2);
    obj.print();
}