#include <iostream>
#include <cstring>
using namespace std;

bool map[205][205], vis[205];
int link[205], N, M;

int find(int t)
{
	for(int i=1; i<=M; i++)
	{
		if(!vis[i] && map[t][i])
		{
			vis[i] = true;
			if(link[i] == 0 || find(link[i]))
			{
				link[i] = t;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int si, t;
	while(scanf("%d%d", &N, &M) == 2)
	{
		memset(map, false, sizeof(map));
		memset(link, 0, sizeof(link));
		for(int i=1; i<=N; i++)
		{
			scanf("%d", &si);
			for(int j=1; j<=si; j++)
			{
				scanf("%d", &t);
				map[i][t] = true;
			}
		}

		int ans = 0;
		for(int i=1; i<=N; i++)
		{
			memset(vis, false, sizeof(vis));
			if(find(i))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}