#include <bits/stdc++.h>
using namespace std;
//we used a min heap here beacause when we will traverse through whole array
//and push k elements into heap and pop every time size>k,then at the end
//of traversal we will have the kth largest element
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
int main()
{
    int size,k;
    cin>>size>>k;
    vector<int> nums(size);
    for(int i=0;i<size;i++)
        cin>>nums[i];
    cout<<findKthLargest(nums,k);
}