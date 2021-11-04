#include<bits/stdc++.h>
using namespace std;
//could have used 2 pointer technique if instead of indices values were asked
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]] = i + 1;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (map[target - nums[i]] != i + 1 && map[target - nums[i]] != 0)
        {
            ans.push_back(min(map[target - nums[i]] - 1, i));
            ans.push_back(max(map[target - nums[i]] - 1, i));
            return ans;
        }
    }
    return ans;
}
int main()
{
    int size,target;
    cin>>size>>target;
    vector<int> nums;
    for(int i=0;i<size;i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    vector<int> ans=twoSum(nums,target);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}