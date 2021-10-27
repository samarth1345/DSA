#include <bits/stdc++.h>
using namespace std;
int check(int op1, int op2, char str)
{
    int ans;
    switch (str)
    {
    case '+':
        ans = op1 + op2;
        break;
    case '-':
        ans = op1 - op2;
        break;
    case '*':
        ans = op1 * op2;
        break;
    case '/':
        ans = op1 / op2;
        break;
    default:
        ans = 0;
    }
    return ans;
}
int prefix(string String)
{
    stack<int> Stack;
    for (int i = 0; i < String.length(); i++)
    {
        if (String[i] >= '0' && String[i] <= '9')
        {
            Stack.push(String[i] - '0');
        }
        else
        {
            int op1, op2;
            op1 = Stack.top();
            Stack.pop();
            op2 = Stack.top();
            Stack.pop();
            Stack.push(check(op2, op1, String[i]));
        }
    }
    return Stack.top();
}
int main()
{
    string str;
    cin >> str;
    cout << prefix(str);
    return 0;
}