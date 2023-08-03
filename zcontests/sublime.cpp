#include "bits/stdc++.h"
#define endl "\n"
#define int long long int
#define MAX 1e18
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
/*-------------------------------------------------------------------------------------*/
void solve(){
    for(int i=1;i<(1<<4);i++){
        string temp="";
        for(int j=3;j>=0;j--){
            if((i&(1<<j)) != 0)
                cout<<1;
            else
                cout<<0;
        }
        cout<<endl;
    }
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