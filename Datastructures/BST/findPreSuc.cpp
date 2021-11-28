#include <iostream>
#include "tree.h"
using namespace std;
//logic:we just have to find floor and ceil of key beacause in inorder
//traversal it is same as sorted array and successor and predecessor are just floor and ceil
void findPre(TreeNode *root, TreeNode *&pre, int val)
{
    // Your code goes here
    if (!root)
        return;
    if (root->val >= val)
        findPre(root->left, pre,val);
    else
    {
        pre = root;
        findPre(root->right, pre,val);
    }
}
void findSuc(TreeNode *root, TreeNode *&suc, int val)
{
    // Your code goes here
    if (!root)
        return;
    if (root->val <= val)
        findSuc(root->right,suc,val);
    else
    {
        suc = root;
        findSuc(root->left, suc,val);
    }
}
int main()
{
    TreeNode *root=new TreeNode(4);
    root->insert();
    TreeNode *pre=NULL,*suc=NULL;
    findPre(root,pre,4);
    findSuc(root,suc,4);
    if(pre)
    cout<<pre->val<<endl;
    if(suc)
    cout<<suc->val;
}