///正int基数排序
///依此推广到负数/long long/etc.

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int mod = 10;//基数

int n, a[maxn], as[mod];

void radix_sort(int *now, int len, int *out){           //@brief *now: 被排序的数组; len: 被排序数组长度; *out: 存放最终的有序数组;
    int mx = -1, div = 1, *nxt;
    for(int i = 0; i < len; ++ i)
        mx = max(mx, now[i]);
    while(mx / div > 0){
        memset(as, 0, sizeof(as));
        for(int i = 0; i < len; ++ i)
            as[(now[i]/div)%mod] ++;
        for(int i = 1; i < mod; ++ i)
            as[i] += as[i-1];
        for(int i = len-1; i >= 0; -- i)
            nxt[--as[(now[i]/div)%mod]] = now[i];
        swap(now, nxt);
        div *= mod;
    }
    for(int i = 0; i < len; ++ i)
        out[i] = now[i];
}

int main(){
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++ i)
            scanf("%d", a + i);
        int tmp[maxn];
        radix_sort(a, n, a);
        for(int i = 0; i < n; ++ i)
            printf("%d%c", a[i], " \n"[i == n-1]);
    }
    return 0;
}