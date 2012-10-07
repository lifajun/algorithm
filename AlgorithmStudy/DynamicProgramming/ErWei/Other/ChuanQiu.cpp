#include <cstdio>
#include <cstring>

int dp[35][35], n, m;

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));//dp[i][j]传了i次球之后，球在第j个小朋友那里
		dp[0][1] = 1;
		for(int i=1; i<=m; i++)
		{
			dp[i][1] = dp[i-1][n] + dp[i-1][2];
			dp[i][n] = dp[i-1][n-1] + dp[i-1][1];
			for(int j=2; j<n; j++)
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
		}
		printf("%d\n", dp[m][1]);
	}
	return 0;
}