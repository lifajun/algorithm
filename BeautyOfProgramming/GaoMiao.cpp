#include <iostream>
using namespace std;

int c[100], g[100][100], n, m;

bool check(int s)
{
	for(int i=1; i<s; i++)
		if(g[i][s] && c[i] == c[s])
			return false;
	return true;
}

bool dfs(int s)
{
	if(s > n)
		return true;
	for(int i=1; i<=m; i++)
	{
		c[s] = i;
		if(check(s) && dfs(s+1))
			return true;
	}
	return false;
}

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>g[i][j];
	m = 1;
	while(1)
	{
		if(dfs(m))
		{
			cout<<m<<endl;
			break;
		}
		m++;
	}
	return 0;
}