#include <bits/stdc++.h>
using namespace std;
//in this we will devide the array into two parts first one which is increasing
//second which is decreasing.we will find index of max element and then just divide the 
//array and search in both of them
int findMaximum(vector<int> arr, int n)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid != 0 && mid != n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        else if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1])
                return mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
}
int solve(vector<int> &A, int B)
{
    int n = A.size();
    int start, end, mid;
    int peak = findMaximum(A, n);
    start = 0;
    end = peak;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[mid] < B)
            start = mid + 1;
        else
            end = mid - 1;
    }
    start = peak + 1;
    end = n - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[mid] < B)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<solve(arr,n);
}