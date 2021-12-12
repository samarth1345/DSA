#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return a>b;
}
vector<int> frequencySort(vector<int> &nums)
{
    unordered_map<int, int> map;
    int size = nums.size();
    for (int i = 0; i < size; i++)
        map[nums[i]]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto i : map)
    {
        pair<int, int> temp;
        temp.first = i.second;
        temp.second = i.first;
        pq.push(temp);
    }
    vector<int> ans;
    int r = -1, element = INT_MAX;
    bool flag=false;
    while (!pq.empty())
    {
        r = pq.top().first;
        element = pq.top().second;
        for(int i=1;i<=r;i++)
            ans.push_back(element);
        pq.pop();
        if(r==pq.top().first)
        {
            int temp=ans.size()-r;
            while(!pq.empty() && pq.top().first==r)
            {
                for(int i=1;i<=r;i++)
                    ans.push_back(pq.top().second);
                pq.pop();
            }
            sort(ans.begin()+temp,ans.end(),comp);
        }
    }
    return ans;
}
int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for(int i=0;i<size;i++)
        cin>>nums[i];
    vector<int> ans=frequencySort(nums);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}