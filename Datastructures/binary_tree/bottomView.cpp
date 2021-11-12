#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//this is also type of line traversal but we have to
//store the last element in every line
vector<int> bottomView(treeNode<int> *root)
{
    vector<int> ans;
    queue<pair<treeNode<int> *, int>> q;
    map<int, int> map;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<treeNode<int> *, int> temp = q.front();
        //we have to store the last element in a line,by this way even if key is present
        //we will update and at end we will have the last element in that line
        map[temp.second]=temp.first->data;
        if (temp.first->left)
            q.push({temp.first->left, temp.second - 1}); //left of root is seen as -1 of current line eg.root=1 left=1-1=0
        if (temp.first->right)
            q.push({temp.first->right, temp.second + 1}); //right of root is seen as +1 of current line eg.root=1 right=1+1=2
        q.pop();
    }
    for (auto i : map)
        ans.push_back(i.second);

    return ans;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    vector<int> ans = bottomView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}