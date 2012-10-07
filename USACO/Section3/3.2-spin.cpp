/*
ID: lifajun2
PROG: spin
LANG: C++
*/
#include <cstring>
#include <cstdio>

struct Wheel
{
	int speed, cut[6], len[6], size;
}wheel[6];
bool iscut[6][365];

int main()
{
	FILE* in = fopen("spin.in", "r");
	FILE* out = fopen("spin.out", "w");
	
	for(int i=1; i<=5; i++)
	{
		fscanf(in, "%d %d", &wheel[i].speed, &wheel[i].size);
		for(int j=1; j<=wheel[i].size; j++)
			fscanf(in, "%d %d", &wheel[i].cut[j], &wheel[i].len[j]);
		fgetc(in);
	}

	for(int i=0; i<360; i++)
	{
		memset(iscut, false, sizeof(iscut));
		for(int j=1; j<=5; j++)
		{
			for(int k=1; k<=wheel[j].size; k++)
			{
				for(int x=wheel[j].cut[k]; x<=wheel[j].cut[k]+wheel[j].len[k]; x++)
					iscut[j][x%360] = true;
				wheel[j].cut[k] = (wheel[j].cut[k] + wheel[j].speed)%360;
			}
		}
		for(int j=0; j<360; j++)
		{
			bool flag = true;
			for(int k=1; k<=5; k++)
				flag = flag && iscut[k][j];
			if(flag)
			{
				fprintf(out, "%d\n", i);
				return 0;
			}
		}
	}
	fprintf(out, "none\n");
	return 0;
}