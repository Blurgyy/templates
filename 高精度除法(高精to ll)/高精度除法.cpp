///被除数高精度 除数为long long
#include<cstdio>
#include<cstring>
#define maxn 100010
#define ll long long
#include<algorithm>
using namespace std;

char n1[maxn], op;
ll n2;
char ans[maxn];
int p;
ll Ans;

int GetLen(ll n)
{
    int len = 0;
    while(n > 0)
    {
        n /= 10;
        len++;
    }
    return len;
}

void out(char * a)
{
    bool flag = false;
    for(int i = 0; i < p; i++)
        if(ans[i] != 0)
        {
            flag = true;
            break;
        }
    if(flag)
    {
        for(int i = 0; i < p; i++)
            if(ans[i] != 0)
            for(; i < p; i++)
                printf("%d", ans[i]);
    }
    else printf("0");
    printf("\n");
}

int main()
{
    while(~scanf("%s ", n1))
    {
        memset(ans, 0, sizeof(ans));
        p = 0;
        Ans = 0;
        scanf("%c", &op);
        getchar();
        scanf("%lld", &n2);
        int len = GetLen(n2);
        int LEN = strlen(n1);
        ///printf("LEN = %d\n", LEN);
        int top = 0;
        ///printf("len = %d\n", len);
        while(top < LEN)
        {
            while(GetLen(Ans) < len || Ans < n2)
            {
                Ans *= 10;
                Ans += n1[top++] - '0';
                if(top >= LEN)break;
                if(Ans < n2)ans[p++] = 0;
                ///printf("Current Ans = %lld.\n", Ans);
            }
            ans[p++] = Ans / n2;
            ///printf("Current ans[i] = %d, ", ans[p-1]);
            Ans %= n2;
            ///printf("Current top = %d, Ans = %lld.\n", top, Ans);
        }
        ///printf("op = %c.\n", op);
        if(op == '/')out(ans);
        else /**if(op == '%')*/printf("%lld\n", Ans);
    }
    return 0;
}


/**
123456 / 12
110 / 100
99 % 10
2147483647 / 2147483647
2147483646 % 2147483647
*/
