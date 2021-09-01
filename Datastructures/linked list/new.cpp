#include <bits/stdc++.h>
using namespace std;
bool flag;
bool compare(string ip, string op)
{
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == op[i])
        {
            return false;
        }
    }
    return true;
}
void permutations(string ip, string op, string final)
{
    if (!flag)
    {
        if (op.length() == final.length())
        {
            if (compare(final, op))
            {
                flag = true;
                cout << op << endl;
            }
            return;
        }
        for (int i = 0; i < ip.length(); i++)
        {
            string op1 = op;
            op1 = op1 + ip[i];
            string ip1 = ip;
            ip1.erase(i, 1);
            permutations(ip1, op1, final);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        flag=false;
        string str;
        cin >> str;
        permutations(str, "", str);
        if(!flag)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
}