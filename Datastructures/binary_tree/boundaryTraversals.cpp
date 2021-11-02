//boundary traversals : anticlockwise direction
#include <iostream>
#include<vector>
#include<algorithm>
#include "tree.h"
using namespace std;
void addforme(vector<int> temp,vector<int> &ans)
{
    for(int i=0;i<temp.size();i++)
    {
        ans.push_back(temp[i]);
    }
}
////to add left boundary nodes
void addleft(treeNode<int> *root,vector<int> &t)
{
    treeNode<int> *temp=root;
    while(temp && (temp->right || temp->left))
    {
        t.push_back(temp->data);
        if(!temp->left)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
}
//to add right boundary nodes
void addright(treeNode<int> *root,vector<int> &t)
{
    treeNode<int> *temp=root;
    vector<int> s;
    while(temp && (temp->right || temp->left))
    {
        s.push_back(temp->data);
        if(!temp->right)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    reverse(s.begin(),s.end());
    addforme(s,t);
}
//to add leaf nodes
void addleaves(treeNode<int> *root,vector<int> &temp)
{
    if(!root || (!root->right && !root->left))
    {
        if(root)
        temp.push_back(root->data);

        return;
    }
    addleaves(root->left,temp);
    addleaves(root->right,temp);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    root->printTree();
    vector<int> ans,temp;
    addleft(root,ans);
    addleaves(root,ans);
    addright(root->right,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}