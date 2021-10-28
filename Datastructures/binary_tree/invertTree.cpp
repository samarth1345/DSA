#include <iostream>
#include "tree.h"
using namespace std;
treeNode<int> *invertTree(treeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    treeNode<int> *new_left = invertTree(root->left);
    treeNode<int> *new_right = invertTree(root->right);
    root->left = new_right;
    root->right = new_left;
    return root;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    root->printTree();
    root=invertTree(root);
    root->printTree();
}