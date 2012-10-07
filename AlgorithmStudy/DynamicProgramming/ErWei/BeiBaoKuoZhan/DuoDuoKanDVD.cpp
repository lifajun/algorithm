#include <iostream>
#include <string.h>
using namespace std;

int dp[101][1001];
int Ti[101], Mi[101];

int main()
{
	int N, M, L;
	cin>>N>>M>>L;
	for(int i=1; i<=N; i++)
		cin>>Ti[i]>>Mi[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for(int i=1; i<=N; i++)
		for(int j=M; j>=1; j--)
			for(int k=L; k>=Ti[i]; k--)
				if(dp[j-1][k-Ti[i]] && (dp[j-1][k-Ti[i]] + Mi[i] > dp[j][k] ))
					dp[j][k] = dp[j-1][k-Ti[i]] + Mi[i];

	int ans = dp[M][1];
	for(int i=1; i<=L; i++)
		if(dp[M][i] > ans)
			ans = dp[M][i];

	cout<<((ans == 0) ? 0 : ans-1)<<endl;
	return 0;
}