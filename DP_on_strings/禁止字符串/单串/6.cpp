#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int mod = 10009;
const char *agct = "AGCT";

int n;
int nxt[35][4], dp[maxn][35];
string forb;

void prep(){
    int len = forb.size();
    memset(nxt, 0, sizeof(nxt));
    for(int i = 0; i < len; ++ i){
        for(int j = 0; j < 4; ++ j){
            string s = forb.substr(0, i) + agct[j];
            while(forb.substr(0, s.size()) != s)
                s = s.substr(1);
            nxt[i][j] = s.size();
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
}

int main(){
    while(cin >> forb >> n){
        prep();
        int len = forb.size();
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
