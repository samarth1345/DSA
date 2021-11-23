#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:if value of root is greater than min of p and q, and less than max of p and q
//then that root is LCA 
TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
{
    if (!root)
        return NULL;
    int r_v = root->val, Min, Max;
    Min = min(p, q);
    Max = max(p, q);
    if (r_v >= Min && r_v <= Max)
        return root;

    else if (r_v > Min && r_v > Max)
        return lowestCommonAncestor(root->left, p, q);

    return lowestCommonAncestor(root->right, p, q);
}
int main()
{
    TreeNode *root=new TreeNode(6);
    root->insert();
    TreeNode *ans=lowestCommonAncestor(root,2,4);
    cout<<ans->val;
}