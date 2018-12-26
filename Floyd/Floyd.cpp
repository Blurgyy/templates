#include<cstdio>
#include<cstring>
#define maxn 210
#define INF 1000000009
#include<algorithm>
using namespace std;

int n, m;
int s, t;
int path[maxn][maxn];

void init()
{
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            if(i == j) path[i][j] = 0;
            else path[i][j] = INF;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        init();
        int x, y, dis;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &dis);
            path[x][y] = min(dis, path[x][y]);
            path[y][x] = min(dis, path[y][x]);
        }
        scanf("%d%d", &s, &t);
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
        if(path[s][t] != INF)printf("%d\n", path[s][t]);
        else printf("-1\n");
    }
    return 0;
}
