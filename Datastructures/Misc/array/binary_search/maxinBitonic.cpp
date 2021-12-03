#include <bits/stdc++.h>
using namespace std;
//Bitonic array:array which increases then decreases
//eg.1 3 5 4 2
int findMaximum(vector<int> arr, int n)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid != 0 && mid != n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return arr[mid];
            else if (arr[mid] > arr[mid - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        else if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1])
                return arr[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<findMaximum(arr,n);
}