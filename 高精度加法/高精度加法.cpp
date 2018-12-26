#include<stdio.h>
#include<string.h>
#define maxn 1010

int main(){
    char n1[maxn], n2[maxn];
    while(~scanf("%s%s", n1, n2)){
        char ans[maxn] = {0};
        int i = 0;
        int p1 = strlen(n1) - 1, p2 = strlen(n2) - 1;
        while(p1 >= 0 && p2 >= 0){
            ans[i++] = n1[p1--] - '0' + n2[p2--] - '0';
        }
        while(p1 >= 0){
            ans[i++] = n1[p1--] - '0';
        }
        while(p2 >= 0){
            ans[i++] = n2[p2--] - '0';
        }
        int j;
        for(j = 0; j < i; j++){
            if(ans[j] >= 10){
                ans[j] -= 10;
                ans[j+1]++;
            }
        }
        if(ans[j] > 0)i++;
        for(j = i-1; j >= 0; j--)
            printf("%d", ans[j]);
        printf("\n");
    }
    return 0;
}
