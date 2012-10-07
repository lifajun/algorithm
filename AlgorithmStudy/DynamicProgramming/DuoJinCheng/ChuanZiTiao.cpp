#include <iostream>
#include <string.h>
using namespace std;

#define max(a, b) (a>b ? a : b)

int dp[110][55][55];
int map[55][55];

int main()
{
	int M, N;
	cin>>M>>N;
	for(int i=1; i<=M; i++)
		for(int j=1; j<=N;j++)
			cin>>map[i][j];
	memset(dp, 0, sizeof(dp));
	dp[1][1][1] = 0;
	for(int k=2; k <= M+N-1; k++)
	{
		for(int i=1; i<=M; i++)
			if(k+1-i>0 && k+1-i<=N)
				for(int j=i; j<=M; j++)
					if(k+1-j>0 && k+1-j<=N)
					{
						if(i == j)
							dp[k][i][j] = dp[k-1][i-1][j] + map[i][k+1-i];
						else
						{
							dp[k][i][j] = max(dp[k-1][i-1][j-1], dp[k-1][i-1][j]);
							dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j-1]);
							dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j]);
							dp[k][i][j] += (map[i][k+1-i] + map[j][k+1-j]);
						}
					}
	}
	cout<<dp[M+N-1][M][M]<<endl;
	return 0;
}							