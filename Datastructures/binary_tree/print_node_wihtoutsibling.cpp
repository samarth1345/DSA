#include <iostream>
#include "tree.h"
using namespace std;
void print_without_sibling(treeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL || root->right==NULL)
    {
        if(root->left!=NULL)
        {
            cout<<root->left->data<<" ";
        }
        else if(root->right!=NULL)
        {
            cout<<root->right->data<<" ";
        }
    }
    print_without_sibling(root->left);
    print_without_sibling(root->right);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    print_without_sibling(root);
}