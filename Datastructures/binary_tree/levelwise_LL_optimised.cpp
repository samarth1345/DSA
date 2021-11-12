#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;
class LL
{
public:
    int data;
    LL *next;
    treeNode<int> *head;
    LL()
    {
        next = NULL;
        head = NULL;
    }
};
void pushleft(LL *temp,queue<LL *>& q)
{
    if (temp->head->left != NULL)
    {
        LL *temp1 = new LL();
        temp1->head = temp->head->left;
        temp1->data = temp->head->left->data;
        q.push(temp1);
    }
}
void pushright(LL *temp,queue<LL *>& q)
{
    if (temp->head->right != NULL)
    {
        LL *temp1 = new LL();
        temp1->head = temp->head->right;
        temp1->data = temp->head->right->data;
        q.push(temp1);
    }
}
//using level wise linked list and pushing NULL after every level
//to mark the end of that level
vector<LL *> solve(treeNode<int> *root)
{
    queue<LL *> q;
    vector<LL *> ans;
    LL *obj = new LL();
    obj->head = root;
    obj->data = root->data;
    q.push(obj);
    q.push(NULL);
    while (!q.empty())
    {
        LL *head = q.front(), prev;
        ans.push_back(head);
        //linking nodes of same level until a NULL is encountered
        while (q.front() != NULL)
        {
            LL *temp = q.front();
            q.pop();
            head->next = temp;
            head = head->next;
            //pushing object of LL with data of left node of current node in queue
            if (temp->head->left != NULL)
            {
                LL *temp1 = new LL();
                temp1->head = temp->head->left;
                temp1->data = temp->head->left->data;
                q.push(temp1);
            }
            //pushing object of LL with data of right node of current node in queue
            if (temp->head->right != NULL)
            {
                LL *temp1 = new LL();
                temp1->head = temp->head->right;
                temp1->data = temp->head->right->data;
                q.push(temp1);
            }
        }
        q.pop();
        q.push(NULL);
    }
    return ans;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(8);
    root->insert();
    vector<LL *> ans = solve(root);
    for (int i = 0; i < ans.size(); i++)
    {
        LL *temp = ans[i];
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}