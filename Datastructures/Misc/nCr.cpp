#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
const int N = 2e5 + 2;
int fact[N],inv_fact[N];
ll mod(ll x){
    return ((x % M + M) % M);
}
ll add(ll a, ll b){
    return mod(mod(a) + mod(b));
}
ll mul(ll a, ll b){
    return mod(mod(a) * mod(b));
}
ll modPow(ll a, ll b){
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % M;
    ll res = 1;
    while (b){
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}
ll inv(ll x){
    return modPow(x, M - 2);
}
ll divide(ll a, ll b){
    return mul(a, inv(b));
}
ll nCr(ll n, ll r){
    return divide(fact[n], mul(fact[r], fact[n - r]));
}
void precalc(){
    fact[0] = 1;
    for (int i = 1; i < N; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    inv_fact[N-1]=divide(1LL,fact[N-1]);
    for(int i=N-2;i>=0;i--){
        inv_fact[i]=mul(inv_fact[i+1],i+1);
    }
}
int main(){
    precalc();
    cout<<fact[10];
}