/*
ID: lifajun2
PROG: inflate
LANG: C++
*/
#include <cstdio>
#include <cstring>

int dp[10005], points[10005],  minutes[10005], M, N;
int main()
{
	FILE* in = fopen("inflate.in", "r");
	FILE* out = fopen("inflate.out", "w");

	fscanf(in, "%d %d", &M, &N);
	fgetc(in);
	for(int i=1; i<=N; i++)
	{
		fscanf(in, "%d %d", &points[i], &minutes[i]);
		fgetc(in);
	}

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=1; i<=N; i++)
		for(int j=minutes[i]; j<=M; j++)
			if(dp[j-minutes[i]] && dp[j] < dp[j-minutes[i]] + points[i])
				dp[j] = dp[j-minutes[i]] + points[i];
	int max = 0;
	for(int i=1; i<= M; i++)
		if(dp[i] > max)
			max = dp[i];
	fprintf(out, "%d\n", max-1);
	return 0;
}