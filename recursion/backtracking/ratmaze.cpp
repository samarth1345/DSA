#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>> v,int row, int col,int n)
{
    if(row<=n-1 && col<=n-1 && v[row][col]==0)
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> v,int row, int col,int n,vector<vector<int>>& ans)
{
    if(row==n-1 && col==n-1)
    {
        return;
    }
    if(check(v,row,col+1,n))  
    {
        
    }
}