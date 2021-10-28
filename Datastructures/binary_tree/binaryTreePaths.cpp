#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
void makefinal(vector<string> temp, vector<string> &ans, string toadd)
{
    for (int i = 0; i < temp.size(); i++)
    {
        string s = temp[i];
        s.insert(0, toadd + "->");
        ans.push_back(s);
    }
}
vector<string> binaryTreePaths(treeNode<int> *root)
{
    vector<string> ans;
    if (root == NULL)
    {
        return ans;
    }
    if (!root->left && !root->right)
    {
        ans.push_back(to_string(root->data));
        return ans;
    }
    vector<string> left = binaryTreePaths(root->left);
    vector<string> right = binaryTreePaths(root->right);
    string toadd = to_string(root->data);
    makefinal(left, ans, toadd);
    makefinal(right, ans, toadd);
    return ans;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    vector<string> ans=binaryTreePaths(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}