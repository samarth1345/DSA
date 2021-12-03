#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
TreeNode *checkleft(TreeNode *root, int key)
{
    TreeNode *ans = NULL;
    if (!root)
        return ans;
    if (root->val > key)
        return root;
    ans = checkleft(root->left, key);
    if (!ans)
    ans = checkleft(root->right, key);
    return ans;
}
TreeNode *checkright(TreeNode *root, int key)
{
    TreeNode *ans = NULL;
    if (!root)
        return ans;
    if (root->val < key)
        return root;
    ans = checkright(root->left, key);
    if (!ans)
    ans = checkright(root->right, key);
    return ans;
}
void recoverTree(TreeNode *root)
{
    if (root)
    {
        TreeNode *leftval = checkleft(root->left, root->val);
        TreeNode *rightval = checkright(root->right, root->val);
        if (leftval)
        {
            int temp = root->val;
            root->val = leftval->val;
            leftval->val = temp;
            return;
        }
        else if (rightval)
        {
            int temp = root->val;
            root->val = rightval->val;
            rightval->val = temp;
            return;
        }
        recoverTree(root->left);
        recoverTree(root->right);
    }
}
int main()
{
    TreeNode *root=new TreeNode(1);
    root->insert();
    root->printTree();
    recoverTree(root);
    root->printTree();
}