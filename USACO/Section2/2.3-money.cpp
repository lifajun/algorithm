/*
ID: lifajun2
PROG: money
LANG: C++
*/
#include <cstdio>
#include <cstring>

long long dp[10005];
int V, N, w[30];

int main()
{
	FILE* in = fopen("money.in", "r");
	FILE* out = fopen("money.out", "w");

	fscanf(in, "%d%d", &V, &N);
	for(int i=1; i<=V; i++)
		fscanf(in, "%d", &w[i]);

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=1; i<=V; i++)
		for(int j=w[i]; j<=N; j++)
			dp[j] += dp[j-w[i]];
	fprintf(out, "%lld\n", dp[N]);
	return 0;
}