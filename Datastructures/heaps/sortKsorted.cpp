#include <bits/stdc++.h>
using namespace std;
void sortKsorted(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k){
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
            pq.pop();
    }
}
int main()
{
    int size,k;
    cin>>size>>k;
    vector<int> nums(size);
    for(int i=0;i<size;i++)
        cin>>nums[i];
    sortKsorted(nums,k);
}