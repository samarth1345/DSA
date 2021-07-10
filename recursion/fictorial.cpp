#include<bits/stdc++.h>
using namespace std;
int fictorial(int n)   //hypothesis
{
    if(n==1)     //base condition
    {
        return 1;
    }
    return n*fictorial(n-1);    //n-->induction  fictorial(n-1)-->hypothesis
}
int main()
{
    int n;
    cin>>n;
    cout<<fictorial(n);
}