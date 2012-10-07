/*
ID: lifajun2
PROG: humble
LANG: C++
*/
#include <cstdio>

int num[100005], p[105], K, N;
int idx[105], tmp[105];

int main()
{
	FILE* in = fopen("humble.in", "r");
	FILE* out = fopen("humble.out", "w");
	
	fscanf(in, "%d %d", &K, &N);
	fgetc(in);
	for(int i=1; i<=K; i++)
		fscanf(in, "%d", &p[i]);

	num[0] = 1;
	for(int i=1; i<=K; i++) idx[i] = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=K; j++)
			tmp[j] = num[idx[j]]*p[j];
		int min = tmp[1], id = 1;
		for(int j=2; j<=K; j++)
			if(tmp[j] < min)
				min = tmp[j], id = j;
		num[i] = min;
		for(int j=1; j<=K; j++)
			if(tmp[j] == min)
				idx[j]++;
	}
	fprintf(out, "%d\n", num[N]);
	return 0;
}