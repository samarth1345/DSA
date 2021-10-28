//The minimum depth is the number of nodes along the shortest path 
//from the root node down to the nearest leaf node.
#include <iostream>
#include "tree.h"
using namespace std;
int minDepth(treeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    //case handling for if one of child Node is NULL
    if (!root->left || !root->right)
    {
        if (!root->left && !root->right)
        {
            return 1;
        }
        else if (!root->left)
        {
            return 1 + minDepth(root->right);
        }
        else
        {
            return 1 + minDepth(root->left);
        }
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    cout << "height of given tree is " << minDepth(root);
}