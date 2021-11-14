#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:the only problem in this question is that we can traverse downwards and
//not upwards so to solve that problem we need to know the parent of every node
//which we can do by doing level order traversal and storing parent of very 
//child in map and then we can start traversing from target node in three directions
void solve(treeNode<int> *root, map<treeNode<int> *, treeNode<int> *> m, unordered_map<treeNode<int> *, bool> &vis, int dis, int k, vector<int> &ans)
{
    vis[root] = true;
    if (dis == k)
    {
        ans.push_back(root->data);
        return;
    }
    if (!root)
    {
        return;
    }
    //traversing in three directions
    if (!vis[root->left] && (root->left != NULL))
        solve(root->left, m, vis, dis + 1, k, ans);
    if (!vis[root->right] && (root->right != NULL))
        solve(root->right, m, vis, dis + 1, k, ans);
    if (!vis[m[root]] && (m[root] != NULL))
        solve(m[root], m, vis, dis + 1, k, ans);
}
vector<int> distanceK(treeNode<int> *root, treeNode<int> *target, int k)
{
    queue<treeNode<int> *> q;
    map<treeNode<int> *, treeNode<int> *> m;
    m[root] = NULL;
    q.push(root);
    while (!q.empty())
    {
        treeNode<int> *temp = q.front();
        if (temp->left)
        {
            q.push(temp->left);
            m[temp->left] = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            m[temp->right] = temp;
        }
        q.pop();
    }
    vector<int> ans;
    unordered_map<treeNode<int> *, bool> vis;
    solve(target, m, vis, 0, k, ans);
    return ans;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
}