#include <iostream>
#include "tree.h"
using namespace std;
int height(treeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    cout << "height of given tree is " << height(root);
}