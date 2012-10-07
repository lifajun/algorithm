/*
ID: lifajun2
PROG: agrinet
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 10000000

int map[105][105], dist[105], N;
bool vis[105];

int prim()
{
	int ans = 0;
	memset(vis, false, sizeof(vis));
	for(int i=1; i<=N; i++)	dist[i] = map[1][i];
	vis[1] = true;
	for(int i=1; i<N; i++)
	{
		int min = INF, p;
		for(int j=1; j<=N; j++)
			if(!vis[j] && dist[j] < min)
				min = dist[p = j];
		ans += min;
		vis[p] = true;
		for(int j=1; j<=N; j++)
			if(!vis[j] && dist[j] > map[p][j])
				dist[j] = map[p][j];
	}
	return ans;
}

int main()
{
	FILE* in = fopen("agrinet.in", "r");
	FILE* out = fopen("agrinet.out", "w");
	
	fscanf(in, "%d", &N);
	fgetc(in);
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			fscanf(in, "%d", &map[i][j]);
			if(i == 80)	fgetc(in);
		}
		map[i][i] = INF;
		fgetc(in);
	}

	fprintf(out, "%d\n", prim());
	return 0;
}