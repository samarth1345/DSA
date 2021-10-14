#include <iostream>
#include "tree.h"
using namespace std;
//we are returning max child sum but if we want to return
//node as well we can use pair in vector to store node as well
//ALSO, we are not doing calculation of maximum part in fun. itself
/*void childsum(tree<int> *obj,vector<int>& child)
{
    int sum=obj->data;
    for(int i=0;i<obj->subnodes.size();i++)
    {
        sum+=obj->subnodes[i]->data;
        childsum(obj->subnodes[i],child);
    }
    child.push_back(sum);
}*/

//optimised solution in O(1) space
//logic: calculate child sum for root and compare with its subnode's child sum
pair<int, int> childsum(tree<int> *obj)
{
    pair<int, int> ans;
    //calculation for root part
    int sum = obj->data;
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        sum += obj->subnodes[i]->data;
    }
    ans.first = obj->data;
    ans.second = sum;
    //calculations for subnodes
    for (int i = 0; i < obj->subnodes.size(); i++)
    {
        pair<int, int> temp= childsum(obj->subnodes[i]);
        if(ans.second<temp.second)
        {
            ans=temp;
        }
    }
    return ans;
}
int main()
{
    tree<int> *obj = new tree<int>(1);
    obj->insertTree(obj);
    vector<int> sum;
    pair<int,int> ans=childsum(obj);
    cout<<"node with max child sum is "<<ans.first<<endl;
}