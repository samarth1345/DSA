#include<iostream>
#include"tree.h"
using namespace std;
//node with max data
int maxnode(tree<int> *obj)
{
    int ans = obj->data;
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        int temp = maxnode(obj->subnodes[i]);
        ans = max(ans, temp);
    }
    return ans;
}
int main()
{
    tree<int> *root = new tree<int>(1);
    root->insertTree(root);
    cout << maxnode(root);
}