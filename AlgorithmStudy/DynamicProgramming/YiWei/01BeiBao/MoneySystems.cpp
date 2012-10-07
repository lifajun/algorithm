#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int dp[1000], V, N, v;
	cin>>V>>N;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i=0; i<V; i++)
	{
		cin>>v;
		for(int j=v; j<=N; j++)
			dp[j] += dp[j-v];
	}
	cout<<dp[N]<<endl;
	return 0;
}