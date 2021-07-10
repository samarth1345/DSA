//We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
//For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
//Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
/***************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k)
{
    int length=pow(2,n)/2;
    int mid=length/2;
    if(n==1 || k==1)             //base condition
    {
        return 0;
    }
    if(k<=mid)                  //hypohthesis
    {
        return solve(n-1,k);
    }
    else                       //induction
    {
        return !solve(n-1,k-mid);
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
}