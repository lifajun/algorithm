#include <iostream>
using namespace std;

int main()
{
	int dp[100], h[100], N, ans1, ans2;
	
	N = 0;
	while(cin>>h[N++]);
	N--;

	for(int i=0; i<N; i++)	dp[i] = 1;
	ans1 = dp[0];
	
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<i; j++)
		{
			if((h[j] >= h[i]) && (dp[i] < dp[j]+1))
				dp[i] = dp[j]+1;
			if(dp[i] > ans1)
				ans1 = dp[i];
		}
	}

	for(int i=0; i<N; i++)	dp[i] = 1;
	ans2 = 1;
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<i; j++)
		{
			if((h[j] < h[i]) && (dp[j]+1 > dp[i]))
				dp[i] = dp[j]+1;
			if(dp[i] > ans2)
				ans2 = dp[i];
		}
	}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}