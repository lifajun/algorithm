#include <iostream>
#include <string.h>
using namespace std;

int dp[1002][1002];
int map[1001][1001];

int min(int a, int b, int c)
{
	if(a < b)
	{
		if(c < a)
			return c;
		else
			return a;
	}
	else if(c<b)
		return c;
	else
		return b;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map[i][j];
	memset(dp, 0, sizeof(dp));
	for(int i=n; i>=1; i--)
	{
		for(int j=m; j>=1; j--)
		{
			if(map[i][j])
				dp[i][j] = min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]) + 1;
			else
				dp[i][j] = 0;
		}
	}
	int ans = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(dp[i][j] > ans)
				ans = dp[i][j];
	cout<<ans<<endl;
	return 0;
}