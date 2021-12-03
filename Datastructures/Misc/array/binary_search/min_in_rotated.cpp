#include <bits/stdc++.h>
using namespace std;
//logic:if array is rotated it is for sure that min is in not in it's place
//so we just assume that first element is minimum and in simple binary search,
//if mid is greater than minimum we go right of mid and if mid is less than mimimum
//we update minimum and move left to see if it is minimum of all or not/
int findMin(vector<int> &nums)
{
    int minimum = nums[0];
    int start = 0, end = nums.size() - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] >= minimum)
        {
            start = mid + 1;
        }
        else
        {
            minimum = nums[mid];
            end = mid - 1;
        }
    }
    return minimum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<findMin(arr);
}