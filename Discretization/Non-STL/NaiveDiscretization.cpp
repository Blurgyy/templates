///Actually not very naive... I think this method has a good complexity
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 20010;
const int INF = 0x7fffffff;

int n;
int Disc[maxn], p;
struct node
{
	int left, right;
}interval[maxn];

int bs(int left, int right, int e)	///Binary search to find the index
{
	if(left >= right)return right;
	int mid = (left + right)>>1;
	if(Disc[mid] > e)return bs(left, mid, e);
	return bs(mid+1, right, e);
}

void init()
{
	p = 0;
	memset(Disc, 0, sizeof(Disc));
}

int main()
{
	while(~scanf("%d", &n))
	{
		init();
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &interval[i].left, &interval[i].right);
			Disc[p++] = interval[i].left;
			Disc[p++] = interval[i].right;
		}
		sort(Disc, Disc + p);
		int top = 1;
		for(int i = 1; i < p; i++)
			if(Disc[i] != Disc[i-1])Disc[top++] = Disc[i];
		p = top;
		///For poj2528
/*
		for(int i = 1; i < p; i++)
			if(Disc[i] - Disc[i-1] > 1)Disc[top++] = Disc[i-1] + 1;
		sort(Disc, Disc + top);///REMEMBER to sort here
*/
		/*
		printf("Disc:\n");
		for(int i = 0; i < top; i++)
			printf("Disc[%d] = %d\n", i, Disc[i]);
		*/
		printf("\n");
		printf("bs:\n");
		for(int i = 0; i < n; i++)
			printf("%d %d\n", bs(0, top, interval[i].left), bs(0, top, interval[i].right));
	}
	return 0;
}
