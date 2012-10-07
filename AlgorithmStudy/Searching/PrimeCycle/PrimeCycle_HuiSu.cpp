#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[25], total;
bool vis[25], prime[50];

void getPrime()
{
	prime[1] = false;
	for(int i=2; i<50; i++)
	{
		if(prime[i])
			for(int j=i*i; j<50; j+=i)
				prime[j] = false;
	}
}

bool is_ok(int s, int n)
{
	if(s != n)
		return prime[a[s] + a[s-1]];
	else
		return prime[a[s] + a[s-1]] && prime[a[s] + a[1]];
}

void dfs(int s, int n)
{
	if(s > n)
	{
		for(int i=1; i<=n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
		total++;
	}
	else
	{
		for(int i=2; i<=n; i++)
		{
			if(!vis[i])
			{
				vis[i] = true;
				a[s] = i;
				if(is_ok(s, n))
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
	memset(prime, true, sizeof(prime));
	getPrime();
	a[1] = 1;
	vis[1] = true;
	dfs(2, 10);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}