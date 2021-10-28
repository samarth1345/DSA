#include <iostream>
#include<queue>
#include "tree.h"
using namespace std;
//2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
void MirrorTree(treeNode<int> *root)
{
    queue<treeNode<int> *> q;
    q.push(root->right);
    q.push(root->left);
    while (!q.empty())
    {
        treeNode<int> *temp = q.front();
        cout << temp->data;
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        q.pop();
    }
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    MirrorTree(root);
}