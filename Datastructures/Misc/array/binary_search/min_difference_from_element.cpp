#include <bits/stdc++.h>
using namespace std;
//logic:we could have find floor and ceil for K with different functions
//but in binary search if element is not present then at end of loop
//start and end are pointing at floor and ceil of K
//so we just se this fact
int findMindiff(int *arr, int N,int K) {
    
    //Your code here
    int start=0,end=N-1,mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==K)
        return 0;
        else if(arr[mid]<K)
        start=mid+1;
        else
        end=mid-1;
    }
    return min(abs(K-arr[start]),abs(K-arr[end]));
}
int main()
{
    int N;
    cin>>N;
    int arr[N],K;
    for(int i=0;i<N;i++)
    cin>>arr[i];
    cin>>K;
    cout<<findMindiff(arr,N,K);
}