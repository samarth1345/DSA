#include <bits/stdc++.h>
using namespace std;
vector<int> printFirstNegativeInteger(int *A, int N, int K)
{
    queue<pair<int, int>> q;
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
        q.push({A[i], i});
    }
    int totwindow = N - K + 1;
    for (int i = 0; i < totwindow; i++)
    {
        if (!q.empty() && q.front().second < (K + i))
        {
            ans.push_back(q.front().first);
        }
        else
        {
            ans.push_back(0);
        }

        if (q.front().second < (i + 1))
        {
            q.pop();
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        vector<int> ans = printFirstNegativeInteger(A, n, k);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout<<endl;
    }
}