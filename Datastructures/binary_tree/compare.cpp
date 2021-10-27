#include <iostream>
#include "tree.h"
using namespace std;
bool isSameTree(treeNode<int> *obj1, treeNode<int> *obj2)
{
    if (obj1 == NULL || obj2 == NULL)
    {
        if (obj1 == obj2)
            return true;
        else
            return false;
    }
    return (obj1->data == obj2->data) & isSameTree(obj1->left, obj2->left) & isSameTree(obj1->right, obj2->right);
}
int main()
{
    treeNode<int> *obj1 = new treeNode<int>(1);
    treeNode<int> *obj2 = new treeNode<int>(1);
    obj1->insert();
    obj2->insert();
    if (isSameTree(obj1, obj2))
        cout << "Identical\n";
    else
        cout << "Not identical\n";
}