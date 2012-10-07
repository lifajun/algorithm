#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int map[20][20], n, m, total;
bool vis[20][20];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool isvalid(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y, int s)
{
	if(s > n*m)
		total++;
	else
	{
		for(int i=0; i<8; i++)
		{
			int xx = x+dx[i], yy = y+dy[i];
			if(isvalid(xx, yy) && !vis[xx][yy])
			{
				vis[xx][yy] = true;
				map[xx][yy] = s;
				dfs(xx, yy, s+1);
				vis[xx][yy] = false;
			}
		}
	}
}

int main()
{
	total = 0;
	memset(vis, false, sizeof(vis));
	cin>>n>>m;
	int time = GetTickCount();
	vis[1][1] = true;
	map[1][1] = 1;
	dfs(1, 1, 2);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}