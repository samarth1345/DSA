#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
int sumOfLeftLeaves(treeNode<int> *root)
{
    if (!root)
        return 0;
    if (root->left)
    {
        if (!root->left->left && !root->left->right)
            return root->left->data + sumOfLeftLeaves(root->right);
        else
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->right);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    cout<<sumOfLeftLeaves(root);
}