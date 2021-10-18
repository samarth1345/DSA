#include<iostream>
#include"tree.h"
using namespace std;
pair<int,int> height_dia(treeNode<int> *root)
{
    pair<int,int> ans;
    if(root==NULL)
    {
        return ans;
    }
    pair<int,int> leftnode,rightnode;
    //height and diameter of left node
    leftnode=height_dia(root->left);

    //height and diameter of right node
    rightnode=height_dia(root->right);
    
    ans.first=max(leftnode.first,rightnode.first)+1;

    int temp=leftnode.first+rightnode.first+1;  //diameter of root node 
    ans.second=max(temp,max(leftnode.second,rightnode.second));

    return ans;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    root->printTree();
    pair<int,int> ans=height_dia(root);
    cout<<"Diameter="<<ans.second;
}