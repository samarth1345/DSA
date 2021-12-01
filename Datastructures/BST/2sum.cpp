#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//this could have been easily done through O(N) space
//but we are going to use same concept as BST iterator were will 
//just store h(height) nodes but for both sides i.e one till leftmost
//node and other till rightmost node and add or remove nodes
//ccording to condition
bool findTarget(TreeNode *root, int k)
{
    TreeNode *temp1 = root, *temp2 = root;
    stack<TreeNode *> leftstack, rightstack;
    while (temp1)
    {
        leftstack.push(temp1);
        temp1 = temp1->left;
    }
    while (temp2)
    {
        rightstack.push(temp2);
        temp2 = temp2->right;
    }
    TreeNode *l = leftstack.top(), *r = rightstack.top();
    while (l->val < r->val)
    {
        if ((l->val + r->val) == k)
            return true;
        else if ((l->val + r->val) > k)
        {
            rightstack.pop();
            TreeNode *temp = r->left;
            while (temp)
            {
                rightstack.push(temp);
                temp = temp->right;
            }
        }
        else
        {
            leftstack.pop();
            TreeNode *temp = l->right;
            while (temp)
            {
                leftstack.push(temp);
                temp = temp->left;
            }
        }
        l = leftstack.top();
        r = rightstack.top();
    }
    return false;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->insert();
    cout << findTarget(root, 3);
}