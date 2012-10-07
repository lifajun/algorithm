#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int dp[10000], N, m, v, p, ans = 0;
	memset(dp, 0, sizeof(dp));
	cin>>N>>m;

	dp[0] = 1;
	for(int i=0; i<m; i++)
	{
		cin>>v>>p;
		for(int j=N; j>=v; j--)
		{
			if(dp[j-v] && (dp[j-v]+v*p > dp[j]))
				dp[j] = dp[j-v]+v*p;
		}
	}

	for(int i=1; i<=N; i++)
		if(dp[i] > ans)
			ans = dp[i];

	cout<<ans-1<<endl;
	return 0;
}