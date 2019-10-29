#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;

int n, mod;
ll a[maxn][maxn];

ll det(ll a[][maxn], int n, int mod){
    ll ret = 1;
    char sign = 0;
    for(int i = 0; i < n; ++ i){    // using the i-th row to eliminate the corresponding elements following rows
        for(int j = i+1; j < n; ++ j){  // for every row after the i-th row
            int x = i;
            int y = j;
            while(a[y][i]){ // 辗转相除
                ll t = a[x][i] / a[y][i];
                for(int k = i; k < n; ++ k){
                    // a[x][k] -= t * a[y][k];
                    a[x][k] = (a[x][k] - t * a[y][k]) % mod;
                }
                swap(x, y);
            }
            if(x != i){ // 交换奇数次
                for(int k = i; k < n; ++ k){
                    swap(a[x][k], a[y][k]);
                }
                ret *= -1;  // 答案符号改变
            }
        }
        if(a[i][i] == 0){   // 本行消元后若对角线元素为 0 则答案为 0 
            return 0;
        }
        // ret *= a[i][i];
        ret = ret * a[i][i] % mod;
    }
    return (ret + mod) % mod;
}

int main(){
    while(~scanf("%d%d", &n, &mod)){
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                scanf("%lld", a[i] + j);
            }
        }
        ll ans = det(a, n, mod);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                printf("%4lld", a[i][j]);
            }
            printf("\n");
        }
        printf("%lld\n", ans);
    }
    return 0;
}
