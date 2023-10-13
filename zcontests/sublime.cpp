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
struct segment_tree{
    vector<int> st,lazy;
    int size;
    segment_tree(int n){
        this->size=n;
        st.resize(4*n);
        lazy.resize(4*n);
    }
    void build(string &s){
        build(0,0,size-1,s);
    }
    void build(int node,int l,int r,string &s){
        if(l==r){
            st[node]=(int)(s[l]-'a');
            return;
        }
        int mid=l+(r-l)/2;
        build(2*node+1,l,mid,s);
        build(2*node+2,mid+1,r,s);
    }
    void update(int start,int end,int val){
        update(0,0,size-1,start,end,val);
    }
    void update(int node,int l,int r,int start,int end,int val){
        if(l>end || r<start)
            return;
        if(lazy[node]!=0){
            if(l!=r){
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+1]%=26;
                lazy[2*node+2]+=lazy[node];
                lazy[2*node+2]%=26;
            }else{
                st[node]+=lazy[node];
                st[node]%=26;
            }
            lazy[node]=0;
        }
        if(l>=start && r<=end){
            if(l!=r){
                lazy[2*node+1]+=val;
                lazy[2*node+1]%=26;
                lazy[2*node+2]+=val;
                lazy[2*node+2]%=26;
            }else{
                st[node]+=val;
                st[node]%=26;
            }
            return;
        }
        int mid=l+(r-l)/2;
        update(2*node+1,l,mid,start,end,val);
        update(2*node+2,mid+1,r,start,end,val);
    }
    int query(int idx){
        return query(0,0,size-1,idx);
    }
    int query(int node,int l,int r,int idx){
        if(idx > r || idx < l)
            return 0;
        if(lazy[node]!=0){
            if(l!=r){
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+1]%=26;
                lazy[2*node+2]+=lazy[node];
                lazy[2*node+2]%=26;
            }else{
                st[node]+=lazy[node];
                st[node]%=26;
            }
            lazy[node]=0;
        }
        if(l==idx && r==idx){
            return st[node];
        }
        int mid=l+(r-l)/2;
        return query(2*node+1,l,mid,idx)+query(2*node+2,mid+1,r,idx);
    }
};
struct manacher
{
    vector<int> p;
    void build(string s)
    {
        string t = "";
        for (auto i : s)
        {
            t += string("#") + i;
        }
        run_manacher(t + "#");
    }
    void run_manacher(string s)
    {
        int n = s.length();
        p.resize(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            p[i] = max(0, min(r - i, (l + r - i >= 0) ? p[l + r - i] : 0));
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
                p[i]++;
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
    int get_longest(int center, bool odd)
    {
        int pos = 2 * center + 1 + !odd;
        return p[pos] - 1;
    }
    bool check(int left, int right)
    {
        bool isOdd = (left % 2 == right % 2);
        int len = get_longest((left + right) / 2, isOdd);
        if (len >= (right - left + 1))
        {
            return true;
        }
        return false;
    }
};
/*-------------------------------------------------------------------------------------*/
void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    segment_tree *tree=new segment_tree(n);
    tree->build(s);
    manacher obj;
    obj.build(s);
    set<int> odd_pal,even_pal;
    for(int i=0;i<n;i++){
        int o=obj.get_longest(i,true);
        int e=obj.get_longest(i,false);
        if(o>2){
            odd_pal.insert(i);
        }
        if(e>1){
            even_pal.insert(i+1);
        }
    }
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        if(k==1){
            int l,r,x;
            cin>>l>>r>>x;
            l--;r--;
            tree->update(l,r,x);
            if(l==r){
                if(tree->query(l)!=tree->query(l+1))
                    even_pal.erase(l+1);
                else if(l+1<n)
                    even_pal.insert(l+1);
                
                if(tree->query(l)!=tree->query(l-1))
                    even_pal.erase(l);
                else if(l-1>=0)
                    even_pal.insert(l);
                
                if(tree->query(l)!=tree->query(l+2))
                    odd_pal.erase(l+1);
                else if(l+2<n)
                    odd_pal.insert(l+1);
                
                if(tree->query(l)!=tree->query(l-2))
                    odd_pal.erase(l-1);
                else if(l-2>=0)
                    odd_pal.insert(l-1);
            }else{
                if(tree->query(l)!=tree->query(l+1))
                    even_pal.erase(l+1);
                else if(l+1<n)
                    even_pal.insert(l+1);
                
                if(tree->query(l)!=tree->query(l-1))
                    even_pal.erase(l);
                else if(l-1>=0)
                    even_pal.insert(l);
                
                if(tree->query(l)!=tree->query(l+2))
                    odd_pal.erase(l+1);
                else if(l+2<n)
                    odd_pal.insert(l+1);
                
                if(tree->query(l)!=tree->query(l-2))
                    odd_pal.erase(l-1);
                else if(l-2>=0)
                    odd_pal.insert(l-1);
                
                if(tree->query(l-1)!=tree->query(l+1))
                    odd_pal.erase(l);
                else if(l-1>=0 && l+1<n)
                    odd_pal.insert(l);
                /**********************************************************/
                
                if(tree->query(r)!=tree->query(r+1))
                    even_pal.erase(r+1);
                else if(r+1<n)
                    even_pal.insert(r+1);
                
                if(tree->query(r)!=tree->query(r-1))
                    even_pal.erase(r);
                else if(r-1>=0)
                    even_pal.insert(r);
                
                if(tree->query(r)!=tree->query(r+2))
                    odd_pal.erase(r+1);
                else if(r+2<n)
                    odd_pal.insert(r+1);
                
                if(tree->query(r)!=tree->query(r-2))
                    odd_pal.erase(r-1);
                else if(r-2>=0)
                    odd_pal.insert(r-1);
                
                if(tree->query(r-1)!=tree->query(r+1))
                    odd_pal.erase(r);
                else if(r-1>=0 && r+1<n)
                    odd_pal.insert(r);
            }
        }else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            bool ok=false;
            auto idx1=even_pal.lower_bound(l+1);
            int idx1v=*(idx1);
            if(idx1v>=l+1 && idx1v<=r){
                // cout<<idx1v<<" "<<"e"<<" ";
                cout<<"NO"<<endl;
                ok=true;
            }
            auto idx2=odd_pal.lower_bound(l+1);
            int idx2v=*(idx2);
            if(idx2v>=l+1 && idx2v <= r-1 && !ok){
                // cout<<idx2v<<" "<<"o"<<" ";
                cout<<"NO"<<endl;
                ok=true;
            }
            if(!ok){
                cout<<"YES"<<endl;
            }
        }
        // for(int j=0;j<n;j++)
        //     cout<<(char)(tree->query(j)+'a');
        // cout<<endl;
    }
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
        solve();
    }
}