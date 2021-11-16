#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//this is just a threaded traversal where we make links to backtrack 
//which recursion was taking care before
//cases to handle
//case 1:when root does'nt have a left node , we just add it to vector 
//and move right
//csse 2:when root has a left node, this is when we have to make links to come back
//as we do in preorder traversal(root->left->right),we have to keep moving right until the last 
//node is leaf or it has it's right pointer to subtree's parent i.e see ELSE case
vector<int> morris(treeNode<int> *root)
{
    vector<int> ans;
    treeNode<int> *curr=root;
    while(curr)
    {
        if(!curr->left)
        {
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else
        {
            treeNode<int> *next=curr->left;
            //move right until condition is met
            while(next->right && next->right!=curr)
            {
                next=next->right;
            }
            //if next->right is NULL,we have to make the link to comeback and ALSO 
            //this is preorder we will add that parent of this subtree as this whole
            //subtree has been traversed
            if(! next->right)
            {
                next->right=curr;
                ans.push_back(curr->data);
                curr=curr->left;
            }
            //else we have to break the connection and move to right subtree now as left subtree has been
            //traversed
            else
            {
                next->right=NULL;
                curr=curr->right;
            }
        }
    }
    return ans;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    vector<int> ans=morris(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}