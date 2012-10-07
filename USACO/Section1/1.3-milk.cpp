/*
ID: lifajun2
PROG: milk
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Farmer
{
	int P, A;
}fa[5005];

int cmp(Farmer f1, Farmer f2)
{
	return f1.P < f2.P;
}

int main()
{
	int N, M, res = 0;
	FILE* in = fopen("milk.in", "r");
	FILE* out = fopen("milk.out", "w");

	fscanf(in, "%d%d", &N, &M);
	for(int i=0; i<M; i++)
		fscanf(in, "%d%d", &fa[i].P, &fa[i].A);
	sort(fa, fa+M, cmp);

	for(int i=0; i<M; i++)
	{
		if(N >= fa[i].A)
		{
			res += fa[i].P * fa[i].A;
			N -= fa[i].A;
		}
		else
		{
			res += N * fa[i].P;
			break;
		}
	}
	fprintf(out, "%d\n", res);
	return 0;
}