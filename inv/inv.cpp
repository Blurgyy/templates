//Time complexity = O(n)

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int Get_inv(int n){
	if(n == 1)return 1;
	return (mod - mod / n) * Get_inv(mod % n) % mod;
}

int main(){
	int n;
	while(~scanf("%d", &n)){
		printf("inv(n) = %d\n", Get_inv(n));
	}
	return 0;
}