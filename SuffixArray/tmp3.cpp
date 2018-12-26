#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000010;
const int maxlog = 20;

struct entry{
    int tup[2], pos;
    entry(){tup[0] = tup[1] = pos = 0;}
    bool operator< (entry b){
        return tup[0] == b.tup[0] ? tup[1] < b.tup[1] : tup[0] < b.tup[0];
    }
}sa[maxn];
int len, stp;
int rk[maxlog][maxn], height[maxn];
char s[maxn];

int assis[maxn];

void rsort(entry *start, entry *end){
    for(entry *i = start; i < end; ++ i)

}

void out(int idx){
    printf("\n");
    for(int i = 0; i < len; ++ i)
        printf("%d\t%s\n", height[i], s + sa[i].pos);
    printf("\n");
}

int calc(int pos){
    int i, j;
    for(i = sa[pos-1].pos, j = sa[pos].pos; i < len && j < len; ++ i, ++ j)
        if(s[i] != s[j])return j - sa[pos].pos;
    return min(i, j) - min(sa[pos-1].pos, sa[pos].pos);
}

void getsa(){
    len = strlen(s);
    for(int i = 0; i < len; ++ i)
        rk[0][i] = s[i] - 'a';
    stp = 1;
    for(int cnt = 1; cnt >> 1 < len; cnt <<= 1, ++ stp){
        for(int i = 0; i < len; ++ i){
            sa[i].tup[0] = rk[stp-1][i];
            if(i + cnt >= len)
                sa[i].tup[1] = -1;
            else 
                sa[i].tup[1] = rk[stp-1][i+cnt];
            sa[i].pos = i;
        }
        sort(sa, sa + len);
        for(int i = 0; i < len; ++ i){
            if(i > 0 && sa[i].tup[0] == sa[i-1].tup[0] && sa[i].tup[1] == sa[i-1].tup[1])
                rk[stp][sa[i].pos] = rk[stp][sa[i-1].pos];
            else 
                rk[stp][sa[i].pos] = i;
        }
    }
    stp -= 1;
    for(int i = 1; i < len; ++ i)
        height[i] = calc(i);
}

int main(){
    memset(height, 0, sizeof(height));
    while(~scanf("%s", s)){
        getsa();
        out(stp);
    }
    return 0;
}

/**

zyxwvutsrqponmlkjihgfedcba

*/