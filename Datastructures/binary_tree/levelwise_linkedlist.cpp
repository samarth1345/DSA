#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;
void insert(vector<int> &arr, vector<int> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        arr.push_back(temp[i]);
    }
}
vector<vector<int>> insertAtlevels(vector<vector<int>> leftarr, vector<vector<int>> rightarr, int data)
{
    vector<vector<int>> ans;
    //data of root at top
    ans.push_back({data});
    if (leftarr.size() == 0 && rightarr.size() == 0)
    {
        return ans;
    }
    //if left node has no further levels we just merge levels of rightnode
    else if (leftarr.size() == 0)
    {
        for (int i = 0; i < rightarr.size(); i++)
        {
            ans.push_back(rightarr[i]);
        }
    }
    //if right node has no further levels we just merge levels of leftnode
    else if (rightarr.size() == 0)
    {
        for (int i = 0; i < leftarr.size(); i++)
        {
            ans.push_back(leftarr[i]);
        }
    }
    else
    {
        //merging levels of left and right node till same level
        int size = min(rightarr.size(), leftarr.size());
        for (int i = 0; i < size; i++)
        {
            vector<int> temp;
            //storing at same level from left node to right node
            insert(temp, leftarr[i]);
            insert(temp, rightarr[i]);
            ans.push_back(temp);
        }
        //if left node had more levels than rightnode
        if (size < leftarr.size())
        {
            for (int i = size; i < leftarr.size(); i++)
            {
                ans.push_back(leftarr[i]);
            }
        }
        //if right node had more levels than left node
        else if(size < rightarr.size())
        {
            for (int i = size; i < rightarr.size(); i++)
            {
                ans.push_back(rightarr[i]);
            }
        }
    }
    //return merged array
    return ans;
}
vector<vector<int>> levelWiseLL(treeNode<int> *root)
{
    vector<vector<int>> arr;
    if (root == NULL)
    {
        return arr;
    }
    vector<vector<int>> leftarr = levelWiseLL(root->left);
    vector<vector<int>> rightarr = levelWiseLL(root->right);
    //fucntion to merge arrays received from left,right node with root 
    arr = insertAtlevels(leftarr, rightarr, root->data);
    return arr;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(8);
    root->insert();
    root->printTree();
    vector<vector<int>> arr = levelWiseLL(root);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}