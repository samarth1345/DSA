#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
string solve(treeNode<int> *root,int val)
{
    string ans="";
    if(!root)
    return ans;
    //if val is found then we just return the same value 
    if(root->data ==  val)
    {
        ans=to_string(root->data);
        return ans;
    }
    //ask left and right node's to just return the path of node
    //if it is present
    string left=solve(root->left,val);
    string right=solve(root->right,val);
    //if there is a path from left
    if(!left.empty())
    ans=to_string(root->data)+"->"+left;
    //if there is a path from right
    else if(!right.empty())
    ans=to_string(root->data)+"->"+right;
    //returns empty string if no case is hit
    return ans;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    string ans=solve(root,4);
    if(ans.empty())
    cout<<"No path"<<endl;
    else
    cout<<ans;
}