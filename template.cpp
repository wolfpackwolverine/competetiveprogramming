#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define maxn 1e6

ll fac[maxn];
ll inv[maxn];

ll gcd (ll a,ll  b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll mul(ll a, ll b) {
    return (a * 1LL * b) % mod;
}

ll exp(ll a, ll x){    //exp(a,m-2) = mudular inverse of a
    if (x == 0) return 1ll;
    ll p = exp(a,x/2);
    p = (p*p)%mod;
    if (x & 1){
        p = (p*a)%mod;
    }
    return p;
}
ll nCr(int n, int r){
    return ((fac[n]*inv[n-r])%mod*inv[r])%mod;
}
void factorial(){
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= maxn; i++){
        fac[i] = (i*fac[i-1])%mod;
        inv[i] = exp(fac[i],mod-2); // when mod is prime 
    }
}

int main(){
    fastio
}
