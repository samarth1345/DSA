#include <iostream>
#include "tree.h"
using namespace std;
bool solve(treeNode<int> *root, int depth, int &final)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
    {
        if (final > 0)
            return depth == final;
        else
        {
            final = depth;
            return true;
        }
    }
    return solve(root->right, depth + 1, final) & solve(root->left, depth + 1, final);
}
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    int final=0;
    cout<<solve(root,0,final);
}