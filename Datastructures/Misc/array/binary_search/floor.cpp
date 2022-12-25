#include <bits/stdc++.h>
using namespace std;
int floor(vector<int> arr,int K) {
    int N=arr.size();
    int start=0,end=N-1,mid,ans=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==K)
            return mid;
        else if(arr[mid]<K)
        {
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
    }
    return ans;
}
