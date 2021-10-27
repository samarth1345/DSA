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
    unordered_map<Node*,Node*> map;
    Node* temp=head;
    while(temp!=NULL)
    {
        Node *newnode=new Node(temp->val);
        map[temp]=newnode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        Node* toadd=map[temp];
        toadd->next=map[temp->next];
        toadd->random=map[temp->random];
        temp=temp->next;
    }
    return map[head];
}
int main()
{
    Node* obj1=new Node(7);
    Node* obj2=new Node(13);
    Node* obj3=new Node(11);
    Node* obj4=new Node(10);
    Node* obj5=new Node(1);
    obj1->next=obj2;
    obj2->next=obj3;
    obj3->next=obj4;
    obj2->random=obj4;
    obj3->random=obj4;
    obj1->random=obj5;
    Node *newnode=copyList(obj1);
    while(newnode!=NULL)
    {
        cout<<newnode->val<<" ";
        if(newnode->random)
        cout<<newnode->random->val<<" ";
        cout<<endl;
        newnode=newnode->next;
    }
}