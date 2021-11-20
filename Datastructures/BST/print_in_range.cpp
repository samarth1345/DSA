#include <iostream>
#include "tree.h"
using namespace std;
//2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    if (!root)
        return ans;
    if (root->val >= low && root->val <= high)
        ans = root->val;
    if (root->val > low)
        ans += rangeSumBST(root->left, low, high);
    if (root->val < high)
        ans += rangeSumBST(root->right, low, high);
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->insert();
    cout<<rangeSumBST(root, 1, 4);
}