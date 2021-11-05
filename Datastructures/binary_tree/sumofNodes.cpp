#include<iostream>
#include"tree.h"
using namespace std;
int sumofnodes(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data+sumofnodes(root->left)+sumofnodes(root->right);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    cout<<sumofnodes(root);
}