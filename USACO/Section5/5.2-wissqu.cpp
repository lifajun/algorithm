/*
ID: lifajun2
PROG: wissqu
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;

char map[4][5];
bool vis[4][4];
int cnt[5], sum = 0;

struct Place
{
	char cow;
	int x, y;
}p[16], pp[16];

bool check(int x, int y, char c)
{
	for(int i=x-1; i<=x+1; i++)
		for(int j=y-1; j<=y+1; j++)
			if(i >= 0 && j >= 0 && i <4  && j < 4 && c == map[i][j])
				return false;
	return true;
}
	
void dfs(int s, char c)
{
	if(s == 16)
	{
		if(sum == 0){for(int i=0; i<16; i++) p[i] = pp[i];}
		sum++;
		return;
	}
	char temp;
	for(int i=0; i<4; i++)
	for(int j=0; j<4; j++)
	if(!vis[i][j] && check(i, j, c))
	{
		vis[i][j] = true;
		temp = map[i][j];
		map[i][j] = c;
		cnt[c-'A']--;
		pp[s].cow = c, pp[s].x = i, pp[s].y = j;
		if(s == 15)
			dfs(16, 0);
		else
		{
			for(int i=0; i<5; i++)
				if(cnt[i])
					dfs(s+1, i+'A');
		}
		vis[i][j] = false;
		map[i][j] = temp;
		cnt[c-'A']++;
	}
}

int main()
{
	ifstream fin("wissqu.in");
	ofstream fout("wissqu.out");

	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<4; i++) fin>>map[i];
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			cnt[map[i][j]-'A']++;
	cnt[3]++, cnt[2]--;
	dfs(0, 'D');

	for(int i=0; i<16; i++)
		fout<<p[i].cow<<" "<<p[i].x+1<<" "<<p[i].y+1<<endl;
	fout<<sum<<endl;

	return 0;
}