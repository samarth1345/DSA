#include<iostream>
#include"tree.h"
using namespace std;
//2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
void inorder_traversal(treeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    inorder_traversal(root);
}