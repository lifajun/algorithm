/*
ID: lifajun2
PROG: numtri
LANG: C++
*/
#include <cstdio>
#include <cstring>
#define max(a, b)(a > b ? a :b)

int tri[1005][1005], N;

int main()
{
	FILE* in = fopen("numtri.in", "r");
	FILE* out = fopen("numtri.out", "w");

	fscanf(in, "%d", &N);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=i; j++)
			fscanf(in, "%d", &tri[i][j]);

	for(int i=N-1; i>=0; i--)
		for(int j=1; j<=i; j++)
			tri[i][j] = max(tri[i+1][j], tri[i+1][j+1]) + tri[i][j];

	fprintf(out, "%d\n", tri[1][1]);
	
	return 0;
}