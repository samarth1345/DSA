#define ll long long int
vector<ll> fact,inv_fact;
const ll Mod=1e9+7;
ll ModPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % Mod;
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = (res*a)%Mod;
        a = (a*a)%Mod;
        b = b / 2;
    }
    return res;
}
ll nCr(ll n, ll r)
{
    ll div=(fact[r]*fact[n-r])%Mod;
    ll div_inv=ModPow(div,Mod-2);
    return (fact[n]*div_inv)%Mod;
}
void precalc(ll N)
{
    fact.resize(N+1);
    inv_fact.resize(N+1);
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1]*i)%Mod;
    }
    inv_fact[N - 1]=ModPow(fact[N-1],Mod-2);
    for (ll i = N - 2; i >= 0; i--)
    {
        inv_fact[i] =(inv_fact[i + 1]*(i + 1))%Mod;
    }
}