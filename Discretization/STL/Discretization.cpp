///输入10000个(l, r)区间，
///l和r为(1, 1e7)之间的数
///map去重/离散化后按原顺序输出
///Discretize
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int INF = 0x7fffffff;

int n;///n intervals
int p;
struct node
{
    int left;
    int right;
}interval[maxn];
map<int, int> Disc;

int main()
{
    while(~scanf("%d", &n))
    {
        p = 0;
        Disc.clear();
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &interval[i].left, &interval[i].right);
            Disc[interval[i].left] = INF;
            Disc[interval[i].right] = INF;
        }
        for(auto i = Disc.begin(); i != Disc.end(); ++i)///auto in C++11
            i->second = ++p;
        for(int i = 0; i < n; ++i)
            printf("%d: %d %d\n", i+1, Disc[interval[i].left], Disc[interval[i].right]);
    }
    return 0;
}
/**

Sample Input:
5
1 1000000
3 4
5 99
81 98
79 1000

Sample Output:
1: 1 10
2: 2 3
3: 4 8
4: 6 7
5: 5 9

*/
