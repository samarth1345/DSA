#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
int sumOfLeftLeaves(treeNode<int> *root)
{
    if (!root)
        return 0;
    if (root->left)
    {
        //checking if it's left is a leaf
        if (!root->left->left && !root->left->right)
            return root->left->data + sumOfLeftLeaves(root->right);
        else
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
    //as root's left doesn't have a left node->checked in if condition above 
    //so we are just calling on root->right 
    return sumOfLeftLeaves(root->right);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    cout<<sumOfLeftLeaves(root);
}