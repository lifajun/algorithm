#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 205
#define INF 10000005
#define min(a, b) (a < b ? a : b)

int capacity[MAX][MAX], flow[MAX][MAX];
int p[MAX], a[MAX], N, M;

int max_flow(int s, int t)
{
	memset(flow, 0, sizeof(flow));
	int f = 0;
	while(1)
	{
		queue<int> q;
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		a[s] = INF;
		q.push(s);

		while(!q.empty())//bfs’“‘ˆπ„¬∑
		{
			int u = q.front(); q.pop();
			for(int v=1; v<=M; v++)
			{
				if(!a[v] && flow[u][v] < capacity[u][v])
				{
					p[v] = u;q.push(v);
					a[v] = min(a[u], capacity[u][v] - flow[u][v]);
				}
			}
		}
		if(a[t] == 0)	break;
		for(int u = t; u != s; u = p[u])
		{
			flow[p[u]][u] += a[t];
			flow[u][p[u]] -= a[t];
		}
		f += a[t];
	}
	return f;
}

int main()
{
	int si, ei, ci;
	while(scanf("%d%d", &N, &M) == 2)
	{
		memset(capacity, 0, sizeof(capacity));
		for(int i=1; i<=N; i++)
		{
			scanf("%d%d%d", &si, &ei, &ci);
			capacity[si][ei] += ci;
		}
		printf("%d\n", max_flow(1, M));
	}
	return 0;
}