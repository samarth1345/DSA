#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    long t;
    cin >> t;
    while (t--)
    {
        map<long, long> m;
        long maxfreq = 0, maxele = 0;
        long n;
        cin >> n;
        long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m[arr[i]]++;
            maxfreq = max(maxfreq, m[arr[i]]);
            maxele = max(maxele, arr[i]);
        }
        if (maxfreq > 2 || m[maxele] > 1)
            cout << "-1" << endl;
        else
        {
            vector<long> left, right;
            bool flag = false;
            for (auto i : m)
            {
                if (i.second > 1)
                {
                    cout << i.first << " ";
                    i.second - 1;
                }
            }
            map<long,long>::reverse_iterator it;
            for (it = m.rbegin(); it != m.rend(); it++)
            {
                cout<< it->first << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
