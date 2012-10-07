#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge
{
	int u, v, w;
}e[10000];

int used[101], father[101], n, m;

int find(int x){return father[x] == x ? x: father[x] = find(father[x]);}

int cmp(Edge e1, Edge e2)
{
	return e1.w < e2.w;
}

int kruskal(int pos)
{
	int top = 0, min = 0, cnt = 0;
	for(int i=1; i<=n; i++)	father[i] = i;
	for(int i=0; i<m; i++)
	{
		if(i == pos)	continue;
		int f1 = find(e[i].u), f2 = find(e[i].v);
		if(f1 != f2)
		{
			if(pos == -1)	used[top++] = i;
			cnt++;
			father[f1] = f2;
			min += e[i].w;
		}
	}
	if(cnt != n-1)
		return -1;
	return min;
}

int main()
{
	int T, u, v, w;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			e[i].u = u, e[i].v = v, e[i].w = w;
		}
		sort(e, e+m, cmp);
		int min = kruskal(-1), flag = 0;
		/*求次小生成树，先求最小生成树，并记录下每条边，然后每次去掉一条边，再求最小生成树，
		当每条边都操作之后，求得的最小值就是次小生成树的值。O(N3)*/
		for(int i=0; i<n-1;i++)
		{
			int t = kruskal(used[i]);
			if(t == min)	{printf("Not Unique!\n");flag = 1;break;}
		}
		if(!flag)
			printf("%d\n", min);
	}
	return 0;
}