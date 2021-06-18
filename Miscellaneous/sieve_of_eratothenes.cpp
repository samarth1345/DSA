/*finding prime numbers in a given range*/
#include<bits/stdc++.h>
using namespace std;
void prime(int num)
{
    vector<int> arr(num,0);     /*initialising arr with 0*/
    for(int i=2;i<=num;i++)
    {
        if(arr[i]==0)
        for(int j=i*i;j<=num;j+=i)
        {
            arr[j]=1;      /*occupying non-prime indexes with 1*/
        }
    }
    cout<<"0 1 ";
    for(int i=2;i<=num;i++)
    {
        if(arr[i]==0)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int num;
    cin>>num;
    prime(num);
}