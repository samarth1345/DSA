#include <bits/stdc++.h>
using namespace std;
//logic:this is just a minute modification of binary search where we will just
//change the statement when we found the element.
//we will do 2 binary serach 1 for first index and 2 for last index.
//in 1st when we find the element in array we will then look leftside of that
//mid, if we have some occurence on left side that can be the first index, adnd
//similarily for last index we will start looking in right side when we find the element 
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