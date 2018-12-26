///suffixarray[i]: (以第i位为起始的)字符串后缀在所有后缀中，按照字典序排序后的下标
///rankarray[i]: 按照字典序排序后的所有后缀中，第i小的后缀的起始位置
///!!!每次刷新rankarray时也要重新把rnk[i].pos按顺序(0->len-1)刷一遍
/// :)

//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<algorithm>
#include<time.h>
#include<windows.h>
using namespace std;
const int maxn = 1000010;

struct entry{
    int tup[2], pos;
}rnk[maxn], tmp[maxn];
char s[maxn];
int sa[20][maxn], assis[30];

int idx(char ch){
    return ch - 'a';
}

void sort(entry arr[], int len){
    /*printf("in sort 1:\n");
    for(int i = 0; i < len; ++ i)
        printf("rnk[%d] = %d, %d, pos = %d\n", i, rnk[i].tup[0], rnk[i].tup[1], rnk[i].pos);
    printf("\n");
    getchar();*/
    memset(assis, 0, sizeof(assis));
    for(int i = 0; i < len; ++ i)
        ++ assis[arr[i].tup[1]];
    for(int i = 1; i < 30; ++ i)
        assis[i] = assis[i-1] + assis[i];
    for(int i = len - 1; i >= 0; -- i)
        tmp[--assis[arr[i].tup[1]]] = arr[i];
    memset(assis, 0, sizeof(assis));
    for(int i = 0; i < len; ++ i)
        ++ assis[tmp[i].tup[0]];
    for(int i = 1; i < 30; ++ i)
        assis[i] = assis[i-1] + assis[i];
    for(int i = len - 1; i >= 0; -- i)
        arr[--assis[tmp[i].tup[0]]] = tmp[i];
    /*printf("in sort 2:\n");
    for(int i = 0; i < len; ++ i)
        printf("rnk[%d] = %d, %d, pos = %d\n", i, rnk[i].tup[0], rnk[i].tup[1], rnk[i].pos);
    printf("\n");*/
}

int main(){
    system("title SuffixArray");
    while(~scanf("%s", s))
    {
        if(!strcmp(s, "cls")){
            system("cls");
            continue;
        }
        //scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len; ++ i)
            sa[0][i] = s[i] - 'a';
        for(int i = 0; i < len; ++ i)
            rnk[i].pos = i;
        /*
        for(int i = 0; i < len; ++ i)
            printf("%d ", sa[i]);
        printf("\n");
        */
        int stp = 1;
        for(int lg = 1; lg < len << 1; lg <<= 1, stp ++){
            for(int i = 0; i < len; ++ i){
                rnk[i].tup[0] = sa[stp-1][i];
                rnk[i].tup[1] = (i + lg < len) * (sa[stp-1][i+lg] + 1);
                rnk[i].pos = i;
            }
            sort(rnk, len);
            for(int i = 0; i < len; ++ i)
                sa[stp][rnk[i].pos] = i > 0 && rnk[i].tup[0] == rnk[i-1].tup[0] && rnk[i].tup[1] == rnk[i-1].tup[1] ? sa[stp][rnk[i-1].pos] : i;    
                ///...dont quite understand for now
            for(int i = 0; i < len; ++ i)
                printf("[%d] = <%2d, %2d>, %d\n", i, rnk[i].tup[0], rnk[i].tup[1], rnk[i].pos);
            for(int i = 0; i < len; ++ i)
                printf("sa[%d][%d] = %d\n", stp, i, sa[stp][i]);
            printf("\n");
        }
        stp --;
        printf("stp = %d\n", stp);
        printf("suffixarray: ");
        for(int i = 0; i < len; ++ i)
            printf("%d%c", sa[stp][i], " \n"[i == len-1]);
        printf("rankarray: ");
        for(int i = 0; i < len; ++ i)
            printf("%d%c", rnk[i].pos, " \n"[i == len-1]);
    }
    return 0;
}