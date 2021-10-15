#include<iostream>
#include"tree.h"
using namespace std;
int count_nodes(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int count=1;
    count+=count_nodes(root->left);
    count+=count_nodes(root->right);
    return count;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    cout<<count_nodes(root);
}