#include <iostream>
using namespace std;

#define INF 0xfffff

int dist[100][100], n;

void floyd()
{
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}

int main()
{
	//.........
	floyd();
	//........
	return 0;
}