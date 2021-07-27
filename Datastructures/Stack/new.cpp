#include<bits/stdc++.h>
using namespace std;
void solve(string dominoes,string& ans,int j)
    {
        cout<<ans<<endl;
        if(dominoes.length()==ans.length())
        {
            return;
        }
        if(dominoes[j]=='L' || dominoes[j]=='R' || j==0)
        {
            if(j==0 && dominoes[j]=='.')
            {
                if(dominoes[j+1]=='L')
                {
                    dominoes[j]='L';
                }
            }
            ans.push_back(dominoes[j]);
            solve(dominoes,ans,j+1);
        }
        else
        {
            if(dominoes[j-1]=='R' && dominoes[j+1]=='L')
            {
                ans.push_back('.');
            }
            else if(dominoes[j-1]=='R')
            {
                ans.push_back('R');
            }
            else if(dominoes[j+1]=='L')
            {
                ans.push_back('L');
            }
            else
            {
                 ans.push_back('.');
            }
             solve(dominoes,ans,j+1);
        }
    }
    string pushDominoes(string dominoes) 
    {
        string ans="";
        solve(dominoes,ans,0);
        return ans;
    }
int main()
{
    string str;
    cin>>str;
    str=pushDominoes(str);
}    