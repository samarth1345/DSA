#include<iostream>
#include"tree.h"
using namespace std;
//height of tree
int height(tree<int> *obj)
{
    int ans = 1;
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        int temp = 1;
        temp += height(obj->subnodes[i]);
        ans = max(ans, temp);
    }
    return ans;
}
int main()
{
    tree<int> *root = new tree<int>(1);
    root->insertTree(root);
    cout << height(root);
}