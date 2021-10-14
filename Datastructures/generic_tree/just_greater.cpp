#include <iostream>
#include "tree.h"
using namespace std;
int just_greater(tree<int>* obj,int n)
{
    int ans=0;
    if(obj->data>n)
    {
        ans=obj->data;
    }
    for(int i=0;i<obj->subnodes.size();i++)
    {
        int temp=just_greater(obj->subnodes[i],n);
        if(ans==0)
        {
            ans=temp;
        }
        else
        {
            ans=min(ans,temp);
        }
    }
    return ans;
}
int main()
{
    tree<int> *obj = new tree<int>(1);
    obj->insertTree(obj);
    cout<<just_greater(obj,2)<<endl;
}