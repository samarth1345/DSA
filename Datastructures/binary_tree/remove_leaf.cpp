#include <iostream>
#include "tree.h"
using namespace std;
bool removeleaf(treeNode<int> *root)
{
    if(root==NULL || (root->left == NULL && root->right==NULL))
    {
        return true;
    }
    if(removeleaf(root->left))
    root->left=NULL;
    if(removeleaf(root->right))
    root->right=NULL;

    return false;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    root->printTree();
    removeleaf(root);
    root->printTree();
}