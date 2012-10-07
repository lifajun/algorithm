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

	while(!q.empty())//�ö���������е�ȥˢ����ʼ�㵽���е�����·
	{
		int t = q.front(); q.pop(); vis[t] = false;
		for(int i=1; i<=n; i++)
		{
			if(dist[i] > dist[t] + cost[t][i])//���ˢ�³ɹ����ұ�ˢ�µ㲻�ڶ�������Ѹõ���뵽�������
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
