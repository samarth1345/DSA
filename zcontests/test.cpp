#include "bits/stdc++.h"
#define endl "\n"
#define int long long int
#define MAX LLONG_MAX
#define ff first
#define ss second
#define pb push_back
#define all(p) p.begin(),p.end()
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
//using namespace __gnu_pbds; 
using namespace std;
const int Mod = 1000000007;
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int power(int x, int p){
    int result=1;
    while(p>0){
        if(p&1)
           result=(result*x)%Mod;
        x=(x*x)%Mod;
        p/=2;
    }
    return result;
}
// vector<int> sfm(1e6+1);
// vector<vector<int>> primes;
// void make_sieve(){
//     for(int i=1;i<=1e6;i++)
//         sfm[i]=i;
//     for(int i=2;i<=1e6;i++){
//         if(sfm[i]==i){
//             int mul=2;
//             while(i*mul <= 1e6){
//                 if(sfm[i*mul]==i*mul)
//                     sfm[i*mul]=i;
//                 mul++;
//             }
//         }
//     }
//     primes.push_back({});
//     for(int i=1;i<=1e6;i++){
//         vector<int> temp;
//         int n=i;
//         while(n!=1){
//             temp.push_back(sfm[n]);
//             int t=sfm[n];
//             while(n%t == 0)
//                 n/=t;
//         }
//         primes.push_back(temp);
//     }
// }
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
struct seg_tree{
    vector<int> mn,mx;
    seg_tree(int n){
        mn.resize(4*n);
        mx.resize(4*n);
    }
    void build(int node,int l,int r,vector<int>& one,vector<int>& two){
        if(l==r){
            mn[node]=two[l];
            mx[node]=one[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2*node+1,l,mid,one,two);
        build(2*node+2,mid+1,r,one,two);
        mx[node]=max(mx[2*node+1],mx[2*node+2]);
        mn[node]=min(mn[2*node+1],mn[2*node+2]);
    }
    pair<int,int> query(int node,int l,int r,int start,int end){
        if(l>=start && r<=end)
            return {mn[node],mx[node]};
        if(l>end || r<start)
            return {INT_MAX,INT_MIN};
        int mid = (l + r) >> 1;
        auto left=query(2*node+1,l,mid,start,end);
        auto right=query(2*node+2,mid+1,r,start,end);
        return {min(left.first,right.first),max(left.second,right.second)};
    }
};
/*-------------------------------------------------------------------------------------*/
void solve(){
    int n;
    cin>>n;
    vector<int> f(n),s(n);
    for(int i=0;i<n;i++)
        cin>>f[i];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int count=0;
    seg_tree *tree=new seg_tree(n);
    tree->build(0,0,n-1,f,s);
    for(int i=1;i<=n;i++){
        int start=0,end=i-1,ans1=-1,ans2=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            auto t=tree->query(0,0,n-1,max(0,mid),min(n-1,i-1));
            int mx=t.first,mn=t.second;
            if(mx==mn){
                ans2=mid;
                end=mid-1;
            }else if(mx>mn){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        start=0; end=i-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            auto t=tree->query(0,0,n-1,max(0,mid),min(n-1,i-1));
            int mx=t.first,mn=t.second;
            if(mx==mn){
                ans1=mid;
                start=mid+1;
            }else if(mx>mn){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        if(ans1!=-1)
            count+=(ans1-ans2+1);
    }
    cout<<count<<endl;
}
int dp[101][101];
bool check(string s,int l,int r){
    while(l!=r){
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
bool help(string &s,int l,int r){
    if(r-l < 1)
        return false;
    if(dp[l][r]!=-1)
        return dp[l][r];
    bool ans=check(s,l,r);
    if(ans)
        return true;
    if(l%2 == r%2){
        for(int i=l+2;i<=r-2;i++){
            ans|=(help(s,l,i-1)&&help(s,i+1,r));
        }
    }else{
        for(int i=l+1;i<=r-1;i++){
            ans|=(help(s,l,i)&&help(s,i+1,r));
        }
    }
    return dp[l][r]=ans;
}
void solve1(){
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        memset(dp,-1,sizeof(dp));
        count+=help(s,0,s.length()-1);
    }
    cout<<count<<endl;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve1();
    }
}