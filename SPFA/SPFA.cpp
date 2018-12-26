///hdu-1874

#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define maxn 205
#define INF 1e9
#include<algorithm>
using namespace std;

int n, m, s, t;
int d[maxn];
bool inq[maxn];
vector<pair<int, int> >E[maxn];

void init(){
    memset(inq, 0, sizeof(inq));
    for(int i = 0; i < n; i++)d[i] = INF;
    for(int i = 0; i < n; i++)E[i].clear();
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
        queue<int> que;
        que.push(s);
        inq[s] = true;
        while(!que.empty()){
            int now = que.front();
            que.pop();
            inq[now] = false;
            int total = E[now].size();
            for(int i = 0; i < total; i++){
                int v = E[now][i].first;
                if(d[v] > d[now] + E[now][i].second){
                    d[v] = d[now] + E[now][i].second;
                    if(inq[v])continue;
                    que.push(v);
                    inq[v] = true;
                }
            }
        }
        if(d[t] == INF)printf("-1\n");
        else printf("%d\n", d[t]);
    }
    return 0;
}