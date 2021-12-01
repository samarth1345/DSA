#include <bits/stdc++.h>
using namespace std;
//BS on Answer:
//In this we will apply Binary search on unsorted array.we just look for answer.
//peak element will be greater than both of its neighbour and this is where 
//we will decide that which side we have to move and probability 
//of getting a answer will be high on neighbour which is greater than mid
//and we are going to move in that side. Special case will be 1st and last element 
//of array
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    int n = nums.size();
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid != 0 && mid != n - 1)
        {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid - 1])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if (mid == 0)
        {
            if (nums[mid] > nums[mid + 1])
                return mid;
            start = mid + 1;
        }
        else if (mid == n - 1)
        {
            if (nums[mid] > nums[mid - 1])
                return mid;
            end = mid - 1;
        }
        else
            return -1;
    }
    return -1;
}
int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<findPeakElement(arr);
}