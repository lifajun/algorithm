/*
ID: lifajun2
PROG: barn1
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool stall[205];
int no_cow[205], cnt = 0;

int main()
{
	FILE* in = fopen("barn1.in", "r");
	FILE* out = fopen("barn1.out", "w");
	int M, S, C, v, min = 205, max = 0;

	fscanf(in, "%d%d%d", &M, &S, &C);
	memset(stall, false, sizeof(stall));
	memset(no_cow, 0, sizeof(no_cow));
	for(int i=0; i<C; i++)
	{
		fscanf(in, "%d", &v);
		stall[v] = true;
		if(v < min)	min = v;
		if(v > max) max = v;
	}

	int i=min;
	while(i <= max)
	{
		if(!stall[i])
		{
			for(;!stall[i]; i++) no_cow[cnt]++;
			cnt++;
		}
		i++;
	}
	sort(no_cow, no_cow+cnt);

	int ans = max-min+1;
	for(int i=1, j = cnt-1; i<M && j >= 0; i++, j--)
		ans -= no_cow[j];

	fprintf(out, "%d\n", ans);
	return 0;
}