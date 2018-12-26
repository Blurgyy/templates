#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int a[maxn], N, se;

int bs(int left, int right, int e){
	if(left >= right)return right;
	int mid = (left + right)>>1;
	if(a[mid] >= e)return bs(left, mid, e);
	return bs(mid+1, right, e), se;
}

int main(){
	while(~scanf("%d", &N)){
		for(int i = 0; i < N; ++ i)
			scanf("%d", a + i);
		scanf("%d", &se);
		printf("a[%d] = %d\n", bs(0, N-1, se), a[bs(0, N-1, se)]);
	}
	return 0;
}