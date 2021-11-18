#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//just use level order traversal and in place of NULL just add # in string
string serialize(treeNode<int> *root)
{
    string ans = "";
    if (!root)
        return ans;
    ans += to_string(root->data);
    queue<treeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        treeNode<int> *temp = q.front();
        if (temp->left)
        {
            ans += ("," + to_string(temp->left->data));
            q.push(temp->left);
        }
        else
            ans += ",#";
        if (temp->right)
        {
            ans += ("," + to_string(temp->right->data));
            q.push(temp->right);
        }
        else
            ans += ",#";
        q.pop();
    }
    return ans;
}
// Decodes your encoded data to tree.
treeNode<int> *deserialize(string data)
{
    if (data.empty())
        return NULL;
    //method to traverse string  
    stringstream s(data);
    string str;
    //uses "," as key and returns string after ","
    getline(s, str, ',');

    treeNode<int> *root = new treeNode<int>(stoi(str));
    queue<treeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        treeNode<int> *left = NULL, *right = NULL, *temp = q.front();
        getline(s, str, ',');
        //if returned string is not hash means we need to add it to tree
        if (str != "#")
        {
            left = new treeNode<int>(stoi(str));
            q.push(left);
        }
        temp->left = left;

        getline(s, str, ',');
        //if returned string is not hash means we need to add it to tree
        if (str != "#")
        {
            right = new treeNode<int>(stoi(str));
            q.push(right);
        }
        temp->right = right;

        q.pop();
    }
    return root;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    string data = serialize(root);
    treeNode<int> *temp = deserialize(data);
    temp->printTree();
}