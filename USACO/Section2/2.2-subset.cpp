/*
ID: lifajun2
PROG: subset
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long long dp[1000], N;

int main()
{
	FILE* in = fopen("subset.in", "r");
	FILE* out = fopen("subset.out", "w");

	fscanf(in, "%d", &N);
	long long sum = (N+1)*N/2;
	if(sum &1)
	{
		fprintf(out, "0\n");
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i=1; i<=N; i++)
		for(long long j=sum/2; j>=i; j--)
			dp[j] += dp[j-i];
	fprintf(out, "%d\n", dp[sum/2]/2);
	return 0;
}