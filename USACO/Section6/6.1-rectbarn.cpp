/*
ID: lifajun2
PROG: rectbarn
LANG: C++
*/
#include <cstdio>
#include <cstring>

#define MAXN 3001
#define INF 4000
#define min(a, b) ((a == 0 ? INF : a) < b ? a : b)
#define max(a, b) (a > b ? a : b)

bool map[MAXN][MAXN];
int h[MAXN], l[MAXN], r[MAXN], R, C, P;

//S=h[i,j]×(l[i,j]+r[i,j]-1)。
//h[i,j]=h[i-1,j]+1               (i,j)是好点
// 0                               (i,j)是坏点 
//l[i,j]=min(l[i-1,j],tl[i,j])    (i,j)是好点
// ∞                                   (i,j)是坏点 
//r[i,j]=min(r[i-1,j],tr[i,j])    (i,j)是好点
// ∞                                   (i,j)是坏点


int main()
{
	int x, y, ans = 0;
	FILE* fin = fopen("rectbarn.in", "r");
	FILE* fout = fopen("rectbarn.out", "w");

	memset(map, true, sizeof(map));
	memset(h, 0, sizeof(h));
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	fscanf(fin, "%d %d %d", &R, &C, &P);
	for(int i=1; i<=P; i++)
	{
		fscanf(fin, "%d %d", &x, &y);
		map[x][y] = false;
	}

	for(int i=1; i<=R; i++)
	{
		int k=0;
		for(int j=1; j<=C; j++)
		{
			if(map[i][j])
			{
				h[j] = h[j]+1;
				k++;
				l[j] = min(l[j], k);
			}
			else
				h[j] = 0, l[j] = 0, k = 0;
		}
		k = 0;
		for(int j=C; j>=1; j--)
		{
			if(map[i][j])
			{
				k++;
				r[j] = min(r[j], k);
				ans = max(ans, (l[j] + r[j] - 1)*h[j]);
			}
			else
				r[j] = 0, k = 0;
		}
	}

	fprintf(fout, "%d\n", ans);
	return 0;
}