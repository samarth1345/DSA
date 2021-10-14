#include <iostream>
#include "tree.h"
using namespace std;
//for storing largest and second largest of every node
class maxi
{
    public:
    int first,second;
};
//return second largest node in tree
maxi* second_largest(tree<int> *obj)
{
    maxi *obj_maxi=new maxi();
    obj_maxi->first=obj->data;
    obj_maxi->second=0;
    for(int i=0;i<obj->subnodes.size();i++)
    {
        maxi *temp=new maxi();
        temp=second_largest(obj->subnodes[i]);
        //comapring values of node and subnodes
        if(obj_maxi->first < temp->second)
        {
            obj_maxi=temp;
        }
        else
        {
            if(obj_maxi->first > temp->first)
            {
                obj_maxi->second=max(obj_maxi->second,temp->first);
            }
            else
            {
                obj_maxi->second=obj_maxi->first;
                obj_maxi->first=temp->first;
            }
        }
    }
    return obj_maxi;
}
int main()
{
    tree<int> *obj = new tree<int>(1);
    obj->insertTree(obj);
    maxi *ans=second_largest(obj);
    cout<<ans->second<<endl;
}