#include <iostream>
#include <algorithm>
using namespace std;
int *findTwoElement(int *arr, int n)
{
    // code here
    long long int sum = (n * (n + 1)) / 2, sum2 = 0, dup;
    sort(arr, arr + n);
    sum2 = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum2 += arr[i];
        if (arr[i] == arr[i - 1])
            dup = arr[i];
    }
    cout << sum << " " << sum2 << " " << dup << endl;
    int *ans = new int[2];
    ans[0] = dup;
    ans[1] = sum - (sum2 - dup);
    return ans;
}
int main()
{
    int n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findTwoElement(arr, n);
}
