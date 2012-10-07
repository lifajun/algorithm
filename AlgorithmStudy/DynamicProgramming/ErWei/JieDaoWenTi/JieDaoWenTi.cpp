#include <iostream>
#include <string.h>
using namespace std;

#define min(a, b) (a<b ? a : b)

int N,M;
int z[100][100], h[100][100];
int dp[100][100];

int main()
{
	cin>>M>>N;
	memset(dp, 0, sizeof(dp));
	memset(z, 0, sizeof(z));
	memset(h, 0, sizeof(h));

	for(int i=1; i<=M; i++)
		for(int j=1; j<N; j++)
			cin>>z[i][j];
	for(int i=1; i<M; i++)
		for(int j=1; j<=N; j++)
			cin>>h[i][j];

	for(int j=N-1; j>=1; j--)
		dp[1][j] = dp[1][j+1] + z[1][j];
	for(int i=1; i<=M; i++)
		dp[i][N] = dp[i-1][N] + h[i-1][N];

	for(int i=2; i<=M; i++)
		for(int j=N-1; j>=1; j--)
			dp[i][j] = min(dp[i-1][j] + h[i-1][j], dp[i][j+1] + z[i][j]);

	cout<<dp[M][1]<<endl;
	return 0;
}