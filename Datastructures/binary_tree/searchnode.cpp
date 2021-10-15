#include <iostream>
#include "tree.h"
using namespace std;
bool search(treeNode<int> *root, int key)
{
    if (root != NULL)
    {
        bool ans = false;
        if (root->data == key)
        {
            ans = true;
        }
        return ans | search(root->left, key) | search(root->right, key);
    }
    return false;
}
int main()
{
    treeNode<int> *root = new treeNode<int>(1);
    root->insert();
    cout << search(root, 4);
}