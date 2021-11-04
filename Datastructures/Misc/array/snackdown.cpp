#include <bits/stdc++.h>
#define LL long
using namespace std;
int main()
{
    LL t;
    cin >> t;
    while (t--)
    {
        LL n;
        unordered_map<LL, bool> map;
        cin >> n;
        LL arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        if (n <= 2)
        {
            cout << "0" << endl;
        }
        else
        {
            sort(arr, arr+n);
            int i = 0, j = n - 1, diff;
            bool flag = false;
            while (i != j)
            {
                diff = arr[j] - arr[i];
                if (map[diff])
                {
                    flag = true;
                    break;
                }
                map[diff] = true;
                i++; j--;
            }
            if (!flag)
            {
                if ((arr[n - 1] == arr[n - 2]) || (arr[0] == arr[1]))
                {
                    cout << "1" << endl;
                }
                else
                {
                    cout << "2" << endl;
                }
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}