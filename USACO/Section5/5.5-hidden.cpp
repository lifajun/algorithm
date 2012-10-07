/*
ID: lifajun2
PROG: hidden
LANG: C++
*/
#include <cstdio>
#include <cstring>

char str[80], pas[100005], p[200010];
int N;

int main()
{
	FILE* fin = fopen("hidden.in", "r");
	FILE* fout = fopen("hidden.out", "w");

	fscanf(fin, "%d", &N);
	fgetc(fin);
	while(fgets(str, 80, fin))
	{
		int len = strlen(str);
		str[len-1] = '\0';
		strcat(pas, str);
	}
	strcpy(p, pas);
	strcat(p, pas);

	int i=0, j=1;
	while(j < N)
	{
		int c, flag = 0;
		for(c = 0; c < N; c++)
		{
			if(p[i+c] < p[j+c]){flag = 1; break;}
			else if(p[i+c] > p[j+c]){flag=2; break;}
		}
		if(c == N){fprintf(fout, "0\n");return 0;}
		if(1 == flag)	j+=(c+1);
		else if(2 == flag) i=j++;
	}
	fprintf(fout, "%d\n", i);
	return 0;
}