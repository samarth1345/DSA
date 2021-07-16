#include <bits/stdc++.h>
using namespace std;
void solve(string op, int zero, int one, int n, int m)
{
    if (n == 0)
    {
        cout << op << endl;
        return;
    }
    if (one >= zero)
    {
        if (one < m)
        {
            string op1, op2;
            op1 = op2 = op;
            op1 = op1 + "0";
            op2 = op2 + "1";
            solve(op1, zero + 1, one, n - 1, m);
            solve(op2, zero, one + 1, n - 1, m);
        }
        else
        {
            if (zero != 0)
            {
                string op3 = op;
                if (op.back() == 0)
                {
                    op3 = op3 + "1";
                    solve(op3, zero, one + 1, n - 1, m);
                }
                else
                {
                    op3 = op3 + "0";
                    solve(op3, zero + 1, one, n - 1, m);
                }
            }
            else
            {
                string op3 = op;
                op3 = op3 + "1";
                solve(op3, zero, one + 1, n - 1, m);
            }
        }
    }
    else
    {
        if (zero < m)
        {
            string op1, op2;
            op1 = op2 = op;
            op1 = op1 + "0";
            op2 = op2 + "1";
            solve(op1, zero + 1, one, n - 1, m);
            solve(op2, zero, one + 1, n - 1, m);
        }
        else
        {
            if (one != 0)
            {
                string op3 = op;
                if (op.back() == 1)
                {
                    op3 = op3 + "0";
                    solve(op3, zero + 1, one , n - 1, m);
                }
                else
                {
                    op3 = op3 + "1";
                    solve(op3, zero , one + 1, n - 1, m);
                }
            }
            else
            {
                string op3 = op;
                op3 = op3 + "0";
                solve(op3, zero + 1, one, n - 1, m);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    solve("", 0, 0, 2 * n, n);
    return 0;
}
