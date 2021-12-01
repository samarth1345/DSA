#include <bits/stdc++.h>
using namespace std;
//this is just another variation of allocate min. no of pages
//we will apply binary search on min. distance(i.e answer)
//lower limit will be 1(not arr[1]-arr[0] because it may have diff greater than some 
//other pair) and upper limit would be arr[n-1]-arr[0](farthest pair)
//check function will check if we can put cows with given minimum distance
//if it can we will just optimise this or else move lower the min. distance.
bool check(int *arr, int n, int k,int c)
{
    int j = 0, cows = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[j] >= k)
        {
            cows++;
            j = i;
        }
        if(cows==c)
        return true;
    }
    //cout<<cows<<endl;
    return false;
}
int aggressivecows(int *arr, int n, int c)
{
    sort(arr, arr + n);
    int start = 1, end = arr[n - 1] - arr[0], mid, ans = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (check(arr, n, mid,c))
        {
            ans = mid;
            start = mid + 1;
        }
        else 
            end = mid - 1;
    }
    return ans;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout<<aggressivecows(arr, n, c)<<endl;
    }
    return 0;
}