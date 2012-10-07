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

	for(int i=1; i<n; i++)//ÿ��ѭ��ȷ��һ��������·��
	{
		int min = INF, p;
		for(int j=1; j<=n; j++)//��δvis�ĵ����ҵ�һ����С��ֵ�����ֵ��ʾ�ĵ�����·����ȷ��
			if(!vis[j] && dist[j] < min)
				p = j, min = dist[j];
		vis[p] = true;//���Ϊ���ҵ�
		for(int j=1; j<=n; j++)
			if(!vis[j] && dist[j] > min + cost[p][j])//�����p֮�󣬶Ի�δ���ʵĵ���¡����ɳ�
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