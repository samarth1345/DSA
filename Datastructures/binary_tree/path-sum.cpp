//Given the root of a binary tree and an integer targetSum, 
//return true if the tree has a root-to-leaf path 
//such that adding up all the values along the path equals targetSum.
#include <iostream>
#include "tree.h"
using namespace std;
bool hasPathSum(treeNode<int> *root, int targetSum)
{
    if (root == NULL)
    {
        return false;
    }
    int currsum = targetSum - root->data;
    if (!root->left && !root->right)
    {
        if (currsum == 0)
            return true;
        return false;
    }
    return hasPathSum(root->left, currsum) | hasPathSum(root->right, currsum);
}
int main()
{
    treeNode<int> *root = NULL;
    root->insert();
    cout << hasPathSum(root, 0);
}