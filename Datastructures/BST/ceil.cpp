#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
int ceil(TreeNode *root,int key)
{
    if(!root)
    return -1;
    if(root->val<key)
    return ceil(root->right,key);
    else if(root->val>key)
    {
        int temp=ceil(root->left,key);
        return temp!=-1?temp:root->val;
    }
    return root->val;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        TreeNode *root=new TreeNode(8);
        root->insert();
        int key;
        cin>>key;
        cout<<ceil(root,key);
    }
}