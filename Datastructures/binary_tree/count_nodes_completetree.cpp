#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//complete binary tree is a BT which doesn't have all nodes at last level i.e
//it shoud have 1,2 or more less nodes at last level and all nodes at last level should be
//maximum towards left(basically no voids starting from left)
int leftheight(treeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + leftheight(root->left);
}
int rightheight(treeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + rightheight(root->right);
}
//logic: we will compare height of left and right subtree(only for complete 
//binary tree) if it is same
//we can just use formula 2^n-1(n=height) to calculate nodes instead of traversing the nodes
//if they are not same then we will move left and right, and again check
int countNodes(treeNode<int> *root)
{
    int left = leftheight(root);
    int right = rightheight(root);
    if (left == right)
        return pow(2, left) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    cout<<countNodes(root);
}