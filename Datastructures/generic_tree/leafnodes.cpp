#include<iostream>
#include"tree.h"
using namespace std;
//no. of leaf nodes
int leafnodes(tree<int> *obj)
{
    if (obj->subnodes.size() == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        ans += leafnodes(obj->subnodes[i]);
    }
    return ans;
}
int main()
{
    tree<int> *root = new tree<int>(1);
    root->insertTree(root);
    cout << leafnodes(root);
}