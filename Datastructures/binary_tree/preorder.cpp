#include<iostream>
#include"tree.h"
using namespace std;
void preorder(treeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    preorder(root);
}