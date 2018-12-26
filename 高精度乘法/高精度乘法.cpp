#include<cstdio>
#include<cstring>
#define maxn 510
#include<algorithm>
using namespace std;

int n1[maxn], n2[maxn];
char N1[maxn], N2[maxn];
char Ans[maxn];
int ans[maxn];

void rev(char * a)
{
    int len = strlen(a);
    for(int i = 0; i < len/2; i++)
        swap(a[i], a[len-i-1]);
}

void out(int len)
{
    int first;
    for(int i = 0; i < len; i++)
        if(ans[i] != 0)
        {
            first = i;
            break;
        }
    for(int i = first; i < len; i++)
        printf("%d", ans[i]);
    printf("\n");
}

int main()
{
    while(~scanf("%s%s", N1, N2))
    {
        memset(ans, 0, sizeof(ans));
        memset(Ans, 0, sizeof(Ans));
        rev(N1);
        rev(N2);
        int len1 = strlen(N1), len2 = strlen(N2);
        for(int i = 0; i < len1; i++)
            n1[i] = N1[i];
        for(int i = 0; i < len2; i++)
            n2[i] = N2[i];
        for(int i = 0; i < len1; i++)
            for(int j = 0; j < len2; j++)
            {
                if(ans[i+j] == 0)
                    ans[i+j] += (n1[i] - '0') * (n2[j] - '0');
                else ans[i+j] += (n1[i] - '0') * (n2[j] - '0');
            }
        int len = len1 + len2;
        for(int i = 0; i < len; i++)
            while(ans[i] > 9)
            {
                ans[i] -= 10;
                ans[i+1]++;
            }
        for(int i = 0; i < len / 2; i++)
            swap(ans[i], ans[len-1-i]);
        out(len);
    }
    return 0;
}
