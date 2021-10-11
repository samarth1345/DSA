#include <iostream>
#include<queue>
#include "tree.h"
using namespace std;
//2 2 3 2 4 5 2 6 7 0 0 0 0
int main()
{
    tree<int> *obj = new tree<int>(1);
    obj->insertTree(obj);
    obj->printTree(obj);
}