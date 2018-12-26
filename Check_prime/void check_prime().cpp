#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

bool check_prime(int n)
{
    if(n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;
    for(int i = 3; i*i <= n; i++)
        if(n % i == 0)return false;
    return true;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(check_prime(n))printf("%d is a prime number.\n", n);
        else printf("%d is an even number.\n", n);
    }
}
