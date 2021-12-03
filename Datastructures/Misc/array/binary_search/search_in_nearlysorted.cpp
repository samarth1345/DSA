#include <bits/stdc++.h>
using namespace std;
//logic:we will perform basic binary search with slight modification
//for every mid we will check its adjacent elements and moving left right remains
//same
int check(vector<int> nums,int key,int pos,int N)
{
    if(nums[pos]==key)
    return pos;
    else if(nums[(pos+1)%N]==key)
    return (pos+1)%N;
    else if(nums[(pos-1+N)%N]==key)
    return (pos-1+N)%N;

    return -1;
}
int search(vector<int> nums,int key)
{
    int N=nums.size();
    int start=0,end=N-1,mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        int temp=check(nums,key,mid,N);
        if(temp!=-1)
        return temp;
        else if(nums[mid]>key)
        end=mid-2;
        else
        start=mid+2;
    }
    return -1;
}
int main()
{
    int n,key;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin>>key;
    cout << search(arr,key);
}