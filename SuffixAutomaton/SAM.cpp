#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

struct SuffixAutomaton {
    int to[maxn][30], fail[maxn], step[maxn];
    int last, Tcnt, sum;
    int Q[maxn];
    int Qcnt;
    int Extend(int key) {
        step[++Tcnt] = step[last] + 1;
        int p = last, u = Tcnt;
        memset(to[u], 0, sizeof to[u]);
        for (; !to[p][key]; p = fail[p]) to[p][key] = u;
        if (!p) {
            fail[u] = 1;
        } else {
            int q = to[p][key];
            if (step[q] != step[p] + 1) {
                step[++Tcnt] = step[p] + 1;
                int v = Tcnt;
                memset(to[v], 0, sizeof to[v]);
                memcpy(to[v], to[q], sizeof to[q]);
                fail[v] = fail[q];
                fail[q] = fail[u] = v;
                for (; to[p][key] == q; p = fail[p])
                    to[p][key] = v;
            } else {
                fail[u] = q;
            }
        }
        last = u;
        return sum += step[last] - step[fail[last]]; 
    }
    void Init(char *S, int len) {
        Tcnt = last = 1; sum = 0;
        for(int i = 0; i < len; i++)
            Extend(S[i] - st);  ///so wtf is this "st"
    }
    inline void Print(void) {
        for (int i = 0; i < Qcnt; i++)
            putchar(Q[i] + st);
        puts("");
    }
    void dfs(int u) {
        for (int i = 0; i < 26; i++)
            if (to[u][i]) {
                Q[Qcnt++] = i;
                Print();
                dfs(to[u][i]);
                --Qcnt;
            }
    }
    void Debug(void) {
        Qcnt = 0; dfs(0);
    }
    void Clear(void) {
        Tcnt = last = 1; sum = 0;
        memset(to[1], 0, sizeof to[1]);
    }
};

int main(){

    return 0;
}