#include <iostream>
#include "tree.h"
using namespace std;
void replaceAtdepth(tree<int> *obj, int d)
{
    obj->data=d;
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        replaceAtdepth(obj->subnodes[i], d+1);
    }
}
int main()
{
    tree<int> *obj = new tree<int>(1);
    obj->insertTree(obj);
    replaceAtdepth(obj,1);
    obj->printTree(obj);
}