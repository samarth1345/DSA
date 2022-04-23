#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> map;
bool isScramble(string s1, string s2)
{
    string key = s1 + " " + s2;
    if (map.find(key) != map.end())
        return map[key];
    if (s1 == s2)
        return true;
    int n = s1.length();
    if (n == 1 || (s1.length() != s2.length()))
        return false;
    for (int i = 1; i < n; i++)
    {
        bool cond1, cond2;
        cond1 = (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)));
        if (cond1)
            return map[key] = true;
        cond2 = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)));
        if (cond2)
            return map[key] = true;
    }
    return map[key] = false;
}