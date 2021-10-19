#include <iostream>
#include "tree.h"
using namespace std;
pair<int, int> getMinAndMax(treeNode<int> *root)
{
    pair<int, int> ans, leftnode, rightnode;
    if (root == NULL)
    {
        ans.first = -1;          ans.second = -1;
        return ans;
    }
    leftnode = getMinAndMax(root->left);
    rightnode = getMinAndMax(root->right);
    if (leftnode.first == -1)
    {
        leftnode.first=root->data; leftnode.second=root->data;
    }
    if (rightnode.first == -1)
    {
        rightnode.first=root->data; rightnode.second=root->data;
    }
    ans.first= min(min(leftnode.first, rightnode.first), root->data);
    ans.second = max(max(leftnode.second, rightnode.second), root->data);
    return ans;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    pair<int, int> ans = getMinAndMax(root);
    cout <<"min="<< ans.first << " max=" << ans.second;
}