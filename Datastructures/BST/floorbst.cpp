#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
int floor(TreeNode *root, int key)
{
    if (!root)
        return -1;

    if (root->val > key)
        return floor(root->left, key);
    else if(root->val < key)
    {
        int temp=floor(root->right,key);
        return temp!=-1?temp:root->val;
    }
    return root->val;
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->insert();
    int key;
    cin >> key;
    cout << floor(root, key);
}