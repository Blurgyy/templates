///hdu-1730

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
using namespace std;

int n, m;
int st[maxn];

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        memset(st, 0, sizeof(st));
        int a, b;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            st[i] = max(a,b) - min(b,a) - 1;
        }
        int ans = st[0];
        for(int i = 1; i < n; i++)
            ans = st[i] ^ ans;
        //printf("%d\n", ans);
        if(ans)printf("I WIN!\n");
        else printf("BAD LUCK!\n");
    }
    return 0;
}
