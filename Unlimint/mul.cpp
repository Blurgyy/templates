#include<bits/stdc++.h>
/*#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>*/
using namespace std;
const int maxn = 1010;

class Unlimint
{
    bool sign;//0+,1-
    vector<int> num;
public:
    Unlimint operator* (Unlimint &a);
    Unlimint delzero(){}
    int size(){
        return num.size();
    }
};
/*
Unlimint Unlimint::operator* (Unlimint &a){
    Unlimint ret;
    ret.sign = (sign ^ a.sign);
    int size1 = num.size(), size2 = a.size();
    int cur_size = size1 + size2;
    ret.num.assign(cur_size + 4, 0);
    for(int i = 0; i < size1; ++ i)
        for(int j = 0; j < size2; ++ j)
            ret[i+j] += num[i] * a[j];
    for(int i = 0; i < cur_size; ++ i){
        if(ret[i] > 9){
            ret[i+1] += ret[i] / 10;
            ret[i] %= 10;
        }
    }
    ret.delzero();
    return ret;
}
*/
int main(){
    int size1, size2;
    int n1[maxn], n2[maxn];
    char N1[maxn], N2[maxn];
    while(~scanf("%s%s", N1, N2)){
        size1 = strlen(N1), size2 = strlen(N2);
        for(int i = 0; i < size1; ++ i)
            n1[i] = N1[i] - '0';
        for(int i = 0; i < size2; ++ i)
            n2[i] = N2[i] - '0';
        vector<int> a, b, ret;
        a.assign(n1, n1 + size1);
        b.assign(n2, n2 + size2);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        ret.assign(size1 + size2 + 4, 0);
        for(int i = 0; i < size1; ++ i)
            for(int j = 0; j < size2; ++ j)
                ret[i+j] += a[i] * b[j];
        for(int i = 0; i < size1 + size2; ++ i)
            if(ret[i] > 9){
                ret[i+1] += ret[i] / 10;
                ret[i] %= 10;
            }
        int start;
        for(start = size1 + size2 - 1; start > 0; -- start)
            if(ret[start])break;
        for(int i = start; i >= 0; -- i)
            printf("%d", ret[i]);
        printf("\n");
    }

    return 0;
}