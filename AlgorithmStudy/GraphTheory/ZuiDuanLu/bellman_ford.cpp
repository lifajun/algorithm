#include <iostream>
using namespace std;

#define INF 10000000

struct Edge
{
	int u, v, w;
}E[100000];

int dist[100], n, e;

bool bellman_ford(int s)
{
	for(int i=1; i<=n; i++)	dist[i] = INF;
	dist[s] = 0;

	for(int i=1; i<n; i++)
		for(int j=1; j<e; j++)//每次循环都把每条边用于松弛
			if(dist[E[j].u] > dist[E[j].v] + E[j].w)
				dist[E[j].u] = dist[E[j].v] + E[j].w

	for(int j=1; j<e; j++)
			if(dist[E[j].u] > dist[E[j].v] + E[j].w)
				return false;
	return true;
}

int main()
{
	//...........
	bellman_ford(1);
	return 0;
}