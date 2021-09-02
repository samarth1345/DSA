#include<iostream>
#include"hashmap.h"
using namespace std;
int main()
{
    ourmap<int> map;
    map.insert("abc",1);
    map.insert("cdk",2);
    map.insert("cdg",2);
    map.insert("samarth",2);
    cout<<map.at("abc")<<endl;
    cout<<map.at("cdk")<<endl;
    cout<<map.at("cdg")<<endl;
    cout<<map.at("samarth")<<endl;
    cout<<map.getsize();
}