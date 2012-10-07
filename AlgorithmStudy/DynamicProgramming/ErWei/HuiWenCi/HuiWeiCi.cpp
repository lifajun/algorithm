#include <iostream>
#include <string.h>
using namespace std;

short dp[5002][5002];
char s[5002];

int min(int a, int b){return a<b ? a :  b;}

int main()
{
	int N;
	cin>>N>>s+1;
	memset(dp, 0, sizeof(dp));
	for(int i=N; i>=1; i--)
	{
		for(int j=i; j<=N; j++)
		{
			if(s[i] == s[j])
				dp[i][j] = dp[i+1][j-1];
			else
				dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1);
		}
	}
	cout<<dp[1][N]<<endl;
	return 0;
}