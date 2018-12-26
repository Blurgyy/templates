#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

#define maxn 100010
typedef unsigned long long ull;
struct StringHasher{
    ull seed;
    int len;
    char s[maxn];
    ull h[maxn], _[maxn];
    StringHasher(ull _seed = 998244353):
        seed(_seed){
        _[0] = 1;
        if(!_[1]){
            for(int i = 1; i < maxn; ++ i){
                _[i] = _[i-1] * seed;
            }
        }
    }

    ull getHash(int l, int r){  ///gets substring[l, r]'s Hash value in O(1)
        return h[l] - h[r+1] * _[r-l+1];
    }
    bool check(int x, int y, int length){   ///substring[x, x+len-1] == substring[y, y+len-1] ? true : false
        ull h1 = getHash(x, x + length - 1);
        ull h2 = getHash(y, y + length - 1);
        return h1 == h2;
    }
    int bs(int x, int y, int left, int right){
        if(left >= right)return right;
        int mid = (left + right + 1) / 2;       ///upper_bound
        if(check(x, y, mid))return bs(x, y, mid, right);
        return bs(x, y, left, mid - 1);
    }
    int lcp(int x, int y){      ///returns length of the longest common prefix of suffix[x] and suffix[y]
        int minl = 0;
        int maxl = max(0, min(len - x + 1, len - y + 1));
        return bs(x, y, minl, maxl);
    }
    void init(char *s){
        len = strlen(s);
        h[len] = 0;
        for(int i = len-1; i >= 0; -- i){
            h[i] = h[i+1] * seed + s[i];
        }
    }
}hasher(1e9+7), hasher_(1e9+9), hasher__;
#undef maxn

int n, x, y;
char s[maxn];

int main(){
    while(~scanf("%s", s)){
        hasher.init(s);
        hasher_.init(s);
        hasher__.init(s);
        scanf("%d", &n);
        while(n --){
            scanf("%d%d", &x, &y);
            int lcp = hasher.lcp(x, y);
            int lcp_ = hasher_.lcp(x, y);
            if(lcp == lcp_){
                lcp = hasher__.lcp(x, y);
            }
            if(lcp){
                for(int i = 0; i < lcp; ++ i){
                    printf("%c", s[x+i]);
                }
                printf("\n");
            }
            else {
                printf("no such string.\n");
            }
        }
    }
    return 0;
}