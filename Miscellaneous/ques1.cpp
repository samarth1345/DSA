/*Given a number N, generate bit patterns from 0 to 2^N-1 such that successive patterns differ by one bit. 
 
Example 1:
Input:
N = 2
Output: 
00 01 11 10
Explanation: 
00 and 01 differ by one bit.
01 and 11 differ by one bit.
11 and 10 also differ by one bit.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void show(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;
    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    cout<<binaryNumber<<" ";
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=i+1;j<(1<<n);j++)
        {
            if(((i^j)%2)==0||((i^j)==1))
            {
            show(i);
            show(j);
            cout<<endl;
            }
        }
    }
}