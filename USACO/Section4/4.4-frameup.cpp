/*
ID: lifajun2
PROG: frameup
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;

#define max(a, b)(a > b ? a : b)
#define min(a, b)(a < b ? a : b)

bool map[26][26], used[26], vis[26];
char pic[35][35], res[26];
int H, W, cnt = 0, degree[26];

ifstream in("frameup.in");
ofstream out("frameup.out");

struct Frame
{
	int lx, ly, rx, ry;
}f[26];

void dfs(int s)
{
	if(s == cnt)
	{
		res[s] = '\0';
		out<<res<<endl;
		return;
	}
	for(int i=0; i<26; i++)
	if(used[i] && !vis[i] && degree[i] == 0)
	{
		vis[i] = true;
		for(int j=0; j<26; j++) if(map[i][j]) degree[j]--;
		res[s] = (i+'A');
		dfs(s+1);
		vis[i] = false;
		for(int j=0; j<26; j++)	if(map[i][j]) degree[j]++;
	}
}

int main()
{
	memset(map, false, sizeof(map));
	memset(used, false, sizeof(used));
	memset(vis, false, sizeof(used));
	memset(degree, 0, sizeof(degree));
	for(int i=0; i<26; i++)
	{
		f[i].lx = f[i].ly = 1000;
		f[i].rx = f[i].ry = 0;
	}
	in>>H>>W;
	for(int i=0; i<H; i++)
		in>>pic[i];

	for(int i=0; i<H; i++)
	for(int j=0; j<W; j++)
	if(pic[i][j] != '.')
	{
		used[pic[i][j]-'A'] = true;
		f[pic[i][j]-'A'].lx = min(f[pic[i][j]-'A'].lx, i);
		f[pic[i][j]-'A'].ly = min(f[pic[i][j]-'A'].ly, j);
		f[pic[i][j]-'A'].rx = max(f[pic[i][j]-'A'].rx, i);
		f[pic[i][j]-'A'].ry = max(f[pic[i][j]-'A'].ry, j);
	}

	for(int i=0; i<26; i++)
	if(used[i])
	{
		cnt++;
		for(int j=f[i].lx; j<=f[i].rx; j++)
			if(pic[j][f[i].ly] != i+'A') map[i][pic[j][f[i].ly]-'A'] = true;
		for(int j=f[i].lx; j<=f[i].rx; j++)
			if(pic[j][f[i].ry] != i+'A') map[i][pic[j][f[i].ry]-'A'] = true;
		for(int j=f[i].ly; j<=f[i].ry; j++)
			if(pic[f[i].lx][j] != i+'A') map[i][pic[f[i].lx][j]-'A'] = true;
		for(int j=f[i].ly; j<=f[i].ry; j++)
			if(pic[f[i].rx][j] != i+'A') map[i][pic[f[i].rx][j]-'A'] = true;
	}

	for(int i=0; i<26; i++)
		for(int j=0; j<26; j++)
			if(map[i][j]) degree[j]++;

	dfs(0);

	return 0;
}