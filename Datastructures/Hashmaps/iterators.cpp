#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> map;
    map["a"]=97;
    map["b"]=98;
    map["c"]=99;
    map["d"]=100;
    map["e"]=101;

    //begin function returns iterator to first pair stored in map
    //end function returns a value indicating end of map
    
    unordered_map<string, int>::iterator it=map.begin();
    while(it != map.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}