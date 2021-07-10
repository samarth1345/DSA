#include<iostream>
#include<vector>
using namespace std;
int josephus(int arr[],int k,int n,int pos,int m)
{
    int new_pos=(pos+k-1)%m;
    cout<<new_pos<<" ";
    if(n==1)
    {
        return new_pos;
    }
    while(arr[new_pos]==0)
    {
        if(arr[new_pos]==0)
        {
        arr[new_pos]=1;
        }
        else
        {
        new_pos+=k;
        }
    }
    return josephus(arr,k,n-1,new_pos+1,m);
}
int main()
{
    int n,k,i=0;
    cin>>n>>k;
    int arr[n]={0};
    cout<<endl<<josephus(arr,k,n,0,n);

    return 0;
}