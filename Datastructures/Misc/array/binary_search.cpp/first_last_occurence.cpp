#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int start = 0, end = nums.size()-1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            if (ans.size()==0)
                ans.push_back(mid);
            else
            {
                ans.erase(ans.begin());
                ans.push_back(mid);
            }
            end = mid - 1;
        }
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    if (ans.empty())
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    start = 0;
    end = nums.size()-1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            if (ans.size() == 1)
                ans.push_back(mid);
            else
            {
                ans.erase(ans.begin() + 1);
                ans.push_back(mid);
            }
            start = mid + 1;
        }
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return ans;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> ans;
    ans = searchRange(arr, x);
    cout << ans[0] << endl
         << ans[1];
}