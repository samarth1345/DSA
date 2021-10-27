#include <bits/stdc++.h>
using namespace std;
void solve(string input)
{
    unordered_map<char, bool> map;
    char min_char = 'z';
    char max_char = 'a';
    string ans = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (map[input[i]])
        {
            int j = 0;
            while (ans[j] != input[i])
            {
                j++;
            }
            ans.erase(j, 1);
            int mid_pos = (ans.length() / 2);
            if (ans.empty())
            {
                ans += input[i];
            }
            else if (ans.length() % 2 == 0)
            {
                ans.insert(mid_pos, 1, input[i]);
            }
            else if (ans[mid_pos] > input[i])
            {
                ans.insert(mid_pos, 1, input[i]);
            }
            else
            {
                ans.insert(mid_pos + 1, 1, input[i]);
            }
        }
        else
        {
            ans += input[i];
        }
        if (input[i] < min_char)
        {
            min_char = input[i];
        }
        if (input[i] > max_char)
        {
            max_char = input[i];
        }
        map[input[i]] = true;
    }
    int pos1, pos2;
    for (int i = 0; i < ans.length(); i++)
    {
        if (ans[i] == min_char)
        {
            pos1 = i;
        }
        if (ans[i] == max_char)
        {
            pos2 = i;
        }
    }
    string str1, str2;
    if (pos1 >= pos2)
    {
        str1 = ans.substr(0, pos1 + 1);
        str2 = ans.substr(pos1 + 1, ans.length() - 1);
    }
    else
    {
        str2 = ans.substr(pos1 + 1, pos2 - pos1 - 1);
        str1 = ans.substr(0, pos1 + 1) + ans.substr(pos2, ans.length() - 1);
    }
    for (int i = 0; i < str1.length(); i++)
    {
        cout << str1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < str2.length(); i++)
    {
        cout << str2[i] << " ";
    }
}
int main()
{
    string input;
    cin >> input;
    solve(input);
}