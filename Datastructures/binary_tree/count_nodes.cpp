#include<iostream>
#include"tree.h"
using namespace std;
int count_nodes(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+count_nodes(root->right)+count_nodes(root->left);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    cout<<count_nodes(root);
}