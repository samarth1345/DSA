#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:we will check at every node that if we have found the 
//both nodes, as soon as we find them we just return the root 
treeNode<int> *lowestCommonAncestor(treeNode<int> *root, treeNode<int> *p, treeNode<int> *q)
{
    treeNode<int> *ans = NULL;
    if (!root)
        return ans;
    //if root is itself one of the required nodes
    if (root == p || root == q)
        ans = root;
    //left and right calls to see if there is required node's in left or 
    //right subtree    
    treeNode<int> *left = lowestCommonAncestor(root->left, p, q);
    treeNode<int> *right = lowestCommonAncestor(root->right, p, q);
    //if there are required node's present in left or right subtree or parent itself
    //we just return root because that is the LCA
    if (ans && left || left && right || ans && right)
        return root;
    //now only one or none has value other than null and we will
    //just return that
    if (left)
        ans = left;
    else if (right)
        ans = right;    
    return ans;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    treeNode<int> *ans=lowestCommonAncestor(root,NULL,NULL);
    cout<<ans->data;
}