/*
ID: lifajun2
PROG: rect1
LANG: C++
*/
#include <cstdio>
#include <cstring>

struct Rect
{
	int x1, y1, x2, y2, c;
}rect[1005];

int N, current_c, max_c, shape[1005];

//漂浮法：每一个版从最底层往最上层漂浮，遇到阻挡就变成最多四块继续漂浮
void cal(int x1, int y1, int x2, int y2, int idx)
{
	while(idx <= N && (x1 >= rect[idx].x2 || y1 >= rect[idx].y2 || x2 <= rect[idx].x1 || y2 <= rect[idx].y1))	idx++;
	if(idx > N)	shape[current_c] += (x2-x1) * (y2-y1);
	else//矩形切割
	{
		if(x1 < rect[idx].x1)	cal(x1, y1, rect[idx].x1, y2, idx+1), x1 = rect[idx].x1;
		if(x2 > rect[idx].x2)	cal(rect[idx].x2, y1, x2, y2, idx+1), x2 = rect[idx].x2;
		if(y1 < rect[idx].y1)	cal(x1, y1, x2, rect[idx].y1, idx+1);
		if(y2 > rect[idx].y2)	cal(x1, rect[idx].y2, x2, y2, idx+1);
	}
}

int main()
{
	FILE* in = fopen("rect1.in", "r");
	FILE* out = fopen("rect1.out", "w");
	
	fscanf(in, "%d %d %d", &rect[0].x2, &rect[0].y2, &N);
	fgetc(in);rect[0].x1 = 0, rect[0].y1 = 0, rect[0].c = 1;
	for(int i=1; i<=N; i++)
	{
		fscanf(in, "%d %d %d %d %d", &rect[i].x1, &rect[i].y1, &rect[i].x2, &rect[i].y2, &rect[i].c);
		if(rect[i].c > max_c)	max_c = rect[i].c;
		fgetc(in);
	}

	for(int i=0; i<=N; i++)
	{
		current_c = rect[i].c;
		cal(rect[i].x1, rect[i].y1, rect[i].x2, rect[i].y2, i+1);
	}

	for(int i=1; i<=max_c; i++)
		if(shape[i])
			fprintf(out, "%d %d\n", i, shape[i]);

	return 0;
}