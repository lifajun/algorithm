/*
ID: lifajun2
PROG: kimbits
LANG: C++
*/
#include <cstdio>
#include <cstring>

int N, L;
unsigned dp[32][32], I;
FILE* in = fopen("kimbits.in", "r");
FILE* out = fopen("kimbits.out", "w");

void getCount()
{
	for(int i=0; i<32; i++)	dp[i][0] = 1;
	for(int j=0; j<32; j++)	dp[0][j] = 1;
	for(int i=1; i<=31; i++)
		for(int j=1; j<=31; j++)
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
}

void print(int n, int l, unsigned i)
{
	if(n == 0)	return;
	unsigned value = dp[n-1][l];
	if(value >= i)
	{
		fprintf(out, "0");
		print(n-1, l, i);
	}
	else
	{
		fprintf(out, "1");
		print(n-1, l-1, i-value);
	}
}

int main()
{
	fscanf(in, "%d %d %u", &N, &L, &I);
	getCount();
	print(N, L, I);
	fprintf(out, "\n");
	return 0;
}