#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const char *agct = "AGCT";

char forb[30];
int n, len, nxt[maxn], dp[maxn][maxn];
int nxt_arr[35];

int idx(char ch){
    switch(ch){
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
    }
    return 3;
}

void Get_next(char *s){
    int i = 0, j = -1;
    memset(nxt_arr, 0, sizeof(nxt_arr));
    nxt_arr[0] = -1;
    while(i <= len){
        if(j == -1 || s[i] == s[j]){
            nxt_arr[++i] = ++ j;
            /*if(s[i] == s[j])
                nxt_arr[i] = nxt_arr[j];*/
        }
        else j = nxt_arr[j];
    }
}

void output(){
    for(int i = 0; i <= len; ++ i)
        printf("%d ", nxt_arr[i]);
    printf("\n");
}

void prep(){
    Get_next(forb);
    output();
}

int main(){
    while(~scanf("%s%d", forb, &n)){
        len = strlen(forb);
        prep();

    }
    return 0;
}