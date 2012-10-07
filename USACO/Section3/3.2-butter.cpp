/*
ID: lifajun2
PROG: butter
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define INF 100000000
int min_dist[805][805], cow[505], N, P, M;
bool vis[805];

struct Edge
{
	int end, w;
	Edge(int e, int ww)
	{
		end = e, w = ww;
	}
};
vector<Edge> ed[805];

void spfa(int pas)
{
	queue<int> q;
	memset(vis, false, sizeof(vis));
	for(int i=1; i<=P; i++)	min_dist[pas][i] = INF;
	for(int i=1; i<pas; i++)	min_dist[pas][i] = min_dist[i][pas],q.push(i), vis[i] = true;
	vis[pas] = true, min_dist[pas][pas] = 0;
	q.push(pas);

	while(!q.empty())
	{
		int t = q.front(); q.pop(); vis[t] = false;
		for(int j=0; j<ed[t].size(); j++)
		{
			if(min_dist[pas][ed[t][j].end] > min_dist[pas][t] + ed[t][j].w)
			{
				min_dist[pas][ed[t][j].end] = min_dist[pas][t] + ed[t][j].w;
				if(!vis[ed[t][j].end])
					vis[ed[t][j].end] = true, q.push(ed[t][j].end);
			}
		}
	}
}

int main()
{
	int a, b, c;
	FILE* in = fopen("butter.in", "r");
	FILE* out = fopen("butter.out", "w");

	fscanf(in, "%d %d %d", &N, &P, &M);fgetc(in);
	for(int i=0; i<N; i++)	fscanf(in, "%d", &cow[i]);
	fgetc(in);

	for(int i=1; i<=M; i++)
	{
		fscanf(in, "%d %d %d", &a, &b, &c);
		ed[a].push_back(Edge(b, c));
		ed[b].push_back(Edge(a, c));
	}

	for(int i=1; i<=P; i++)
		spfa(i);

	int min = INF;
	for(int i=1; i<=P; i++)
	{
		int sum = 0;
		for(int j=0; j<N; j++)
			sum += min_dist[i][cow[j]];
		if(sum < min)	min = sum;
	}

	fprintf(out, "%d\n", min);
	return 0;
}