#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *newnode = new TreeNode(val);
    if (!root)
        return newnode;
    if (!root->left && !root->right)
    {
        if (root->val > val)
            root->left = newnode;
        else
            root->right = newnode;
    }
    else if (root->val < val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}
int main()
{
   TreeNode *root=new TreeNode(6);
   root->insert();
   root=insertIntoBST(root,5);
   root->printTree(); 
}