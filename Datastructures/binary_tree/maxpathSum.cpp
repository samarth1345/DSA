#include <iostream>
#include "tree.h"
using namespace std;
int solve(treeNode<int> *root, int &maxi)
{
    if (!root)
        return 0;
    int leftsum, rightsum;
    leftsum = max(0, solve(root->left, maxi));
    rightsum = max(0, solve(root->right, maxi));
    maxi = max(maxi, (leftsum + rightsum + root->data));
    return root->data + max(leftsum, rightsum);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    root->printTree();
    int maxi=INT_MIN;
    cout<<max(solve(root,maxi),maxi);
}