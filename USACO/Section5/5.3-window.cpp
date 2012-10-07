/*
ID: lifajun2
PROG: window
LANG: C++
*/
#include <cstdio>
#include <iostream>
using namespace std;
int area;
FILE* fin = fopen("window.in", "r");
FILE* fout = fopen("window.out", "w");

struct Win
{
	char id;
	int x1, y1, x2, y2;
}win[100];

int win_cnt;

void create(char id, int x1, int y1, int x2, int y2)
{
	for(int i=0; i<win_cnt; i++)
		if(win[i].id == id)	return;
	if(y1 < y2) swap(y1, y2);
	if(x1 > x2) swap(x1, x2);
	win[win_cnt].id = id, win[win_cnt].x1 = x1, win[win_cnt].x2 = x2;
	win[win_cnt].y1 = y1, win[win_cnt++].y2 = y2;
}

void top(char id)
{
	int i;
	for(i=0; i<win_cnt; i++)
		if(win[i].id == id)	break;
	if(i == win_cnt)	return;

	Win temp = win[i];
	for(int j=i; j<win_cnt-1; j++)
		win[j] = win[j+1];
	win[win_cnt-1] = temp;
}

void bottom(char id)
{
	int i;
	for(i=0; i<win_cnt; i++)
		if(win[i].id == id)	break;
	if(i == win_cnt)	return;

	Win temp = win[i];
	for(int j=i; j>=1; j--)
		win[j] = win[j-1];
	win[0] = temp;
}

void destroy(char id)
{
	for(int i=0; i<win_cnt; i++)
	{
		if(win[i].id == id)
		{
			for(int j=i; j<win_cnt-1; j++)
				win[j] = win[j+1];
			win_cnt--;
			break;
		}
	}
}

void getArea(int idx, int x1, int y1, int x2, int y2)
{
	while(idx < win_cnt && (win[idx].x1 > x2 || win[idx].x2 < x1 || win[idx].y1 < y2 || win[idx].y2 > y1))	idx++;
	if(idx == win_cnt) {area += (x2-x1)*(y1-y2);return;};
	if(x1 < win[idx].x1)	getArea(idx+1, x1, y1, win[idx].x1, y2), x1 = win[idx].x1;
	if(x2 > win[idx].x2)	getArea(idx+1, win[idx].x2, y1, x2, y2), x2 = win[idx].x2;
	if(y1 > win[idx].y1)	getArea(idx+1, x1, y1, x2, win[idx].y1);
	if(y2 < win[idx].y2)	getArea(idx+1, x1, win[idx].y2, x2, y2);
}

void output(char id)
{
	int i;
	for(i=0; i<win_cnt; i++)
		if(win[i].id == id)	break;
	if(i == win_cnt)	return;
	area = 0;
	getArea(i+1, win[i].x1, win[i].y1, win[i].x2, win[i].y2);
	fprintf(fout, "%.3lf\n", (double)(area)/(double)((win[i].x2-win[i].x1)*(win[i].y1-win[i].y2))*100);
}

int main()
{
	char cmd[50], id;
	int x1, y1, x2, y2;
	while(fgets(cmd, 50, fin))
	{
		switch(cmd[0])
		{
		case 'w':
			sscanf(cmd+1, "(%c, %d, %d, %d, %d)", &id, &x1, &y1, &x2, &y2);
			create(id, x1, y1, x2, y2);
			break;
		case 't':
			sscanf(cmd+1, "(%c)", &id);
			top(id);
			break;
		case 'b':
			sscanf(cmd+1, "(%c)", &id);
			bottom(id);
			break;
		case 'd':
			sscanf(cmd+1, "(%c)", &id);
			destroy(id);
			break;
		case 's':
			sscanf(cmd+1, "(%c)", &id);
			output(id);
			break;
		default:
			break;
		}
	}
	return 0;
}