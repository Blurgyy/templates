#include<cstdio>
#include<cstring>
#define maxn 10010
#define M 1000000007
#define ll long long
#include<algorithm>
using namespace std;

int n, t, k;
ll a[maxn], temp[maxn];

ll fp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(a, 0, sizeof(a));
        scanf("%d%d%d", &n, &t, &k);
        for(int i = 0; i < n; i++)
            scanf("%d", a + i);
        ll ans = fp(k, t);
        for(int i = 0; i < n; i++){
            if(i - (t%n) >= 0)
                temp[i] = a[i - (t%n)] * ans % M;
            else
                temp[i] = a[i + n - (t%n)] * ans % M;
        }
        for(int i = 0; i < n; i++)
            if(i == 0)printf("%lld", temp[0]);
            else printf(" %lld", temp[i]);
        printf("\n");
    }
    return 0;
}
