#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[20], total;
bool vis[20];

void dfs(int s, int n)
{
	if(s > n)
		total++;
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
			{
				vis[i] = true;
				a[s] = i;
				dfs(s+1, n);
				vis[i] = false;
			}
		}
	}
}

int main()
{
	int time = GetTickCount();
	total = 0;
	memset(vis, false, sizeof(vis));
	dfs(1, 11);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}