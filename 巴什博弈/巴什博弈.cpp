///hdu-1856

#include<cstdio>
#include<cstring>

int n, m, c;

int main()
{
    scanf("%d", &c);
    while(c--)
    {
        bool ans = true;
        scanf("%d%d", &n, &m);
        if(n % (m+1) == 0)ans = false;
        if(ans)printf("first\n");
        else printf("second\n");
    }
    return 0;
}
