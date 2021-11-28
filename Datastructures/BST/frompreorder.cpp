#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:In BST we don't need inorder and preorder both,we can build a tree from 
//preorder due to property of BST,in preorder traversal we get to know left subtree
//of root because all the elements of left are smaller than root and vice versa for 
//right subtree
vector<int> slicing(vector<int> arr, int X, int Y)
{
    vector<int> vector(arr.begin() + X, arr.begin() + Y + 1);
    return vector;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *newnode = NULL, *leftNode = NULL, *rightNode = NULL;

    if (preorder.empty())
        return newnode;

    int head = preorder[0], size = preorder.size();
    newnode = new TreeNode(head);

    int left = 0;
    while (left < size && preorder[left] <= head)
        left++;

    if (left > 0)
    {
        vector<int> lefttree = slicing(preorder, 1, left - 1);
        leftNode = bstFromPreorder(lefttree);
    }
    if (size - left > 0)
    {
        vector<int> righttree = slicing(preorder, left, size - 1);
        rightNode = bstFromPreorder(righttree);
    }
    newnode->left = leftNode;
    newnode->right = rightNode;

    return newnode;
}
int main()
{
    TreeNode *root = NULL;
    int n;
    cin >> n;
    vector<int> preorder;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        preorder.push_back(temp);
    }
    root = bstFromPreorder(preorder);
    root->printTree();
}