///挖草开心基本算是第一个自己写出的矩阵快速幂开心开心
///严肃
///比赛完了再看看


///这是10x10矩阵。。
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20
#define ll long long
using namespace std;

ll k;
int m;

struct line
{
    int a[maxn];
    void print()
    {
        printf("line:\n");
        for(int i = 0; i < 10; i++)
            printf("%3d", a[i]);
        printf("\n");
    }
};

struct matrix
{
    int m[maxn][maxn];
    void print()
    {
        printf("matrix:\n");
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
                printf("%3d", m[i][j]);
            printf("\n");
        }
    }
};



line operator * (line a, matrix b)
{
    line ret;
    memset(ret.a, 0, sizeof(ret.a));
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            ret.a[i] += a.a[j] * b.m[j][i];
            ret.a[i] %= m;
        }
    return ret;
}

matrix operator * (matrix a, matrix b)
{
    matrix ret;
    memset(ret.m, 0, sizeof(ret.m));
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10; k++)
            {
                ret.m[i][j] += a.m[i][k] * b.m[k][j];
                ret.m[i][j] %= m;
            }
    return ret;
}

matrix pow(matrix a, ll n)
{
    matrix ret;
    memset(ret.m, 0, sizeof(ret.m));
    for(int i = 0; i < 10; i++)
        ret.m[i][i] = 1;
    while(n)
    {
        if(n & 1)ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}

int main()
{
    while(~scanf("%lld%d", &k, &m))
    {
        matrix mat;
        matrix Ans;
        line ans;
        for(int i = 0; i < 10; i++)
            ans.a[i] = 10 - i - 1;
        memset(mat.m, 0, sizeof(mat.m));
        for(int i = 0; i < 10; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            mat.m[i][0] = tmp;
        }
        for(int i = 1; i < 10; i++)
            mat.m[i-1][i] = 1;
        Ans = pow(mat, k - 9);
        ans = ans * Ans;
        printf("%d\n", ans.a[0]);
    }
    return 0;
}
