#include<iostream>
using namespace std;
int checkbit(int x,int pos)
{
    if(x&(1<<pos))
    return 1;
    else
    return 0;
}
int repeat(int arr[],int n)
{
    int check[32]={0};
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(checkbit(arr[j],i))
            check[i]++;
        }
    }
    int sum=0;
    for(int i=0;i<32;i++)
    {
        if(check[i]!=0)
        {
        if((check[i]%3!=0))
        {
            sum=sum^(1<<i);
        }
        }

    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<repeat(arr,n)<<endl;
    return 0;
}