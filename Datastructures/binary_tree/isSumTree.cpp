#include <iostream>
#include "tree.h"
using namespace std;
int solve(treeNode<int> *root)
{
    if (!root)
        return 0;
    int left_sum = solve(root->left);
    int right_sum = solve(root->right);
    if (!root->left && !root->right)
        return root->data;

    else if (left_sum + right_sum == root->data && left_sum != -1 && right_sum != -1)
        return root->data + left_sum + right_sum;

    return -1;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(3);
    root->insert();
    if(solve(root)!=-1)
    cout<<"Sum tree"<<endl;
    else
    cout<<"Not Sum tree"<<endl;
}