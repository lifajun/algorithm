#include <iostream>
#include <string.h>
using namespace std;

int dp[3002][3002];
int arr[3002];

int min(int a, int b, int c)
{
	if(a < b)
	{
		if(c < a)
			return c;
		else
			return a;
	}
	else if(c < b)
		return c;
	else
		return b;
}

int main()
{
	int N;
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>arr[i];

	memset(dp, 0, sizeof(dp));
	for(int i=N; i>=1; i--)
	{
		for(int j=i; j<=N; j++)
		{
			if(arr[i] == arr[j])
				dp[i][j] = dp[i+1][j-1];
			else
				dp[i][j] = min(dp[i+1][j]+1, dp[i][j-1]+1, dp[i+1][j-1]+1);
		}
	}
	cout<<dp[1][N]<<endl;
	return 0;
}