#include <iostream>
#include "tree.h"
using namespace std;
bool compare(tree<int> *obj1,tree<int>* obj2)
{
    bool ans=true;
    //compare data of nodes
    if(obj1->data != obj2->data)
    {
        ans=false;
    }
    for(int i=0;i<obj1->subnodes.size();i++)
    {
        //compare data for all subnodes
        ans=ans&compare(obj1->subnodes[i],obj2->subnodes[i]);
    }
    return ans;
}
int main()
{
    tree<int> *obj = new tree<int>(1);
    tree<int> *obj2 = new tree<int>(1);
    obj->insertTree(obj);
    obj2->insertTree(obj2);
    if(compare(obj,obj2))
    cout<<"Identical\n";
    else
    cout<<"Not identical\n";
}