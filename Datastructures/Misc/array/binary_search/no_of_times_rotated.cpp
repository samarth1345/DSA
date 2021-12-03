#include <bits/stdc++.h>
using namespace std;
//firstly,this is same problem as min_in_rotated,if we have min we can find no of rotations.
//we are finding min with a different method then min_in_rotated.
//eg. of rotated sorted array = 11 15 16 20 2 4 7 8
//observations: 1.min element is smaller than both the adjacent elements
//2.if element[start]<element[end] array is sorted(no rotations)
//3.we will always search for min in unsorted part ,as it contains ROTATED array
//which further contains minimmum element
int findMin(vector<int> &nums)
{
    int N = nums.size();
    int start = 0, end = N - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[start] <= nums[end])
            return start;

        if (nums[(mid + N - 1) % N] > nums[mid] && nums[(mid + 1) % N] > nums[mid])
            return mid;

        if (nums[start] <= nums[mid])
            start = mid + 1;

        else
            end = mid - 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << n - findMin(arr);
}