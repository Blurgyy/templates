//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 2610;
const int INF = 0x3f3f3f3f;
const char *agct = "AGCT";

int N, Case = 0, dp[maxn][maxn];
char in[25], dna[maxn];
struct Trie{
    int nxt[maxn][4],
        fail[maxn],
        size, root;
    bool finish[maxn];

    int idx(char ch){
        if(ch == 'A')return 0;
        if(ch == 'G')return 1;
        if(ch == 'C')return 2;
        return 3;
    }
    int newNode(){
        for(int i = 0; i < 4; ++ i)
            nxt[size][i] = 0;
        fail[size] = 0;
        finish[size] = false;
        return size++;
    }
    void init(){
        size = 1;
        root = newNode();
    }
    void insert(char *s){
        int now = root;
        while(*s){
            int index = idx(*s);
            if(!nxt[now][index])
                nxt[now][index] = newNode();
            now = nxt[now][index];
            ++ s;
        }
        finish[now] = true;
    }
    void Get_fail(){
        queue<int> Q;
        fail[root] = root;
        for(int i = 0; i < 4; ++ i){
            if(nxt[root][i]){
                Q.push(nxt[root][i]);
                fail[nxt[root][i]] = root;
            }
            else nxt[root][i] = root;
        }
        while(!Q.empty()){
            int now = Q.front();
            //printf("now = %d\n", now);
            Q.pop();
            finish[now] = (finish[now] || finish[fail[now]]);
            for(int i = 0; i < 4; ++ i){
                if(nxt[now][i]){
                    Q.push(nxt[now][i]);
                    fail[nxt[now][i]] = nxt[fail[now]][i];
                }
                else nxt[now][i] = nxt[fail[now]][i];
            }
        }
    }
    int meta(char *s){
        int len = strlen(s);
        memset(dp, 0x3f, sizeof(dp));
        dp[0][root] = 0;
        for(int i = 0; i < len; ++ i){
            for(int j = 1; j < size; ++ j){
                if(dp[i][j] < INF){
                    for(int k = 0; k < 4; ++ k){
                        int nStatus = nxt[j][k];
                        //printf("nStatus = %d\n", nStatus);
                        if(finish[nStatus])continue;
                        printf("ns = %d\n", nStatus);
                        dp[i+1][nStatus] = min(dp[i+1][nStatus], dp[i][j] + (k != idx(s[i])));
                    }
                }
            }
        }
        for(int i = 0; i <= len; ++ i){
            for(int j = 0; j < size; ++ j){
                printf("%11d", dp[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        int ans = INF;
        for(int i = 0; i < size; ++ i)
            ans = min(ans, dp[len][i]);
        return ans == INF ? -1 : ans;


    }
}ac;

int main(){
    while(~scanf("%d", &N)){
        ac.init();
        while(N--){
            scanf("%s", in);
            ac.insert(in);
        }
/*

*/
        ac.Get_fail();
        printf("nxt: \n");
        for(int i = 1; i < ac.size; ++ i){
            for(int j = 0; j < 4; ++ j)
                printf("%3d", ac.nxt[i][j]);
            printf("\n");
        }
/*
        printf("finish: ");
        for(int i = 0; i < ac.size; ++ i)
            printf(" %d", ac.finish[i]);
        printf("\n");
        printf("fail: ");
        for(int i = 0; i < ac.size; ++ i)
            printf(" %d", ac.fail[i]);
        printf("\n");
*/
        scanf("%s", dna);
        printf("Case %d: %d\n", ++ Case, ac.meta(dna));
    }
    return 0;
}