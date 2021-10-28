#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
bool MirrorTree(treeNode<int> *root)
{
    queue<treeNode<int> *> q;
    vector<int> ans;
    if (root->left != NULL)
        q.push(root->left);
    if (root->right != NULL)
        q.push(root->right);
    int n=1; 
    while (!q.empty())
    {
        treeNode<int> *temp = q.front();
        ans.push_back(temp->data);
        if(n&1)
        {
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        else
        {
            if(temp->right)
            q.push(temp->right);
            if(temp->left)
            q.push(temp->left);
        }
        q.pop();
        n++;
    }
    /*for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }*/
    int k=1;
    int win;
    while(ans.size())
    {
        win=pow(2,k);
        if(ans.size()<win)
        return false;
        for(int i=0;i<win/2;i++)
        {
            if(ans[i]!=ans[i+win/2])
            {
                return false;
            }
        }
        ans.erase(ans.begin(),ans.begin()+win);
        k++;
    }
    return true;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    cout<<MirrorTree(root);
}