/*
ID: lifajun2
PROG: frac1
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct Num
{
	double val;
	int up, down;
}num[160*160];

int cmp(Num n1, Num n2)
{
	return n1.val < n2.val;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int cnt = 0, N;
	FILE* in = fopen("frac1.in", "r");
	FILE* out = fopen("frac1.out", "w");

	fscanf(in, "%d", &N);
	for(int i=1; i<N; i++)
		for(int j=i+1; j<=N; j++)
			if(gcd(i, j) == 1)
				num[cnt].up = i, num[cnt].down = j, num[cnt++].val = (double)i/(double)j;

	fprintf(out, "0/1\n");
	sort(num, num+cnt, cmp);
	for(int i=0; i<cnt; i++)
		fprintf(out, "%d/%d\n", num[i].up, num[i].down);
	fprintf(out, "1/1\n");
	return 0;
}