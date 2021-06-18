#include<iostream>
using namespace std;
int repeat(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum=sum^arr[i];
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
    cout<<repeat(arr,n);
    return 0;
}