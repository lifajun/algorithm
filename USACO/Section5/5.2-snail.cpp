/*
ID: lifajun2
PROG: snail
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

bool hasBar[205][205], vis[205][205];
int N, len = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 &&  y < N && !hasBar[x][y];
}

void dfs(int x, int y, int d, int s)
{
	int xx = x + dx[d], yy = y + dy[d];
	if(s > len) len  = s;
	if(vis[xx][yy]) return;
	else if(isvalid(xx, yy))
	{
		vis[xx][yy] = true;
		dfs(xx, yy, d, s+1);
		vis[xx][yy] = false;
	}
	else
	{
		int d1 = (d+1)%4;
		int x1 = x + dx[d1], y1 = y + dy[d1];
		if(isvalid(x1, y1) && !vis[x1][y1])
		{
			vis[x1][y1] = true;
			dfs(x1, y1, d1, s+1);
			vis[x1][y1] = false;
		}
		d1 = (d-1+4)%4;
		x1 = x + dx[d1], y1 = y + dy[d1];
		if(isvalid(x1, y1) && !vis[x1][y1])
		{
			vis[x1][y1] = true;
			dfs(x1, y1, d1, s+1);
			vis[x1][y1] = false;
		}
	}
}
int main()
{
	int M;
	char str[10];
	FILE* in = fopen("snail.in", "r");
	FILE* out = fopen("snail.out", "w");

	memset(hasBar, false, sizeof(hasBar));
	fscanf(in, "%d %d", &N, &M);
	for(int i=1; i<=M; i++)
	{
		fscanf(in, "%s", str);
		hasBar[atoi(str+1)-1][str[0]-'A'] = true;
	}

	memset(vis, false, sizeof(vis));
	vis[0][0] = true;
	dfs(0, 0, 1, 1);
	memset(vis, false, sizeof(vis));
	vis[0][0] = true;
	dfs(0, 0, 2, 1);

	fprintf(out, "%d\n", len); 
	return 0;
}