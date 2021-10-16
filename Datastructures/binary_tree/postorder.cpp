#include<iostream>
#include"tree.h"
using namespace std;
void postorder(treeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    postorder(root);
}