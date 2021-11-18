#include <bits/stdc++.h>
using namespace std;
long long no_of_ones(string in)
{
    int ones=0;
    for(int i=0;i<in.size();i++)
    {
        if(in[i]=='1')
        ones++;
    }
    return ones;
}
long long countinversion(string s)
{
    int one=0,ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        ans+=one;
        else
        one++;
    }
    return ans;
}
long long makefinal(vector<string> s)
{
   vector<pair<int,string>> v;
   for(int i=0;i<s.size();i++)
   {
       pair<int,string> p;
       p.first=no_of_ones(s[i]);
       p.second=s[i];
       v.push_back(p);
   }
   sort(v.begin(),v.end());
   string fin_s="";
   for(int i=0;i<v.size();i++)
   {
       fin_s+=v[i].second;
   }
   return countinversion(fin_s);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<string> s(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    cout<<makefinal(s)<<endl;
	}
	return 0;
}