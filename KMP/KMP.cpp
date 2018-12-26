#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#define maxn 10010
using namespace std;

void get_next(string a, int next[])
{
    memset(next, 0, sizeof(next));
    int lena = a.size();
    int j = -1, i = 0;
    next[0] = -1;
    while(i < lena-1)
    {
        if(j == -1 || a[i] == a[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else j = next[j];
    }
}

int next[maxn];
string a, b;

int main()
{
    while(cin >> a >> b)
    {
        get_next(a, next);
        int ans = 0;
        int p = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(b[p] == a[i])ans++;
            if(ans == a.size())break;
            if(b[p] != a[i])
            {
                i = next[i];
                ans = next[i];
            }
            p++;
        }
        printf("ans = %d\n", ans);
        for(int i = 0; i < a.size(); i++)
            printf("%3c", a[i]);
        printf("\n");
        for(int i = 0; i < a.size(); i++)
            printf("%3d", next[i]);
        printf("\n\n");
    }
    return 0;
}


/**

Release 16.01  rev 10702 (2016-01-25 19:50:14)   gcc 4.9.2 Windows/unicode - 32 bitRelease 16.01  rev 10702 (2016-01-25 19:50:14)   gcc 4.9.2 Windows/unicode - 32 bitRelease 16.01  rev 10702 (2016-01-25 19:50:14)   gcc 4.9.2 Windows/unicode - 32 bit

*/
