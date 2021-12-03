#include <bits/stdc++.h>
using namespace std;
//logic:the only problem in this question is we don't have end for finding mid
//so we have to start with small end and then keep moving it until
//we get 1,also we will use binary search to find first index/
int search(int *arr)
{
    //Your code here
    int start = 0, end = 1, mid ,ans=-1;
    //this loop is to find window for searching
    while (arr[end] != 1)
    {
        start = end;
        end = end * 2;
    }
    //this is basic binary search
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if(arr[mid]==1)
        {
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans;
}
int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << search(arr);
}