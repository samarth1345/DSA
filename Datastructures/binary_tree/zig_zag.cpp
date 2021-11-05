#include <iostream>
#include<vector>
#include<algorithm>
#include "tree.h"
using namespace std;
void printzigzag(vector<vector<int>> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        vector<int> temp=arr[i];
        if(i%2!=0)
        reverse(temp.begin(),temp.end());
        for(int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
}
//done using level order traversal
void zig_zag(treeNode<int> *root)
{
    queue<treeNode<int> *> q;
    vector<vector<int>> arr;
    q.push(root);
    q.push(NULL);
    while(!q.empty() && q.front()!=NULL)
    {
        vector<int> temp;
        while(!q.empty() && q.front()!=NULL)
        {
            temp.push_back(q.front()->data);
            if(q.front()->left!=NULL)   q.push(q.front()->left);
            if(q.front()->right!=NULL)  q.push(q.front()->right);
            q.pop();
        }
        q.pop();
        q.push(NULL);
        arr.push_back(temp);
    }
    printzigzag(arr);
}
int main()
{
    treeNode<int> *root = new treeNode<int>(5);
    root->insert();
    zig_zag(root);
}