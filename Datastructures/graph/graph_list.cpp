#include<bits/stdc++.h>
#include"graph_list.h"
using namespace std;
int main()
{
    graph *obj=new graph(5);
    obj->input(1,4);
    obj->input(1,2);
    obj->input(1,5);
    obj->input(2,3);
    obj->input(2,5);
    obj->input(4,1);
    obj->input(3,5);
    obj->input(5,4);
    obj->print();
}