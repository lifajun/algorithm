#include <iostream>
using namespace std;

int main()
{
	int dp[100],a[100], N, ans;
	cin>>N;
	for(int i=0; i<N; i++)	dp[i] = 1;
	for(int i=0; i<N; i++)
		cin>>a[i];

	ans = dp[0];
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<=i-1; j++)
		{
			if((a[i]<a[j]) && (dp[i]<dp[j]+1))
				dp[i] = dp[j]+1;
			if(dp[i] > ans)
				ans = dp[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}