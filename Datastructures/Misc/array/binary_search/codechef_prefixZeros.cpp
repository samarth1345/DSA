#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;
bool checker(int to_check,string a,int k)
{
    int total=0,left=k;
    for(int i=to_check;i>=0;i--)
    {
        int char_value=a[i]-48;
        int temp=(10-(char_value+total)%10);
        if(temp==0||temp==10)
        continue;
        if(temp>left)
        return false;
        total+=temp;
        left-=temp;
    }
    return true;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string a;
        cin>>a;
        int start=0,end=n-1,mid,ans=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(checker(mid,a,k))
            {
                ans=mid+1;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
}