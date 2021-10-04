#include <bits/stdc++.h>
using namespace std;
int setBitNumber(int n)
{
    int k = (int)(log2(n));
    return pow(2,k);
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long num;
        cin >> num;
        if(((num)&(num-1))==0 && num!=1)
        {
            cout<<num/2<<endl;
        }
        else
        {
            long ans = setBitNumber(num);
            long temp=num-ans+1;
            if(temp<ans/2)
            {
                temp=ans/2;
            }
            cout<<temp<<endl;
        }
    }
    return 0;
}
