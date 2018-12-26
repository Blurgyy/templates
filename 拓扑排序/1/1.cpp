#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 510
using namespace std;

int n, m;
int mp[maxn][maxn];
int degree[maxn];
int ans[maxn];
int p;

void init(){
    memset(mp, 0, sizeof(mp));
    memset(degree, 0, sizeof(degree));
    memset(ans, 0, sizeof(ans));
    p = 0;
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        int u, v;
        while(m--){
            scanf("%d%d", &u, &v);
            if(mp[u][v] == 0){
                mp[u][v]++;
                degree[v]++;
            }
        }
        while(p < n){
            int pos = 0;
            for(int i = 1; i <= n; i++)
                if(!degree[i]){
                    pos = i;
                    degree[i] = -2;
                    break;
                }
            for(int i = 1; i <= n; i++)
                if(mp[pos][i] > 0){
                    mp[pos][i] = -1;
                    degree[i]--;
                }
            ans[p++] = pos;
        }
        for(int i = 0; i < p; i++)
            if(!i)printf("%d", ans[i]);
            else printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
