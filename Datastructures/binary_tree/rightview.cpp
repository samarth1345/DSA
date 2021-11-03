#include <iostream>
#include "tree.h"
using namespace std;
void rightSideView(treeNode<int> *root,int& depth,int depth_new)
{
    //base case
    if(!root)
    return;

    //"depth" is depth till which we have traversed and find right side view
    //"depth_new" is depth of current node 
    if(depth_new>=depth)
    {
        cout<<root->data<<" ";
        depth++;
    }
    //go to right child of every node first
    rightSideView(root->right,depth,depth_new+1);
    rightSideView(root->left,depth,depth_new+1);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    vector<int> ans;
    int depth=0;
    rightSideView(root,depth,0);
}