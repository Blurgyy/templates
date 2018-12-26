///hdu-1874

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define maxn 205
#define INF 1e9
using namespace std;

int n, m, s, t;
int d[maxn];
vector<pair<int, int> > E[maxn];

void init(){
    for(int i = 0; i < n; i++)E[i].clear();
    for(int i = 0; i < n; i++)d[i] = INF;
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        int x, y, z;
        while(m--){
            scanf("%d%d%d", &x, &y, &z);
            E[x].push_back(make_pair(y, z));
            E[y].push_back(make_pair(x, z));
        }
        scanf("%d%d", &s, &t);
        d[s] = 0;
        priority_queue<pair<int, int> > Q;
        Q.push(make_pair(-d[s], s));
        while(!Q.empty()){
            int now = Q.top().second;
            Q.pop();
            int len = E[now].size();
            for(int i = 0; i < len; i++){
                int v = E[now][i].first;
                if(d[v] > d[now] + E[now][i].second){
                    d[v] = d[now] + E[now][i].second;
                    Q.push(make_pair(-d[v], v));
                }
            }
        }
        if(d[t] == INF)printf("-1\n");
        else printf("%d\n", d[t]);
    }
    return 0;
}
