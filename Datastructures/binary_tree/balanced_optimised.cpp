#include<iostream>
#include"tree.h"
using namespace std;
//return height if tree is balanced else return -1
int height(treeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left,right;
    left=height(root->left);
    right=height(root->right);
    if(left!=-1 && right!=-1 && abs(left-right)<=1)
    {
        return max(left,right)+1;
    }
    return -1;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(5);
    root->insert();
    root->printTree();
    if(height(root)!=-1)
    {
        cout<<"balanced"<<endl;
    }
    else
    {
        cout<<"not balanced"<<endl;
    }
}