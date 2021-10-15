#include <iostream>
#include "tree.h"
using namespace std;
//count no. of nodes
int countnodes(tree<int> *obj)
{
    int count = 1;
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        count += countnodes(obj->subnodes[i]);
    }
    return count;
}
int main()
{
    tree<int> *root = new tree<int>(1);
    root->insertTree(root);
    cout << countnodes(root);
}