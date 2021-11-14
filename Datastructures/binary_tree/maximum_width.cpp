#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
//logic:we will use level order traversal and with node , we will also pass 
//index of that node which will be specific to the level's
//eg. for every level index will start from 0,1.... ans so on
//and to find width we just need the index of first and last node
int widthOfBinaryTree(treeNode<int> *root)
{
    queue<pair<treeNode<int> *, int>> q;
    int max_width = 0;
    q.push({root, 1});
    while (!q.empty())
    {
        int size = q.size();
        //this variable is to maintain 0 indexing or else if we don't start from 0
        //for every level it will lead to overflow and we use the index of first node
        //of that level 
        int minm = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            //this is the modified index of every node
            int crr = q.front().second - minm;
            if (i == 0)
                first = crr;
            if (i == size - 1)
                last = crr;
            if (q.front().first->left)
                q.push({q.front().first->left, (2 * crr) + 1});  //every left node is 2*parent+1
            if (q.front().first->right)
                q.push({q.front().first->right, (2 * crr) + 2});  //every right node is 2*parent+2
            q.pop();
        }
        max_width = max(max_width, last - first + 1);
    }
    return max_width;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    cout << widthOfBinaryTree(root);
}