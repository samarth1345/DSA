#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:we use iterative inorder traversal beacuse in inorder bst is 
//simply a sorted array so we use that fact
int kthSmallest(TreeNode *root, int k)
{
    if (!root)
        return -1;
    int count = 0;
    stack<TreeNode *> Stack;
    Stack.push(root);
    TreeNode *node = root->left;
    while (1)
    {
        if (node)
        {
            Stack.push(node);
            node = node->left;
        }
        else
        {
            if (Stack.empty())
                break;
            TreeNode *temp = Stack.top();
            Stack.pop();
            count++;
            if (count == k)
                return temp->val;
            node = temp->right;
        }
    }
    return -1;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->insert();
    cout << kthSmallest(root, 3);
}