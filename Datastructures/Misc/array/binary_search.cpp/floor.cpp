#include <bits/stdc++.h>
using namespace std;
int findFloor(long long int arr[], int N, long long int K) {
    
    //Your code here
    int start=0,end=N-1,mid;
    long long int ans=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==K)
        return K;
        else if(arr[mid]<K)
        {
            ans=max(ans,arr[mid]);
            start=mid+1;
        }
        else
        end=mid-1;
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
    cout<<findFloor(arr,N,K);
}