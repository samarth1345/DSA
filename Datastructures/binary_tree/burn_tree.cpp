#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:in this we will need to traverse radially so we will need to mark
//parent pointers in map,and then we will use visited map to traverse
//and a queue to burn nodes.
int solve(treeNode<int> *root, map<treeNode<int>*,treeNode<int>*> m)
{
    unordered_map<treeNode<int> *, bool> vis;
    queue<treeNode<int> *> levelorder;
    int ans=0;
    bool flag;
    levelorder.push(root);
    vis[root]=true;
    while (!levelorder.empty())
    {
        int size = levelorder.size();
        flag=false;
        for (int i = 1; i <= size; i++)
        {
            treeNode<int> *node=levelorder.front();

            if (!vis[node->left] && (node->left != NULL))
            {
                flag=flag|true;
                levelorder.push(node->left); vis[node->left]=true;        
            }
            if (!vis[node->right] && (node->right != NULL))
            {
                flag=flag|true;
                levelorder.push(node->right); vis[node->right]=true;
            }
            if (!vis[m[node]] && (m[node] != NULL))
            {
                flag=flag|true;
                levelorder.push(m[node]); vis[m[node]]=true;
            }
            levelorder.pop();
        }
        if(flag)
        ans++;
    }
    return ans;
}
int burntree(treeNode<int> *root,treeNode<int> *toburn)
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
    return solve(toburn,m);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    cout<<burntree(root,root->left->right);
}