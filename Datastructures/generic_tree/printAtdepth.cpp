#include<iostream>
#include"tree.h"
using namespace std;
//replace nodes data with depth
void printAtdepth(tree<int> *obj, int d)
{
    if (d == 0)
    {
        cout << obj->data << " ";
        return;
    }
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        printAtdepth(obj->subnodes[i], d - 1);
    }
}
int main()
{
    tree<int> *root = new tree<int>(1);
    root->insertTree(root);
    printAtdepth(root,2);
}