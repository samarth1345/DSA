//first program using input/output method
//done using recursion tree
#include<bits/stdc++.h>
using namespace std;
void subset(string ip,string op,int& count)   
{
    //showing ouput when input lenght is zero acc. to tree
    if(ip.length()==0)
    {
        count++;
        cout<<op<<endl;
        return;
    }
    //initialsing two outputs coming from previous node: op1 op2
    string op1=op;           //first output without decisisve char
    string op2=op+ip[0];     //second output with decisive char
    ip.erase(0,1);           //erasing decisive input from input
    subset(ip,op1,count);
    subset(ip,op2,count);
}
int main()
{
    string ip;
    cin>>ip;
    int count=0;
    string op="";         //initialsing output as empty
    subset(ip,op,count);
    cout<<count;
}