#include<bits/stdc++.h>
using namespace std;
//Note: use 0-based indexing
struct manacher
{
    vector<int> p;
    void build(string s)
    {
        string t = "";
        for (auto i : s)
        {
            t += string("#") + i;
        }
        run_manacher(t + "#");
    }
    void run_manacher(string s)
    {
        int n = s.length();
        p.resize(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            p[i] = max(0, min(r - i, (l + r - i >= 0) ? p[l + r - i] : 0));
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
                p[i]++;
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
    int get_longest(int center, bool odd)
    {
        int pos = 2 * center + 1 + !odd;
        return p[pos] - 1;
    }
    bool check(int left, int right)
    {
        bool isOdd = (left % 2 == right % 2);
        int len = get_longest((left + right) / 2, isOdd);
        if (len >= (right - left + 1))
        {
            return true;
        }
        return false;
    }
};