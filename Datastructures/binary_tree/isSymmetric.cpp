//Given the root of a binary tree, check whether it is a mirror of itself 
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//we have to just traverse with any technique 
//and we will keep on checking for symmetry
bool solve(treeNode<int> *l, treeNode<int> *r)
{
    if (!l || !r)
    {
        if (!l && !r)
            return true;
        return false;
    }
    //we are comapring left and right nodes of root 
    //and then we are calling on left node's left and right node's right and vice versa
    //to see mirror image 
    return (l->data == r->data) & solve(l->left, r->right) & solve(l->right, r->left);
}
//this function is just because we can't ask for root's left and right from user
bool isSymmetric(treeNode<int> *root)
{
    if (!root)
        return true;
    return solve(root->left, root->right);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    if(isSymmetric(root))
    cout<<"symmetric"<<endl;
    else
    cout<<"not symmetric"<<endl;
}