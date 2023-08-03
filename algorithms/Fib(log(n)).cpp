 int Mod=1e9+7;
 unordered_map<ll,ll> Fib;
 ll fib(ll n)
 {
     if(n<2) return 1;
     if(Fib.find(n) != Fib.end()) return Fib[n];
     ll one=fib((n+1) / 2)%Mod;
     ll two=fib(n/2)%Mod;
     ll thre=fib((n-1) / 2)%Mod;
     ll four=fib((n-2) / 2)%Mod;
     Fib[n]=((one*two)%Mod + (thre*four)%Mod) % Mod;
     return Fib[n];
 }