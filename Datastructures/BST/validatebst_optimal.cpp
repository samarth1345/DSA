#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
bool solve(TreeNode *root, long lower, long upper)
{
    if (!root)
        return true;
    if (root->val > lower && root->val < upper)
    {
        return solve(root->left, lower, root->val) & solve(root->right, root->val, upper);
    }
    return false;
}
int main()
{
    TreeNode *root=new TreeNode(1);
    root->insert();
    cout<<solve(root,LONG_MIN,LONG_MAX);
}