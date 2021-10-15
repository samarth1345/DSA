#include<iostream>
#include"tree.h"
using namespace std;
int main()
{
    treeNode<int> *root=new treeNode<int>(1);
    root->insert();
    root->printTree();
}