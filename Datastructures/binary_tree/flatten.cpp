#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:just ask recursion to flatten left and right subtree,
//and we just want last node of flattened left subtree.
//now we will put root of left subtree in right of our root
//and last node of left subtree will have root of right subtree.
treeNode<int> *findlastnode(treeNode<int> *root)
{
    if (!root)
        return NULL;
    if (!root->left && !root->right)
        return root;
    return findlastnode(root->right);
}
void flatten(treeNode<int> *root)
{
    if (!root)
        return;
    //flatten the left subtree 
    flatten(root->left);
    //last node of flattened left subtree
    treeNode<int> *temp = findlastnode(root->left);
    //flatten the right subtree
    flatten(root->right);
    if (temp)
        temp->right = root->right;
    if (root->left)
        root->right = root->left;
    root->left = NULL;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    flatten(root);
    root->printTree();
}