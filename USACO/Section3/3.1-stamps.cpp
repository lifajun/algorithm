/*
ID: lifajun2
PROG: stamps
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 10000
#define min(a, b)(a < b ? a : b)
int dp[200*MAX+10], K, N, value[55];

int main()
{
	FILE* in = fopen("stamps.in", "r");
	FILE* out = fopen("stamps.out", "w");
	
	int max = 0;
	fscanf(in, "%d %d", &K, &N);
	for(int i=1; i<=N; i++)
	{
		fscanf(in, "%d", &value[i]);
		if(value[i] > max)	max = value[i];
		if(i%15 == 0)fgetc(in);
	}
	sort(value+1, value+N+1);
	
	for(int i=1; i<=K*max+1; i++)	dp[i] = MAX;
	dp[0] = 0;
	for(int i=1; i<=N; i++)
		for(int j=value[i]; j<=K*value[i]; j++)
			dp[j] = min(dp[j], dp[j-value[i]]+1);
	int i;
	for(i=1; i<=K*MAX; i++)
		if(dp[i] > K)
			break;
	fprintf(out, "%d\n", i-1);
	return 0;
}