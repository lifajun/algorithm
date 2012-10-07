/*
ID: lifajun2
PROG: fracdec
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cmath>

int N, D, cnt, c_start;
int r[100000], q[100000];
bool vis[100000];
FILE* in = fopen("fracdec.in", "r");
FILE* out = fopen("fracdec.out", "w");

//FILE* in = fopen("in.txt", "r");
//FILE* out = fopen("out.txt", "w");

int find(int num)
{
	for(int i=0; i<cnt; i++)
		if(r[i] == num)	return i;
	return -1;
}

int getCycle(int n, int d)
{
	memset(vis, false, sizeof(vis));
	cnt = 0;
	r[cnt] = n, vis[n] = true;
	while(n)
	{
		q[cnt++] = n*10/d;
		n = n*10%d;
		if(vis[n])	return n;
		r[cnt] = n, vis[n] = true;
	}
	return 0;
}

void outputline(int& len)
{
	if((len++) % 76 == 0)
	{
		len = 1;
		fprintf(out, "\n");
	}
}

int getLen(int num)
{
	if(num == 0)	return 1;
	int len = 0;
	while(num)
	{
		len++;
		num /= 10;
	}
	return len;
}

int main()
{
	fscanf(in, "%d %d", &N, &D);
	fprintf(out, "%d.", N/D);
	int len = getLen(N/D)+2, num = getCycle(N%D, D);
	if(N%D == 0)
		fprintf(out, "0\n");
	else if(num)
	{
		c_start = find(num);
		for(int i=0; i<c_start; i++)
		{
			fprintf(out, "%d", q[i]);
			outputline(len);
		}
		fprintf(out, "(");
		outputline(len);
		for(int i=c_start; i<cnt; i++)
		{
			fprintf(out, "%d", q[i]);
			outputline(len);
		}
		fprintf(out, ")\n");
	}
	else
	{
		for(int i=0; i<cnt; i++)
		{
			fprintf(out, "%d", q[i]);
			outputline(len);
		}
		fprintf(out, "\n");
	}
	return 0;
}