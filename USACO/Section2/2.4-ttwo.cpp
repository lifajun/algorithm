/*
ID: lifajun2
PROG: ttwo
LANG: C++
*/
#include <cstdio>
#include <cstring>

bool vis[11][11][4][11][11][4];
char map[15][15];
int x1, y1, x2, y2, d1, d2, t=0;

void move(int& x, int& y, int& d)
{
	if(d == 0 && map[x-1][y] == '.')
		x = x - 1;
	else if(d == 1 && map[x][y+1] == '.')
		y = y + 1;
	else if(d == 2 && map[x+1][y] == '.')
		x = x + 1;
	else if(d == 3 && map[x][y-1] == '.')
		y = y - 1;
	else
		d = (d+1)%4;
}

int main()
{
	bool  flag = false;
	FILE* in = fopen("ttwo.in", "r");
	FILE* out = fopen("ttwo.out", "w");
	
	for(int i=0; i<=11; i++)	map[0][i] = '*';
	for(int i=1; i<=10; i++)
	{
		map[i][0] = '*';
		for(int j=1; j<=10; j++)
		{
			map[i][j] = (char)fgetc(in);
			if(map[i][j] == 'C'){x1 = i, y1 = j, map[i][j] = '.';}
			if(map[i][j] == 'F'){x2 = i, y2 = j, map[i][j] = '.';}
		}
		fgetc(in);
		map[i][11] = '*';
	}
	for(int i=0; i<=11; i++)	map[11][i] = '*';

	d1 = 0, d2 = 0;
	memset(vis, false, sizeof(vis));

	while(!vis[x1][y1][d1][x2][y2][d2])
	{
		vis[x1][y1][d1][x2][y2][d2] = true;
		move(x1, y1, d1);
		move(x2, y2, d2);
		t++;
		if(x1 == x2 && y1 == y2){flag = true; break;}
	}

	if(flag)	fprintf(out, "%d\n", t);
	else	fprintf(out, "0\n");

	return 0;
}