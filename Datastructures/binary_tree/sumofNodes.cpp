#include<iostream>
#include"tree.h"
using namespace std;
int sumofnodes(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int sum=root->data;
    sum+=sumofnodes(root->left);
    sum+=sumofnodes(root->right);
    return sum;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    cout<<sumofnodes(root);
}