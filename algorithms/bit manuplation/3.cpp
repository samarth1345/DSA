#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll allone(int count)
{
    ll ans = 0;
    for (int i = 0; i <= count; i++)
    {
        ans += (pow(10, i));
    }
    return ans;
}
ll fornine(ll n)
{
    int d = 9;
    ll ans = 0, prev_value = 0, count = 0, temp;
    int digit;
    ll m=n;
    while (m != 0)
    {
        
    }
    return ans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        ll ans = 0, prev_value = 0, count = 0, temp;
        int digit;
        if (d == 9)
        {
            cout << fornine(n) << endl;
        }
        else if(d == 0 && n == 0)
        {
            cout<<"1"<<endl;
        }
        else
        {
            while (n != 0)
            {
                digit = n % 10;
                if (digit == d)
                {
                    if (d == 0)
                    {
                        temp = allone(count) - prev_value;
                        ans += temp;
                    }
                    else
                    {
                        temp = pow(10, count) - prev_value;
                        ans += temp;
                    }
                }
                else
                {
                    temp = 0;
                }
                prev_value += temp;
                prev_value += digit * pow(10, count);
                count++;
                n /= 10;
            }
            cout << ans << endl;
        }
    }
}