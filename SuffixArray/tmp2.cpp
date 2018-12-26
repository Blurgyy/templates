#include <cstdio>
#include <cstring>
#include <malloc.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct entry{
    int tup[2], p;
}rk[maxn];
char s[maxn];
int sa[20][maxn];
int len;

bool operator<(entry a, entry b){
    if(a.tup[0] < b.tup[0])return true;
    if(a.tup[0] > b.tup[0])return false;
    return a.tup[1] < b.tup[1];
}

void rsort(entry arr[], int len){
    for(int i = 0; i < len; ++ i)
        arr[i].tup[0] += 1, arr[i].tup[1] += 1;
    int *assis = new int[max(26, len)];
    entry *tmp = new entry[len];
    memset(assis, 0, sizeof(assis));
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < len; ++ i)
        assis[arr[i].tup[1]] ++;
    for(int i = 1; i < len; ++ i)
        assis[i] += assis[i-1];
    /**/
    for(int i = len-1; i >= 0; -- i){
        printf("assis[%d] = %d\n", arr[i].tup[1], assis[arr[i].tup[1]]);
        tmp[--assis[arr[i].tup[1]]] = arr[i];
    }
    memset(assis, 0, sizeof(assis));
    /**/
    for(int i = 0; i < len; ++ i)
        assis[tmp[i].tup[0]] ++;
    for(int i = 1; i < len; ++ i)
        assis[i] += assis[i-1];
    for(int i = len-1; i >= 0; --i)
        arr[--assis[tmp[i].tup[0]]] = tmp[i];
    delete []assis;
    delete []tmp;
}

void out(int lev){
    for(int i = 0; i < len; ++ i)
        printf("%d%c", sa[lev][i], " \n"[i == len-1]);
    printf("\n");
}

int main(){
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    while(~scanf("%s", s)){
        if(!strcmp(s, "\\cls")){
            system("cls");
            continue;
        }
        len = strlen(s);
        for(int i = 0; i < len; ++ i)
            sa[0][i] = s[i] - 'a';
        out(0);
        int stp, cnt;
        for(stp = 1, cnt = 1; cnt >> 1 < len; ++ stp, cnt <<= 1){
            for(int i = 0; i < len; ++ i){
                rk[i].tup[0] = sa[stp-1][i];
                if(i + cnt < len)
                    rk[i].tup[1] = sa[stp-1][i+cnt];
                else rk[i].tup[1] = -1;
                rk[i].p = i;
            }
            //sort(rk, rk + len);
            rsort(rk, len);
            for(int i = 0; i < len; ++ i){
                //P[stp][L[i].p] = i > 0 && L[i].tup[0] == L[i - 1].tup[0] && L[i].tup[1] == L[i - 1].tup[1] ? P[stp][L[i - 1].p] : i; 
                if(i > 0 && rk[i].tup[0] == rk[i-1].tup[0] && rk[i].tup[1] == rk[i-1].tup[1])
                    sa[stp][rk[i].p] = sa[stp][rk[i-1].p];
                else 
                    sa[stp][rk[i].p] = i;
            }

            out(stp);

        }
        for(int i = 0; i < len; ++ i)
            printf("%d ", sa[stp-1][i]);
        printf("\n666\n");
    }
    return 0;
}

/**


testestestest

*/