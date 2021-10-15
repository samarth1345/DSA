#include<iostream>
#include"tree.h"
//sum of nodes
int sumofnodes(tree<int> *obj)
{
    int sum = obj->data;
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        sum += sumofnodes(obj->subnodes[i]);
    }
    return sum;
}
int main()
{
    tree<int> *root = new tree<int>(1);
    root->insertTree(root);
    cout << sumofnodes(root);
}