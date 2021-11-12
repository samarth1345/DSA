#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//this is type of line traversal using map(not unordered) and queue
//first element in every line is seen as topview 
vector<int> topView(treeNode<int> *root)
{
    //Your code here
    vector<int> ans;
    queue <pair<treeNode<int>*,int>> q;
    map<int,int> map;
    q.push({root,0});
    while(!q.empty())
    {
        pair<treeNode<int>*,int> temp=q.front();
        //if current element is first one in that particular line 
        if(!map[temp.second])
        {
            map[temp.second]=temp.first->data;
        }
        if(temp.first->left)
        q.push({temp.first->left,temp.second - 1}); //left of root is seen as -1 of current line eg.root=1 left=1-1=0
        if(temp.first->right)
        q.push({temp.first->right,temp.second + 1});//right of root is seen as +1 of current line eg.root=1 right=1+1=2
        q.pop();
    }
    for(auto i:map)
    ans.push_back(i.second);

    return ans;
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    vector<int> ans=topView(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}