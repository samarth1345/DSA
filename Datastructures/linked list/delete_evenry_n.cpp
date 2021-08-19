#include <iostream>
#include "SinglyLinkedList.cpp"
using namespace std;
void delete_every_n(Node *head, int n, int m)
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
    delete_every_n(obj.head, 0, 2);
    obj.print();
}