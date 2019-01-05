#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll n, k;

ll fpow(ll x, ll k, ll mod = mod){
    ll a = x;
    ll ret = 1;
    while(k){
        if(k & 1){
            ret = ret * a % mod;
        }
        a = a * a % mod;
        k >>= 1;
    }
    return ret;
}

ll inv(ll x){
    return fpow(x, mod - 2);
}

int main(){
    while(~scanf("%lld", &n)){
        printf("inv(%lld) = %lld\n", n, inv(n));
    }
}