/*
ID: lifajun2
PROG: nocows
LANG: C++
*/
#include <cstdio>
#include <cstring>

#define MOD 9901
int dp[205][105];

int main()
{
	int N, K;
	FILE* in = fopen("nocows.in", "r");
	FILE* out = fopen("nocows.out", "w");

	fscanf(in, "%d%d", &N, &K);
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=K; i++)	dp[1][i] = 1;

	for(int i=2; i<=N; i++)
	for(int j=1; j<=K; j++)
	for(int k=1; k<i; k+=2)
		dp[i][j] = (dp[i][j] + dp[k][j-1] * dp[i-k-1][j-1])%MOD;

	fprintf(out, "%d\n", (dp[N][K] - dp[N][K-1]+MOD)%MOD);
	return 0;
}