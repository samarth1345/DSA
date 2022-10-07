#include <iostream>
#include <vector>
using namespace std;
vector<int> get_lps(string s, string pat)
{
    vector<int> lps(pat.length());
    int prev_lps = 0, i = 1;
    // prev_lps is actually the index which is helping us match the prefixe's
    // of the string.
    while (i < pat.length())
    {
        if (s[i] == s[prev_lps])
        {
            lps[i] = prev_lps + 1;
            prev_lps++;
            i++;
        }
        else if (prev_lps == 0)
        {
            lps[i] = 0;
            i++;
        }
        else
        {
            // this is telling that if we can not have prev_lps+1 here can we
            // have prev_lps-1 value here
            prev_lps = lps[prev_lps - 1];
        }
    }
    return lps;
}
void kmp(string s, string pat)
{
    vector<int> lps = get_lps(s, pat);
    int i = 0, j = 0;
    while (i < s.length())
    {
        if (s[i] == pat[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = lps[j - 1];
        }
        if (j == pat.length())
        {
            cout << i - j << endl;
            j--;
        }
    }
}
int main()
{
    string s;
    cin >> s;
    string pat;
    cin >> pat;
    kmp(s, pat);
}