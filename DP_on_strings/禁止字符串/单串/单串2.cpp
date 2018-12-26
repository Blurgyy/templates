#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int mod = 10009;
const char *agct = "AGCT";

string forb;
int n, nxt[maxn][4];///nxt[i][j]: 在forb的长度为i的前缀后添加字符agct[j]所生成的字符串的后缀中，同时还是forb的前缀的最长的串的长度
int dp[maxn][maxn]; ///dp[i][j]: 长度为i，有长度为j的后缀且该后缀是禁止字符串forb的前缀的串的个数

int idx(char ch){
    switch(ch){
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
    }
    return 3;
}

void prep(){
    memset(nxt, 0, sizeof(nxt));
    int len = forb.size();
    for(int i = 0; i < len; ++ i){
        for(int j = 0; j < 4; ++ j){
            string s = forb.substr(0, i) + agct[j];
            while(forb.substr(0, s.size()) != s)
                s = s.substr(1);
            nxt[i][j] = s.size();
            printf("nxt[%d][%d] = %d\t", i, j, s.size());
        }
        printf("\n");
    }
}

int main(){
    while(cin >> forb >> n){
        prep();
        ///memset(dp[0], 0, sizeof(dp[0]));
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int len = forb.size();
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < len; ++ j){
                for(int k = 0; k < 4; ++ k){
                    int cur = nxt[j][k];
                    printf("nxt[%d][%d] = %d\n", j, k, cur);
                    if(cur == len)continue;
                    dp[i+1][cur] = (dp[i][j] + dp[i+1][cur]) % mod;
                    printf("dp[%d][%d] = dp[%d][%d] + dp[%d][%d] = %d, ", i+1, cur, i, j, i+1, cur, dp[i+1][cur]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < len; ++ i){
            ans = (ans + dp[n][i]) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}


