//naive solution for finding if tree is balanced or not
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
bool isBalanced(treeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    return (abs(height(root->left) - height(root->right)) <= 1) & isBalanced(root->left) & isBalanced(root->right);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(5);
    root->insert();
    root->printTree();
    if (isBalanced(root))
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "not balanced" << endl;
    }
}