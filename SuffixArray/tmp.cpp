//suffix array: only lower-case letters allowed(can be improved)

//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100010;

struct entry{
    pii tuple;
    int pos;
};
char s[maxn];
int sa[20][maxn], assis[26];
entry Rank[maxn];

void radix_sort(entry arr[], int len){
    memset(assis, 0, sizeof(assis));
    entry *tmp = (entry*) malloc(len * sizeof(entry));
    for(int i = 0; i < len; ++ i)
        assis[arr[i].tuple.second] ++;
    for(int i = len-1; i >= 0; -- i)
        tmp[--assis[arr[i].tuple.second]] = arr[i];
    memset(assis, 0, sizeof(assis));
    for(int i = 0; i < len; ++ i)
        assis[tmp[i].tuple.first] ++;
    for(int i = len-1; i >= 0; -- i)
        arr[--assis[tmp[i].tuple.second]] = tmp[i];
}

int main(){
    while(~scanf("%s", s)){
        int len = strlen(s);
        for(int i = 0; i < len; ++ i)
            sa[0][i] = s[i] - 'a';
        int cnt = 1;
        for(int stp = 1; cnt < len; cnt <<= 1, ++ stp){
            for(int i = 0; i < len; ++ i){
                Rank[i].tuple = make_pair(sa[stp-1][i], i > cnt ? sa[stp-1][i+cnt] : -1);
                Rank[i].pos = i;
            }
            radix_sort(Rank, len);
            for(int i = 0; i < len; ++ i)
                sa[stp][Rank[i].pos] = i;
        }
        for(int stp = 0; stp < cnt; ++ stp){
            for(int i = 0; i < len; ++ i)
                printf("%d ", sa[stp][i]);
            printf("\n");
        }
        printf("end.\n");
    }
    return 0;
}