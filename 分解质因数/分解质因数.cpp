#include<stdio.h>
int main()
{
    int i,n,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=2;i<=n;i++)
        {
            for(;;)
            {
                if(n%i==0)
                {
                    printf("%d",i);
                    n=n/i;
                    if(n!=1)printf("*");
                }
                else break;
            }
        }
        printf("\n");
    }
    return 0;
}
