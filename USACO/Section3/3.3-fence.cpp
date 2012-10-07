/*
ID: lifajun2
PROG: fence
LANG: C++
*/
#include <fstream>
using namespace std;

int degree[505], dist[505][505], F;
int path[1030], len = 0, maxn;

void dfs(int u)
{
	for(int v = 1; v<=maxn; v++)
	{
		if(dist[u][v])
		{
			dist[u][v]--, dist[v][u]--;
			dfs(v);
		}
	}
	path[len++] = u;
}

int main()
{
	int u, v;
	ifstream in("fence.in");
	ofstream out("fence.out");

	in>>F;
	for(int i=1; i<=F; i++)
	{
		in>>u>>v;
		degree[u]++, degree[v]++;
		dist[u][v]++, dist[v][u]++;
		if(u > maxn)	maxn = u;
		if(v > maxn)	maxn = v;
	}
	int s = 0;
	for(int i=1; i<=maxn; i++)
	{
		if(degree[i])
		{
			if(s == 0) s = i;
			if(degree[i] % 2 == 1)	{s = i; break;}
		}
	}
	dfs(s);
	for(int i=len-1; i>=0; i--)
		out<<path[i]<<endl;
	return 0;
}