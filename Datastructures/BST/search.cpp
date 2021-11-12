#include <iostream>
#include "tree.h"
using namespace std;
TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
    {
        return NULL;
    }
    if (root->val == val)
        return root;
    TreeNode *temp;
    if (val < root->val)
        temp = root->left;
    if (val > root->val)
        temp = root->right;
    return searchBST(temp, val);
}
int main()
{
    TreeNode *root=new TreeNode(4);
    root->insert();
    TreeNode *ans=searchBST(root,10);
    if(!ans)
    cout<<"-1";
    else
    cout<<ans->val;
}