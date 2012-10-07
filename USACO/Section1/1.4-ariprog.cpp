/*
ID: lifajun2
PROG: ariprog
LANG: C++
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool hash[125001];
struct Node
{
	int sta, len;
}nod[10005];

int cmp(Node a, Node b)
{
	if(a.len == b.len)	return a.sta < b.sta;
	return a.len < b.len;
}

void bisquares(int m)
{
	memset(hash, false, sizeof(hash));
	for(int p=0; p<=m; p++)
		for(int q=0; q<=m; q++)
			hash[p*p+q*q] = true;
}

int main()
{
	FILE* in = fopen("ariprog.in", "r");
	FILE* out = fopen("ariprog.out", "w");
	int N, M, cnt=0, n;

	fscanf(in, "%d%d", &N, &M);
	bisquares(M);
	for(int st = 0; st <= 2*M*M; st++)
	for(int le = 1; le <= 2*M*M/(N-1); le++)
	{
		for(n=0; n<N && st + n*le <= 2*M*M && hash[st + n*le]; n++);
		if(n == N)	nod[cnt].sta = st, nod[cnt++].len = le;
	}
	if(cnt == 0)	{fprintf(out, "NONE\n");return 0;}
	sort(nod, nod+cnt, cmp);
	for(int i=0; i<cnt; i++)
		fprintf(out, "%d %d\n", nod[i].sta, nod[i].len);
	return 0;
}