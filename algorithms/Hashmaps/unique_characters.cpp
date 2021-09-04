#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;
string unique(string ip)
{
    unordered_map<char,bool> map;
    string ans="";
    int i=0;
    while(ip[i] != '\0')
    {
        if(map[ip[i]] != true)
        {
            ans+=ip.substr(i,1);
            map[ip[i]]=true;
        }
        i++;
    }
    return ans;
}
int main()
{
    string ip;
    cin>>ip;
    cout<<unique(ip);
}