#include <iostream>
#include <cstring>
using namespace std;

#define INF 100000000

int cost[1005][1005], dist[1005], n;
bool vis[1005];

int dijkstra(int s, int e)
{
	for(int i=1; i<=n; i++)	dist[i] = cost[s][i];
	dist[s] = 0;
	memset(vis, false, sizeof(vis));
	vis[s] = true;

	for(int i=1; i<n; i++)//每次循环确定一个点的最短路径
	{
		int min = INF, p;
		for(int j=1; j<=n; j++)//从未vis的点中找到一个最小的值，这个值表示改点的最短路径已确定
			if(!vis[j] && dist[j] < min)
				p = j, min = dist[j];
		vis[p] = true;//标记为已找到
		for(int j=1; j<=n; j++)
			if(!vis[j] && dist[j] > min + cost[p][j])//加入点p之后，对还未访问的点更新——松弛
				dist[j] = dist[p] + cost[p][j];
	}
	return dist[e];
}

int main()
{
	int T, x, y, w;
	cin>>T>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cost[i][j] = INF;
	for(int i=1; i<=T; i++)
	{
		cin>>x>>y>>w;
		if(cost[x][y] > w)	cost[x][y] = cost[y][x] = w;
	}
	cout<<dijkstra(1, n)<<endl;
	return 0;
}