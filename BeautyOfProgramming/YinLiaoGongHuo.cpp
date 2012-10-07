#include <iostream>
#include <cstring>
using namespace std;

int dp[10000];

int main()
{
	int vi, ci, hi, n, v;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	cin>>n>>v;
	for(int i=1; i<=n; i++)
	{
		cin>>vi>>ci>>hi;
		for(int k=1; k<=ci; k++)
		{
			for(int j=v; j>=vi; j--)
				if(dp[j-vi] && dp[j-vi] + hi > dp[j])
					dp[j] = dp[j-vi] + hi;
		}
	}
	cout<<dp[v]<<endl;
	return 0;
}