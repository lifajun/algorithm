#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int a[25], n, k, cnt;
int vis[25];

bool isPrime()
{
	int s = 0;
	for(int i=1; i<=n; i++)
		if(vis[i])		s += a[i];
	for(int i=2; i<=sqrt((double)s); i++)
	{
		if(s % i == 0)
			return false;
	}
	return true;
}

int hasVis()
{
	int cnt = 0;
	for(int i=1; i<=n; i++)
		cnt += vis[i];
	return cnt;
}

void dfs(int s)
{
	if(s > n+1)
		return;
	if(hasVis() == k)
	{
		for(int i=1; i<=n; i++)
			if(vis[i])		cout<<a[i]<<" ";
		cout<<endl;
		if(isPrime())
			cnt++;
		return;
	}
	else
	{
		vis[s] = 1;
		dfs(s+1);
		vis[s] = 0;
		dfs(s+1);
	}
}

int main()
{
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	memset(vis, 0, sizeof(vis));
	cnt = 0;
	dfs(1);
	cout<<cnt<<endl;
	return 0;
}