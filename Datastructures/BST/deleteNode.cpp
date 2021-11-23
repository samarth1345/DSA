#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
TreeNode *getrightNode(TreeNode *root)
{
    if (!root)
        return NULL;
    if (!root->left)
        return root;
    return getrightNode(root->right);
}
TreeNode *getleftNode(TreeNode *root)
{
    if (!root)
        return NULL;
    if (!root->left)
        return root;
    return getleftNode(root->left);
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    TreeNode *curr = root, *prev = NULL;
    while (curr && curr->val != key)
    {
        prev = curr;
        if (curr->val > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (curr)
    {
        TreeNode *newnode = NULL, *toadd = NULL;
        if (curr->right)
        {
            newnode = getleftNode(curr->right);
            if (newnode)
                newnode->left = curr->left;
            toadd = curr->right;
        }
        else if (curr->left)
        {
            newnode = getrightNode(curr->left);
            if (newnode)
                newnode->right = curr->right;
            toadd = curr->left;
        }
        if (prev && prev->val < curr->val)
        {
            prev->right = toadd;
        }
        else if (prev && prev->val > curr->val)
        {
            prev->left = toadd;
        }
        else
        {
            return toadd;
        }
    }
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->insert();
    root = deleteNode(root, 3);
    root->printTree();
}