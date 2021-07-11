#include<bits/stdc++.h>
using namespace std;
void hanoi(char source,char helper,char dest,int num)           //hypothesis
{ 
    if(num==1)                                                 //base condition
    {
        cout<<"Move disk "<<num<<" from "<<source<<" to "<<dest<<endl;
        return;
    }
    hanoi(source,dest,helper,num-1);                             //hypothesis
    cout<<"Move disk "<<num<<" from "<<source<<" to "<<dest<<endl;      //induction
    hanoi(helper,source,dest,num-1); 
}
int main()
{
    int num;
    cin>>num;
    hanoi('s','h','d',num);
}