#include <iostream>
#include "tree.h"
using namespace std;
int solve(treeNode<int> *node)
{
    if (!node)
    {
        return 0;
    }
    int left_sum = solve(node->left);
    int right_sum = solve(node->right);
    int total = left_sum + right_sum + node->data;
    node->data = left_sum + right_sum;
    return total;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    root->printTree();
    solve(root);
    root->printTree();
}