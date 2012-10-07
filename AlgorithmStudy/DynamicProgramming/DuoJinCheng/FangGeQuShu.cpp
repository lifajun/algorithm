#include <iostream>
#include <string.h>
using namespace std;

#define max(a, b) (a>b ? a : b)

int dp[30][15][15];
int map[15][15];

int main()
{
	int N, x, y, v;
	cin>>N;
	while(1)
	{
		cin>>x>>y>>v;
		if(x+y+v == 0)
			break;
		map[x][y] = v;
	}
	memset(dp, 0, sizeof(dp));
	dp[1][1][1] = map[1][1];
	for(int k=2; k <= 2*N-1; k++)
	{
		for(int i=1; i<=N; i++)
			if(k+1-i>0 && k+1-i<=N)
				for(int j=i; j<=N; j++)
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
	cout<<dp[2*N-1][N][N]<<endl;
	return 0;
}