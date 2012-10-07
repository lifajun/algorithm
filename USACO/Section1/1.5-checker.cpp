/*
ID: lifajun2
PROG: checker
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

FILE* in = fopen("checker.in", "r");
FILE* out = fopen("checker.out", "w");

bool a[15], b[30], c[30];
int N, ans[15], cnt=0, num = 0;

void dfs(int s)
{
	if(s > N)
	{
		if(cnt < 3)
		{
			fprintf(out, "%d", ans[1]);
			for(int i=2; i<=N; i++)
				fprintf(out, " %d", ans[i]);
			fprintf(out, "\n");
			cnt++;
		}
		num++;
	}
	else
	{
		for(int i=1; i<=N; i++)
			if(!a[i] && !b[s-i+N] && !c[i+s])
			{
				a[i] = true; b[s-i+N] = true; c[i+s] = true;
				ans[s] = i;
				dfs(s+1);
				a[i] = false; b[s-i+N] = false; c[i+s] = false;
			}
	}
}

int main()
{
	fscanf(in, "%d", &N);
	dfs(1);
	fprintf(out, "%d\n", num);
	return 0;
}