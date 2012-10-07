/*
ID: lifajun2
PROG: comehome
LANG: C++
*/
#include <cstdio>
#include <cstring>
#define min(a, b) (a < b ? a : b)
#define INF 100000000
int cost[100][100];
int dist[100];
bool vis[100];

int getvalue(char c)
{
	if(c >= 'a' && c <= 'z')
		return (c-'a')*2 + 1;
	else
		return (c-'A')*2;
}

int dijkstra(int& idx)
{
	memset(vis, false, sizeof(vis));
	for(int i=0; i<=51; i++)	dist[i] = INF;
	dist[50] = 0;
	for(int i=1; i<=52; i++)
	{
		int min = INF, p;
		for(int j=0; j<52; j++)
		{
			if(dist[j] < min && !vis[j])
				min = dist[p = j];
		}
		if(p != 50 && p % 2 == 0)	{idx = p;return min;}
		vis[p] = true;
		for(int j=0; j<52; j++)
			if(!vis[j] && dist[j] > dist[p] + cost[p][j])
				dist[j] = dist[p] + cost[p][j];
	}
	return 0;
}

int main()
{
	int P, v;
	char x, y;
	FILE* in = fopen("comehome.in", "r");
	FILE* out = fopen("comehome.out", "w");
	
	for(int i=0; i<52; i++)
		for(int j=0; j<52; j++)
			cost[i][j] = INF;
	fscanf(in, "%d", &P);
	fgetc(in);
	for(int i=1; i<=P; i++)
	{
		fscanf(in, "%c %c %d", &x, &y, &v);
		fgetc(in);
		cost[getvalue(x)][getvalue(y)] = min(v, cost[getvalue(x)][getvalue(y)]);
		cost[getvalue(y)][getvalue(x)] = min(v, cost[getvalue(y)][getvalue(x)]);
	}

	int cle, idx = 0;
	cle = dijkstra(idx);
	fprintf(out, "%c %d\n", (char)(idx/2 + 'A'), cle);
	return 0;
}