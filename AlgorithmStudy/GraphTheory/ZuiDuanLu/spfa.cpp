#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INF 10000000

int cost[100][100], n, dist[100];
bool vis[100];

void spfa(int s)
{
	memset(vis, false, sizeof(vis));
	queue<int> q;
	for(int i=1; i<=n; i++)	dist[i] = INF;
	vis[s] = true, dist[s] = 0;
	q.push(s);

	while(!q.empty())//用队列里的所有点去刷新起始点到所有点的最短路
	{
		int t = q.front(); q.pop(); vis[t] = false;
		for(int i=1; i<=n; i++)
		{
			if(dist[i] > dist[t] + cost[t][i])//如果刷新成功，且被刷新点不在队列中则把该点加入到队列最后
			{
				dist[i] = dist[t] + cost[t][i];
				if(!vis[i])
					vis[i] = true, q.push(i);
			}
		}
	}
}

int main()
{
	int s;
	cin>>s;
	//....
	spfa(s);
	return 0;
}
