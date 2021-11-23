//Given an array of strings words, return the words that can be 
//typed using letters of the alphabet on only one row of American keyboard 
#include<bits/stdc++.h>
using namespace std;
string to_lower(string input)
{
    string ans = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] < 97)
            ans += (input[i] + 32);
        else
            ans += input[i];
    }
    return ans;
}
vector<string> findWords(vector<string> &words)
{
    unordered_map<char, int> map;
    vector<string> ans;
    string first = "qwertyuiop", second = "asdfghjkl", third = "zxcvbnm";
    for (int i = 0; i < first.length(); i++)
        map[first[i]] = 1;

    for (int i = 0; i < second.length(); i++)
        map[second[i]] = 2;

    for (int i = 0; i < third.length(); i++)
        map[third[i]] = 3;

    for (int i = 0; i < words.size(); i++)
    {
        bool flag = true;
        string temp = to_lower(words[i]);
        for (int j = 1; j < temp.length(); j++)
        {
            if (map[temp[j]] != map[temp[j - 1]])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans.push_back(words[i]);
    }
    return ans;
}
int main()
{
    string input;
}