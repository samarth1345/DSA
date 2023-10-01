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
struct node{
    int max_cons_one,max_cons_zero;
    int left_one,left_zero;
    int right_one,right_zero;
    node(){
        max_cons_zero=0; max_cons_one=0;
        left_zero=0; left_one=0;
        right_zero=0; right_one=0;
    }  
};
struct seg_tree{
    vector<node> st;
    vector<int> lazy;
    seg_tree(int n){
        st.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int node,int l,int r,string &s){
        if(l==r){
            st[node].max_cons_one=(s[l]=='1');
            st[node].max_cons_zero=(s[l]=='0');
            st[node].left_one=(s[l]=='1');
            st[node].left_zero=(s[l]=='0');
            st[node].right_one=(s[l]=='1');
            st[node].right_zero=(s[l]=='0');
            return;
        }
        int mid=l+(r-l)/2;
        build(2*node+1,l,mid,s);
        build(2*node+2,mid+1,r,s);
        st[node].max_cons_one=max({st[2*node+1].max_cons_one,st[2*node+2].max_cons_one,st[2*node+1].right_one+st[2*node+2].left_one});
        st[node].max_cons_zero=max({st[2*node+1].max_cons_zero,st[2*node+2].max_cons_zero,st[2*node+1].right_zero+st[2*node+2].left_zero});
        st[node].left_one=st[2*node+1].left_one;
        if(st[2*node+1].left_one==(mid-l+1)){
            st[node].left_one+=st[2*node+2].left_one;
        }
        st[node].left_zero=st[2*node+1].left_zero;
        if(st[2*node+1].left_zero==(mid-l+1)){
            st[node].left_zero+=st[2*node+2].left_zero;
        }
        st[node].right_one=st[2*node+2].right_one;
        if(st[2*node+2].right_one==(r-(mid+1)+1)){
            st[node].right_one+=st[2*node+1].right_one;
        }
        st[node].right_zero=st[2*node+2].right_zero;
        if(st[2*node+2].right_zero==(r-(mid+1)+1)){
            st[node].right_zero+=st[2*node+1].right_zero;
        }
        // cout<<l<<" "<<r<<" "<<st[node].max_cons_one<<" "<<st[node].max_cons_zero<<" "<<st[node].left_one<<" "<<st[node].left_zero<<" "<<st[node].right_one<<" "<<st[node].right_zero<<endl;
    }
    void flip(int node,int l,int r){
        swap(st[node].max_cons_one,st[node].max_cons_zero);
        swap(st[node].left_one,st[node].left_zero);
        swap(st[node].right_one,st[node].right_zero);
    }
    void update(int node,int l,int r,int start,int end){
        if(lazy[node]!=0){
            flip(node,l,r);
            lazy[node]=0;
            if(l!=r){
                lazy[2*node+1]^=1;
                lazy[2*node+2]^=1;
            }
        }
        if(l>=start && r<=end){
            flip(node,l,r);
            if(l!=r){
                lazy[2*node+1]^=1;
                lazy[2*node+2]^=1;
            }
            return;
        }
        if(l>end || r<start)
            return;
        int mid=l+(r-l)/2;
        update(2*node+1,l,mid,start,end);
        update(2*node+2,mid+1,r,start,end);
        st[node].max_cons_one=max({st[2*node+1].max_cons_one,st[2*node+2].max_cons_one,st[2*node+1].right_one+st[2*node+2].left_one});
        st[node].max_cons_zero=max({st[2*node+1].max_cons_zero,st[2*node+2].max_cons_zero,st[2*node+1].right_zero+st[2*node+2].left_zero});
        st[node].left_one=st[2*node+1].left_one;
        if(st[2*node+1].left_one==(mid-l+1)){
            st[node].left_one+=st[2*node+2].left_one;
        }
        st[node].left_zero=st[2*node+1].left_zero;
        if(st[2*node+1].left_zero==(mid-l+1)){
            st[node].left_zero+=st[2*node+2].left_zero;
        }
        st[node].right_one=st[2*node+2].right_one;
        if(st[2*node+2].right_one==(r-(mid+1)+1)){
            st[node].right_one+=st[2*node+1].right_one;
        }
        st[node].right_zero=st[2*node+2].right_zero;
        if(st[2*node+2].right_zero==(r-(mid+1)+1)){
            st[node].right_zero+=st[2*node+1].right_zero;
        }
    }
    pair<node,int> query(int Node,int l,int r,int start,int end){
        if(lazy[Node]!=0){
            flip(Node,l,r);
            if(l!=r){
                lazy[2*Node+1]^=1;
                lazy[2*Node+2]^=1;
            }
            lazy[Node]=0;
        }
        if(l>=start && r<=end){
            return {st[Node],r-l+1};
        }
        if(l>end || r<start)
            return {node(),0};
        int mid=l+(r-l)/2;
        auto left1=query(2*Node+1,l,mid,start,end);
        auto right1=query(2*Node+2,mid+1,r,start,end);
        node left=left1.first,right=right1.first;
        node ans;
        ans.max_cons_one=max({left.max_cons_one,right.max_cons_one,left.right_one+right.left_one});
        ans.max_cons_zero=max({left.max_cons_zero,right.max_cons_zero,left.right_zero+right.left_zero});
        ans.left_one=left.left_one;
        if(left.left_one==left1.second){
            ans.left_one+=right.left_one;
        }
        ans.left_zero=left.left_zero;
        if(left.left_zero==left1.second){
            ans.left_zero+=right.left_zero;
        }
        ans.right_one=right.right_one;
        if(right.right_one==right1.second){
            ans.right_one+=left.right_one;
        }
        ans.right_zero=right.right_zero;
        if(right.right_zero==right1.second){
            ans.right_zero+=left.right_zero;
        }
        return {ans,left1.second+right1.second};
    }
};
/*-------------------------------------------------------------------------------------*/
void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    seg_tree *tree=new seg_tree(n);
    tree->build(0,0,n-1,s);
    // cout<<tree->query(0,0,n-1,3,5).first.max_cons_one<<endl;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int start,end;
            cin>>start>>end;
            start--; end--;
            tree->update(0,0,n-1,start,end);
        }else{
            int start,end;
            cin>>start>>end;
            start--; end--;
            cout<<tree->query(0,0,n-1,start,end).first.max_cons_one<<endl;
        }
    }
    // cout<<endl;/
}
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}