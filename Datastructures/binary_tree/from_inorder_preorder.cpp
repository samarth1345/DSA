#include <iostream>
#include "tree.h"
using namespace std;
vector<int> slicing(vector<int> arr, int X, int Y)
{
    auto first = arr.begin() + X;
    auto last = arr.begin() + Y + 1;
    vector<int> vector(first, last);
    return vector;
}
treeNode<int> *construct(vector<int> inorder, vector<int> preorder, int size)
{
    if (size > 0)
    {
        int root_data = preorder[0];
        int left = 0;
        while (left<size && inorder[left] != root_data)
        {
            left++;
        }
        treeNode<int> *root = new treeNode<int>(root_data);
        treeNode<int> *leftnode=NULL;
        treeNode<int> *rightnode=NULL;
        if(left>0)
        leftnode = construct(slicing(inorder, 0, left - 1), slicing(preorder, 1, left), left);
        if((size-left-1) > 0)
        rightnode= construct(slicing(inorder, left + 1, size-1), slicing(preorder, 1 + left, size-1), size - left-1);
        root->left = leftnode;
        root->right = rightnode;
        return root;
    }
    return NULL;
}
int main()
{
    int size;
    cin >> size;
    vector<int> inorder, preorder;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        preorder.push_back(temp);
    }
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        inorder.push_back(temp);
    }
    treeNode<int> *newnode = construct(inorder, preorder, size);
    newnode->printTree();
}