/*
ID: lifajun2
PROG: milk3
LANG: C++
*/
#include <cstdio>
#include <cstring>
#define max(a, b)(a > b ? a :b)
#define min(a, b)(a < b ? a : b)

bool vis[21][21], bucket[21];
int a, b, c;

//深搜的参数不一定是层数，在这里表示了状态
void dfs(int x, int y, int z)
{
	if(vis[x][y])	return;
	vis[x][y] = true;
	if(x == 0)	bucket[z] = true;
	dfs(max(0, x+y-b), min(x+y, b), z);
	dfs(min(x+y, a), max(0, x+y-a), z);
	dfs(max(0, x+y-c), y, min(x+z, c));
	dfs(min(x+z, a), y, max(0, x+z-a));
	dfs(x, max(0, y+z-c), min(y+z, c));
	dfs(x, min(y+z, b), max(0, y+z-b));
}

int main()
{
	FILE* in = fopen("milk3.in", "r");
	FILE* out = fopen("milk3.out", "w");
	
	fscanf(in, "%d%d%d", &a, &b, &c);
	memset(vis, false, sizeof(vis));
	memset(bucket, false, sizeof(bucket));
	
	dfs(0, 0, c);
	
	int i;
	for(i=0; i<21; i++)
	if(bucket[i])	
		{fprintf(out, "%d", i);break;}
	for(int j=i+1; j<21; j++)
		if(bucket[j])	fprintf(out, " %d", j);
	fprintf(out, "\n");
	
	return 0;
}