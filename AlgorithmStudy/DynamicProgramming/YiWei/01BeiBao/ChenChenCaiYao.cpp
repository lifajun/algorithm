#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int dp[1001], ans = 0, T, M, t, v;
	memset(dp, 0, sizeof(dp));
	cin>>T>>M;

	dp[0] = 1;
	for(int i=0; i<M; i++)
	{
		cin>>t>>v;
		for(int j=T; j>=t; j--)
		{
			if(dp[j-t] && (dp[j-t]+v > dp[j]))
				dp[j] = dp[j-t]+v;
		}
	}
	for(int i=1; i<=T; i++)
		if(dp[i] > ans)
			ans = dp[i];
	cout<<ans-1<<endl;
	return 0;
}