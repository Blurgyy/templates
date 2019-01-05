//好像不太靠谱。。
//我再找一个求逆元的

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n, m;

ll exgcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll ret = exgcd(b, a%b, x, y);
    ll t = x;
    x = y;
    y = t - (a/b) * y;
    return ret;
}

int main(){
    ll x, y;
    while(~scanf("%lld%lld", &n, &m)){
        exgcd(n, m, x, y);
        printf("%lld, %lld\n", x, y);
    }
    return 0;
}