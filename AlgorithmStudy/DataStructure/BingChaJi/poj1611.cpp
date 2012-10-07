#include <iostream>
using namespace std;

int father[30005],  rank[30005], n, m;
//rank数组表示每个点的等级，把等级低的挂接到等级高的上面

int find(int x){return father[x] == x ? x : father[x] = find(father[x]);}
void union_set(int x, int y)
{
	int f1 = find(x), f2 = find(y);
	if(f1 != f2)
	{
		if(rank[f1] > rank[f2])
			father[f2] = f1;
		else
		{
			father[f1] = f2;
			if(rank[f1] == rank[f2])
				rank[f2]++;
		}
	}
}

int main()
{
	int k, v, pre;
	while(scanf("%d%d", &n, &m), n+m)
	{
		for(int i=0; i<n; i++)	father[i] = i, rank[i] = 0;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d", &k, &pre);
			for(int i=1; i<k; i++)
			{
				scanf("%d", &v);
				union_set(pre, v);
			}
		}
		int ans = 1;
		int f = find(0);
		for(int i=1; i<n; i++)
			if(find(i) == f)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}