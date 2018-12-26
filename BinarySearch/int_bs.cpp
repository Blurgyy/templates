#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
char out[2][30] = {"Not Exist", "Exist"};

template<typename T>
int bs(T e, T arr[], int left, int right){      /*@brief 寻找元素e在数组arr中的下标
                                                 *@param 寻找元素/目标数组/二分区间左侧/二分区间右侧
                                                 *@return (upper_bound)
                                                 */
    if(left >= right)return right;
    int mid((left + right) >> 1);
    if(e <= arr[mid])return bs(e, arr, left, mid);
    return bs(e, arr, mid + 1, right);
}

template<typename T>
bool check(T e, T arr[], int left, int right){  /*@brief 检查元素e是否存在于数组arr中
                                                 *@param 
                                                 *@return 
                                                 */
    return arr[bs(e, arr, left, right)] == e;
}

int main(){
    int n, a[maxn];
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++ i)
            scanf("%d", a + i);
        sort(a, a + n);
        n = unique(a, a + n) - a;
        for(int i = 0; i < 100000000; ++ i){
            if(check(i, a, 0, n))printf("%d exists\n", i);
        }
    }
    return 0;
}