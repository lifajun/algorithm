/*
ID: lifajun2
PROG: sort3
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int a[1005], sorted[1005];
queue<int> pa[1005];
//数字置换环：一个未排序的数组需要的交换最少的次数以达到排序，
//即把每个数都先放到它正确的位置上去，从而形成了一个环。

//通过一个队列数组来寻找数字置换环，
//pa[i]表示未排序数组中i占据了已排序数组中哪些数的位置，
//然后遍历队列数组，遍历的同时删除一个个的数字环（数字出队），每一个环
//需要交换的最小次数为环的长度减一，遍历直到所有的队列为空，停止。
int main()
{
	int N, ans = 0;
	FILE* in = fopen("sort3.in", "r");
	FILE *out = fopen("sort3.out", "w");

	fscanf(in, "%d", &N);
	for(int i=0; i<N; i++)
		fscanf(in, "%d", &a[i]);
	memcpy(sorted, a, sizeof(a));
	
	sort(sorted, sorted+N);
	for(int i=0; i<N; i++)
		if(a[i] != sorted[i])
			pa[a[i]].push(sorted[i]);

	for(int i=1; i<=3; i++)
	{
		while(!pa[i].empty())
		{
			int  t = pa[i].front(), len = 1;
			pa[i].pop();
			while(t != i)
			{
				int temp = t;
				t = pa[temp].front();pa[temp].pop();
				len++;
			}
			ans += len-1;
		}
	}
	fprintf(out, "%d\n", ans);
	return 0;
}