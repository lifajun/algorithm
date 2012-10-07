/*
ID: lifajun2
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define max(a, b) (a > b ? a :b)

struct Line
{
	int l, r;
}line[5005];

int cmp(Line l1, Line l2)
{
	return l1.l < l2.l;
}

int main()
{
	int N;
	FILE* in = fopen("milk2.in", "r");
	FILE* out = fopen("milk2.out", "w");

	fscanf(in, "%d", &N);
	for(int i=0; i<N; i++)
		fscanf(in, "%d%d", &line[i].l, &line[i].r);
	sort(line, line+N, cmp);

	int con = line[0].r - line[0].l, idle = 0, t_start = line[0].l, t_end = line[0].r;
	for(int i=1; i<N; i++)
	{
		if(line[i].l <= t_end)
		{
			t_end = max(t_end, line[i].r);
			con = max(con, t_end - t_start);
		}
		else
		{
			idle = max(idle, line[i].l - t_end);
			t_start = line[i].l, t_end = line[i].r;
		}
	}

	fprintf(out, "%d %d\n", con, idle);
	return 0;
}