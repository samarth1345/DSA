#include <bits/stdc++.h>
using namespace std;
vector<int> takeInput(vector<int> input, int size)
{
    vector<int> ans(size);
    queue<pair<int, int>> q;
    int count = 1;
    ans[0] = input[0];
    ans[size - 1] = input[1];
    q.push({0, size - 1});
    while (!q.empty() && count < size)
    {
        count++;
        int mid = (q.front().first + q.front().second) / 2;
        ans[mid] = input[count];
        if ((mid - q.front().first) > 1)
        {
            q.push({q.front().first, mid});
        }
        if ((q.front().second - mid) > 1)
        {
            q.push({mid, q.front().second});
        }
        q.pop();
    }
    return ans;
}
int getfirsteven(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] % 2 == 0)
        {
            return i;
        }
    }
    return -1;
}
int getfirstodd(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] % 2 != 0)
        {
            return i;
        }
    }
    return -1;
}
int getlastodd(vector<int> ans)
{
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] % 2 != 0)
        {
            return i;
        }
    }
    return -1;
}
int getlasteven(vector<int> ans)
{
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] % 2 == 0)
        {
            return i;
        }
    }
    return -1;
}
int getfirstpos(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] > 0)
        {
            return i;
        }
    }
    return -1;
}
int getfirstneg(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] < 0)
        {
            return i;
        }
    }
    return -1;
}
int getlastpos(vector<int> ans)
{
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] > 0)
        {
            return i;
        }
    }
    return -1;
}
int getlastneg(vector<int> ans)
{
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] < 0)
        {
            return i;
        }
    }
    return -1;
}
bool removeEven(vector<int> &ans)
{
    int first_even, first_odd, last_even, last_odd;
    int count = 0;
    while (first_even != -1 && last_even != -1)
    {
        first_even = getfirsteven(ans);
        first_odd = getfirstodd(ans);
        if (first_even != -1)
        {
            ans[max(first_even, first_odd)] = ans[first_even] + ans[first_odd];
            ans.erase(ans.begin() + min(first_even, first_odd));
        }

        last_even = getlasteven(ans);
        last_odd = getlastodd(ans);
        if (last_even != -1)
        {
            ans[min(last_even, last_odd)] = ans[last_even] + ans[last_odd];
            ans.erase(ans.begin() + max(last_even, last_odd));
        }
        count++;
    }
    if (count == 0)
    {
        return false;
    }
    return true;
}
bool removenegative(vector<int> &ans)
{
    int first_pos, first_neg, last_pos, last_neg;
    int count = 0;
    while (first_neg != -1 && last_neg != -1)
    {
        first_pos = getfirstpos(ans);
        first_neg = getfirstneg(ans);
        if (first_neg != -1)
        {
            ans[max(first_pos, first_neg)] = ans[first_pos] + ans[first_neg];
            ans.erase(ans.begin() + min(first_pos, first_neg));
        }
        last_pos = getlastpos(ans);
        last_neg = getlastneg(ans);
        if (last_neg != -1)
        {
            ans[min(last_pos, last_neg)] = ans[last_pos] + ans[last_neg];
            ans.erase(ans.begin() + max(last_pos, last_neg));
        }
        count++;
    }
    if (count == 0)
    {
        return false;
    }
    return true;
}
vector<int> removeduplicates(vector<int> ans)
{
    unordered_map<int, bool> map;
    vector<int> afterremove;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (!map[ans[i]])
        {
            afterremove.push_back(ans[i]);
        }
        map[ans[i]] = true;
    }
    return afterremove;
}
vector<int> solve(vector<int> input, int size)
{
    vector<int> ans = takeInput(input, size);
    removeEven(ans);
    removenegative(ans);
    removeEven(ans);
    ans=removeduplicates(ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int> input;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    vector<int> ans = solve(input, size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
