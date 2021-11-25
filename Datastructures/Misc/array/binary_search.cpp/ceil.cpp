#include <bits/stdc++.h>
using namespace std;
int findCeil(long long int arr[], int N, long long int K) {
    
    //Your code here
    int start=0,end=N-1,mid;
    long long int ans=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==K)
        return K;
        else if(arr[mid]<K)
        start=mid+1;
        else
        {
        ans=arr[mid];
        end=mid-1;
        }
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    long long int arr[N],K;
    for(int i=0;i<N;i++)
    cin>>arr[i];
    cin>>K;
    cout<<findCeil(arr,N,K);
}