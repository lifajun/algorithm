#include <iostream>
#include <cstring>
using namespace std;

#define INF 0xffffffff

int n, cost[100][100];

int prim()
{
	bool visited[100];
	int lowc[100], ans = 0;
	memset(visited, false, sizeof(visited));
	visited[1] = true;
	for(int i=1; i<=n; i++)	lowc[i] = cost[1][i];
	for(int i=1; i<n; i++)//加入n-1条边，每一条边的起点都在visited集合里面，终点在剩下的点里面
	{
		int min = INF, p;
		for(int j=1; j<=n; j++)
			if(!visited[j] && lowc[j] < min)
				min = lowc[j], p = j;//找出需要加入到visited的点的边，贪心
		if(min == INF)	return -1;//找不到，图不连通
		ans += min;
		visited[p] = true;
		for(int j=1; j<=n; j++)//该循环更新visited中的点到未访问点的最短距离，因为该次只更新了p，所以只检查p
			if(!visited[j] && lowc[j] > cost[p][j])
				lowc[j] = cost[p][j];
	}
	return ans;
}

int main()
{
	int p, x, y, w;
	cin>>n>>p;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cost[i][j] = INF;
	for(int i=1; i<=p; i++)
	{
		cin>>x>>y>>w;
		cost[x][y] = w;
	}
	cout<<prim()<<endl;
	return 0;
}