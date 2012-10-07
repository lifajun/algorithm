/*
ID: lifajun2
PROG: hamming
LANG: C++
*/
#include <cstdio>

int cwords[65], N, B, D;
bool finished;

int ham_dist(int a, int b)
{
	int res = a ^ b, c1 = 0;
	while(res)
	{
		res = res&(res-1);
		c1++;
	}
	return c1;
}

void dfs(int s)
{
	if(s > N)
	{
		finished = true;
		return;
	}
	for(int i=cwords[s-1]+1; i<(1<<B); i++)
	{
		bool flag = true;
		for(int j=1; j<s; j++)
		if(ham_dist(cwords[j], i)	< D)	{flag=false;break;}
		if(flag)
		{
			cwords[s] = i;
			dfs(s+1);
			if(finished)	return;
		}
	}
}

int main()
{
	FILE* in = fopen("hamming.in", "r");
	FILE *out = fopen("hamming.out", "w");

	fscanf(in, "%d%d%d", &N, &B, &D);
	finished = false;
	cwords[0] = -1;
	dfs(1);

	for(int i=1; i<=N; i++)
	{
		if((i-1)%10 == 0)	fprintf(out, "%d",cwords[i]); 
		else fprintf(out, " %d", cwords[i]);
		if(i%10 == 0)	fprintf(out, "\n");
	}
	if(N%10 != 0)	fprintf(out, "\n");

	return 0;
}