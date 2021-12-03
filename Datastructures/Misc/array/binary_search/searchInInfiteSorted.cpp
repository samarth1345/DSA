#include <bits/stdc++.h>
using namespace std;
//logic:the only problem in this question is we don't have end for finding mid
//so we have to start with small end and then keep moving it until
//we get upper bound of K
int search(int *arr, int K)
{
    //Your code here
    int start = 0, end = 1, mid=-1;
    //this loop is to find window for searching 
    while (1)
    {
        if (arr[end] >= K)
            break;
        else
        {
            start = end;
            end = end * 2;
        }
    }
    //this is basic binary search
    while (start <= end)
    {
        mid = start+(end-start)/2;
        if (K == arr[mid])
        {
            return mid;
        }
        else if (K < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return mid;
}
int main()
{
    int N;
    cin >> N;
    int arr[N], K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> K;
    cout << search(arr, K);
}