/*
ID: lifajun2
PROG: fact4
LANG: C++
*/
#include <cstdio>

int num[4500], N;

int main()
{
	FILE* in = fopen("fact4.in", "r");
	FILE* out = fopen("fact4.out", "w");
	
	fscanf(in, "%d", &N);
	int cnt_5 = 0, copy = N;
	while(copy)
	{
		copy/=5;
		cnt_5 += copy;
	}
	for(int i=1; i<=N; i++)	num[i] = i;
	for(int i=5; i<=N; i+=5)
		while(num[i] % 5 == 0)
			num[i] /= 5;
	for(int i=1; i<=N && cnt_5; i++)
	{
		while(cnt_5 && num[i] % 2 == 0)
			num[i] /= 2, cnt_5--;
	}
	int ans = 1;
	for(int i=1; i<=N; i++)
		ans = ans*num[i]%10;
	fprintf(out, "%d\n", ans);

	return 0;
}