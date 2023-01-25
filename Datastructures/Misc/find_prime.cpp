#include<bits/stdc++.h>
using namespace std;
vector<int> sfm(1e6);
void make_sieve(){
    for(int i=1;i<=1e6;i++)
        sfm[i]=i;
    for(int i=2;i<=1e6;i++){
        if(sfm[i]==i){
            int mul=2;
            while(i*mul<=1e6){
                if(sfm[i*mul]==i*mul)
                    sfm[i*mul]=i;
                mul++;
            }
        }
    }
}
//this returns prime factorization of a number
vector<int> get_primes(int n){
    vector<int> primes;
    while(n!=1){
        primes.push_back(sfm[n]);
        n/=sfm[n];
    }
    return primes;
}
int main(){
    make_sieve();
    vector<int> ans=get_primes(24);
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;
}