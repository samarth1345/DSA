#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    int size = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        map[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto i : map)
    {
        pair<int, int> temp;
        temp.first = i.second;
        temp.second = i.first;
        if (pq.size() < k)
        {
            pq.push(temp);
        }
        else if (temp.first > pq.top().first)
        {
            pq.pop();
            pq.push(temp);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        cout<<pq.top().second<<" ";
        pq.pop();
    }
    return ans;
}
int main()
{
    int size,k,x;
    cin>>size>>k;
    vector<int> nums(size);
    for(int i=0;i<size;i++)
        cin>>nums[i];
    topKFrequent(nums,k);
}