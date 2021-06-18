#include<iostream>
using namespace std;
int checkbitpos(int m)
{
    int i=0;
    while(1)
    {
        if(m&(1<<i))
        {
        return i;
        break;
        }
    }
}
int checkbit(int x,int pos)
{
    if(x&(1<<pos))
    return 1;
    else
    return 0;
}
void repeat(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum=sum^arr[i];
    }
    int m=checkbitpos(sum);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(checkbit(arr[i],m))
        count=(count^arr[i]);
    }
    cout<<count<<endl<<(count^sum)<<endl;
    
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
    repeat(arr,n);
    return 0;
}