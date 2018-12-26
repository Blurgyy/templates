#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int mod = 10009;
const char *agct = "AGCT";

char forb[maxn];
int nxt_arr[maxn], dp[maxn][maxn], nxt[maxn][4];
int len, n;

int idx(char ch){
    switch(ch){
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
    }
    return 3;
}

void kmp_prep(char *s){
    int lens = strlen(s);
    int i = 0, j = -1;
    memset(nxt_arr, 0, sizeof(nxt_arr));
    nxt_arr[0] = -1;
    while(i <= len){
        if(j == -1 || s[i] == s[j])
            nxt_arr[++i] = ++ j;
        else j = nxt_arr[j];
    }
}

void out(){
    for(int i = 0; i <= len; ++ i)
        printf("%d ", nxt_arr[i]);
    printf("\n");
}
/*
void prep(){///预处理(用于dp的)nxt数组
    len = strlen(forb);
    kmp_prep(forb);
    out();
    memset(nxt, 0, sizeof(nxt));
    int first_ch = idx(forb[0]);
    for(int i = 0; i < len; ++ i){
        for(int j = 0; j < 4; ++ j){
            if(forb[nxt_arr[i+1]] == agct[j])//e.g. AAGAAGCT
                nxt[i][j] = nxt_arr[i+1] + 1;
            else nxt[i][j] =
        }
    }
}
*/

void prep(){
    string pat = forb;
    int len = pat.size();
    for(int i = 0; i < len; ++ i){
        for(int j = 0; j < 4; ++ j){
            string s = pat.substr(0, i) + agct[j];
            while(pat.substr(0, s.size()) != s)
                s = s.substr(1);
            nxt[i][j] = s.size();
            printf("nxt[%d][%d] = %d\t", i, j, nxt[i][j]);
        }
        printf("\n");
    }
}

int main(){
    while(~scanf("%s%d", forb, &n)){
        prep();
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        len = strlen(forb);
        /*
        for(int i = 0; i < len; ++ i){
            for(int j = 0; j < n; ++ j){
                for(int k = 0; k < 4; ++ k){
                    int cur = nxt[i][k];
                    printf("cur = %d\n", cur);
                    if(cur == len)continue;
                    dp[j+1][cur] = (dp[j][i] + dp[j+1][cur]) % mod;
                    //printf("%d\n", dp[j+1][cur]);
                }
            }
        }
        */
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < len; ++ j){
                for(int k = 0; k < 4; ++ k){
                    int cur = nxt[j][k];
                    if(cur == len)continue;
                    dp[i+1][cur] = (dp[i+1][cur] + dp[i][j]) % mod;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < len; ++ i)
            ans = (ans + dp[n][i]) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
