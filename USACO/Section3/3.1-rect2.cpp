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
}rect[10005], temp, temp2;

int N, max_c, shape[1005], tot, cur_tot;

bool has_no_insert(Rect r1, Rect r2)
{
	return r2.x1 >= r1.x2 || r2.x2 <= r1.x1 || r2.y1 >= r1.y2 || r2.y2 <= r1.y1;
}

void add(int x1, int y1, int x2, int y2, int c)
{
	rect[++tot].x1 = x1, rect[tot].y1 = y1, rect[tot].x2 = x2, rect[tot].y2 = y2, rect[tot].c = c;
}

void cut(Rect r1, Rect r2)
{
	if(r1.x1 < r2.x1)	add(r1.x1, r1.y1, r2.x1, r1.y2, r1.c), r1.x1 = r2.x1;
	if(r2.x2 < r1.x2) add(r2.x2, r1.y1, r1.x2, r1.y2, r1.c), r1.x2 = r2.x2;
	if(r1.y1 < r2.y1) add(r1.x1, r1.y1, r1.x2, r2.y1, r1.c);
	if(r2.y2 < r1.y2) add(r1.x1, r2.y2, r1.x2, r1.y2, r1.c);
}

int main()
{
	FILE* in = fopen("rect1.in", "r");
	FILE* out = fopen("rect1.out", "w");
	
	fscanf(in, "%d %d %d", &rect[0].x2, &rect[0].y2, &N);
	fgetc(in);rect[0].x1 = 0, rect[0].y1 = 0, rect[0].c = 1;tot = 0;
	for(int i=1; i<=N; i++)
	{
		fscanf(in, "%d %d %d %d %d", &temp.x1, &temp.y1, &temp.x2, &temp.y2, &temp.c);
		if(temp.c > max_c)	max_c = temp.c;
		fgetc(in);
		cur_tot = tot;
		for(int i=0; i<=tot; i++)
		{
			if(has_no_insert(rect[i], temp))	continue;
			temp2 = rect[i];
			rect[i--] = rect[cur_tot], rect[cur_tot--] = rect[tot--];
			cut(temp2, temp);
		}
		rect[++tot] = temp;
	}

	for(int i=0; i<=tot; i++)
		shape[rect[i].c] += (rect[i].x2 - rect[i].x1)*(rect[i].y2 - rect[i].y1);

	for(int i=1; i<=max_c; i++)
		if(shape[i])
			fprintf(out, "%d %d\n", i, shape[i]);

	return 0;
}