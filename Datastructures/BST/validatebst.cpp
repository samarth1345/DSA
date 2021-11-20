#include <bits/stdc++.h>+
#include "tree.h"
using namespace std;
//logic:we will get max value from left subtree and min value from right subtree 
//and comapre them with roots's data ,Also we will compare root's left data and 
//root's right data with root's data 
//note:this code works fine with almost all testcases except when value of data
//is close to INT_MIN and INT_MAX 
int MIN = INT_MIN;
int MAX = INT_MAX;
int minimum(TreeNode *root)
{
    if (!root)
        return MAX;
    return min(root->val, min(minimum(root->left), minimum(root->right)));
}
int maximum(TreeNode *root)
{
    if (!root)
        return MIN;
    return max(root->val, max(maximum(root->left), maximum(root->right)));
}
bool isValidBST(TreeNode *root)
{
    if (!root || !root->left && !root->right)
        return true;
    int right_min = minimum(root->right);
    int left_max = maximum(root->left);
    bool ans = (root->val < right_min) && (root->val > left_max) && isValidBST(root->left) && isValidBST(root->right);
    return ans;
}