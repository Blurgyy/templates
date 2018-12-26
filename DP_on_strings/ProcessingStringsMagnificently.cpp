const char *AGCT = "AGCT";
const int MOD = 10009;

///Input
int N, K;   ///K为禁止字符串S的长度
string S;

int nxt[MAX_K][4];
int dp[MAX_N+1][MAX_K];

void solve(){
    ///预处理
    for(int i = 0; i < K; ++ i){
        for(int j = 0; j < 4; ++ j){
            ///在S长度为i的前缀后添加一个字符
            string s = S.substr(0, i) + AGCT[j];
            ///反复删除第一个字符，直到成为S的前缀
            while(S.substr(0, s.length()) != s)
                s = s.substr(1);
            nxt[i][j] = s.length();
        }
    }

    ///dp边界初值

    dp[0][0] = 1;
    for(int i = 1; i < K; ++ i)
        dp[0][i] = 0;

    ///dp

    for(int t = 0; t < N; ++ t){
        //memset(dp[t+1], 0, sizeof(dp[t+1])); 
        for(int i = 0; i < K; ++ i)
            dp[t+1][i] = 0;
        for(int i = 0; i < K; ++ i){
            for(int j = 0; j < 4; ++ j){
                int ti = nxt[i][j];
                if(ti == K)continue;    ///不允许出现S
                dp[t+1][ti] = (dp[t+1][ti] + dp[t][i]) % MOD;
                ///((长度为t+1 && 有长度为ti的后缀(该后缀是S的前缀))的生成串)的个数 += ((长度为t && 有长度为i的后缀(该后缀是S的前缀))的生成串)的个数
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < K; ++ i)
        ans = (ans + dp[N][i]) % MOD;
    printf("%d\n", ans);
}