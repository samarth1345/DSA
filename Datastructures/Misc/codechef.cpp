#include <bits/stdc++.h>
using namespace std;
void print(stack<int> s1, stack<int> s2, queue<int> q)
{
    bool flag_s1 = false, flag_s2 = false, flag_q = false;
    while (!q.empty())
    {
        flag_q = true;
        cout << q.front() << " ";
        q.pop();
    }
    if (flag_q)
        cout << endl;
    while (!s1.empty())
    {
        flag_s1 = true;
        cout << s1.top() << " ";
        s1.pop();
    }
    if (flag_s1)
        cout << endl;
    while (!s2.empty())
    {
        flag_s2 = true;
        cout << s2.top() << " ";
        s2.pop();
    }
    if (flag_s2)
        cout << endl;
}
void do_queue(stack<int> &s, queue<int> &q)
{
    while (!q.empty())
    {
        int k = q.size() - 1;
        queue<int> temp;
        for (int i = 1; i <= k; i++)
        {
            temp.push(q.front());
            q.pop();
        }
        for (int i = 1; i <= k; i++)
        {
            q.push(temp.front());
            temp.pop();
        }
        s.push(q.front());
        q.pop();
    }
}
void insert_else(int num, stack<int> &s1, stack<int> &s2, queue<int> &q, bool flag)
{
    if (flag)
    {
        while (!s1.empty() && num >= s1.top())
        {
            q.push(s1.top());
            s1.pop();
        }
        s1.push(num);
        print(s1, s2, q);
        do_queue(s1, q);
    }
    else
    {
        while (!s2.empty() && num <= s2.top())
        {
            q.push(s2.top());
            s2.pop();
        }
        s2.push(num);
        print(s1, s2, q);
        do_queue(s2, q);
    }
}
void insert(int num, stack<int> &s1, stack<int> &s2, queue<int> &q)
{
    if (s1.empty() || num < s1.top())
    {
        s1.push(num);
        print(s1, s2, q);
    }
    else if (s2.empty() || num > s2.top())
    {
        s2.push(num);
        print(s1, s2, q);
    }
    else
    {
        if (abs(s1.top() - num) < abs(s2.top() - num))
            insert_else(num, s1, s2, q, true);
        else
            insert_else(num, s1, s2, q, false);
    }
}
void reverse_stack(stack<int> &s)
{
    queue<int> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty())
    {
        s.push(temp.front());
        temp.pop();
    }
}
void last_step(stack<int> &s1, stack<int> &s2, queue<int> &q)
{
    reverse_stack(s2);
    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() < s2.top())
        {
            q.push(s1.top());
            s1.pop();
        }
        else
        {
            q.push(s2.top());
            s2.pop();
        }
        print(s1, s2, q);
    }
    while (!s1.empty())
    {
        q.push(s1.top());
        s1.pop();
        print(s1, s2, q);
    }
    while (!s2.empty())
    {
        q.push(s2.top());
        s2.pop();
        print(s1, s2, q);
    }
}
void solve(vector<int> arr, int n)
{
    stack<int> s1, s2;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        insert(arr[i], s1, s2, q);
    }
    last_step(s1, s2, q);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    solve(arr, n);
}