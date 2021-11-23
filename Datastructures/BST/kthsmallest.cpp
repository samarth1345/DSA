#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:we have to check no of nodes in left subtree of current node
//if it is equal to (k-1) i.e -1 because we have to include current node 
//also,if no of nodes are greater then k-1 we have to just move left
//because current is greater than whhat we need,if no of nodes are less we have
//to move rightand also decrement k.
int leftnodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + leftnodes(root->left) + leftnodes(root->right);
}
int kthSmallest(TreeNode *root, int k)
{
    if (!root)
        return 0;
    int Leftnodes = leftnodes(root->left);
    if (Leftnodes == k - 1)
        return root->val;
    else if (Leftnodes > k - 1)
        return kthSmallest(root->left, k);
    return kthSmallest(root->right, k - Leftnodes - 1);
}
int main()
{
    TreeNode *root=new TreeNode(2);
    root->insert();
    cout<<kthSmallest(root,3);
}