///hdu-1850

#include<cstdio>
#include<cstring>
#define maxn 110

int m;
int n[maxn];

int ret(int x)
{
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        if(i == x)continue;
        ans = ans ^ n[i];
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &m) && m)
    {
        memset(n, 0, sizeof(n));
        for(int i = 0; i < m; i++)
            scanf("%d", n + i);
        int ans = n[0];
        for(int i = 1; i < m; i++)
            ans = n[i] ^ ans;
        if(ans == 0)
        {
            printf("0\n");
            continue;
        }
        ans = 0;
        int tmp;
        for(int i = 0; i < m; i++)
        {
            tmp = ret(i);
            if(tmp < n[i])ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
