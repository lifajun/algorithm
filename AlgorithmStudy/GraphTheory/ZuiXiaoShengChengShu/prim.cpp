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
	for(int i=1; i<n; i++)//����n-1���ߣ�ÿһ���ߵ���㶼��visited�������棬�յ���ʣ�µĵ�����
	{
		int min = INF, p;
		for(int j=1; j<=n; j++)
			if(!visited[j] && lowc[j] < min)
				min = lowc[j], p = j;//�ҳ���Ҫ���뵽visited�ĵ�ıߣ�̰��
		if(min == INF)	return -1;//�Ҳ�����ͼ����ͨ
		ans += min;
		visited[p] = true;
		for(int j=1; j<=n; j++)//��ѭ������visited�еĵ㵽δ���ʵ����̾��룬��Ϊ�ô�ֻ������p������ֻ���p
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