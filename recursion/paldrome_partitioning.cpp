#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<numeric>
using namespace std;
using namespace std;
vector<vector<string>> ans;
bool isPalindrome(string &str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(string &s, int start, int end, vector<string> &curr)
{
    if (start > end)
    {
        ans.push_back(curr);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        if (isPalindrome(s, start, i))
        {
            vector<string> temp = curr;
            temp.push_back(s.substr(start, i - start + 1));
            solve(s, i + 1, end, temp);
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> temp;
    solve(s, 0, s.length() - 1, temp);
    return ans;
}