#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int val)
    {
        this->val = val;
        random = NULL;
        next = NULL;
    }
};
Node *copyList(Node *head)
{

    Node *temp = head;
    //creating new nodes and putting them in next of given corresponding nodes
    while (temp != NULL)
    {
        Node *newnode = new Node(temp->val);
        newnode->next = temp->next;
        temp->next = newnode;
        temp = temp->next->next;
    }
    temp = head;
    //putting random in place for newely created nodes
    while (temp != NULL)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    temp = head;
    Node *newhead = temp->next;
    //seprating previous nodes and new nodes
    while (temp != NULL)
    {
        Node *new_temp = temp->next;
        temp->next = temp->next->next;

        if (new_temp->next)
            new_temp->next = new_temp->next->next;

        temp = temp->next;
    }
    return newhead;
}
int main()
{
    Node *obj1 = new Node(7);
    Node *obj2 = new Node(13);
    Node *obj3 = new Node(11);
    Node *obj4 = new Node(10);
    Node *obj5 = new Node(1);
    obj1->next = obj2;
    obj2->next = obj3;
    obj3->next = obj4;
    obj2->random = obj4;
    obj3->random = obj4;
    obj1->random = obj5;
    Node *newnode = copyList(obj1);
    while (newnode != NULL)
    {
        cout << newnode->val << " ";
        if (newnode->random)
            cout << newnode->random->val << " ";
        cout << endl;
        newnode = newnode->next;
    }
}