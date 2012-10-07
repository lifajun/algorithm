/*
ID: lifajun2
PROG: fc
LANG: C++
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
	double x, y;
}p[10005], Hull[10005];
int N;

double crossProduct(Point p1, Point p2, Point p3)
{
	return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
}

double dist(Point p1, Point p2)
{
	return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

int cmp(Point p1, Point p2)
{
	double pro = crossProduct(p[0], p1, p2);
	if(pro > 0)	return 1;
	if(pro < 0)	return 0;
	return dist(p[0], p1) < dist(p[0], p2);
}

int graham()
{
	int k=0;
	for(int i=1; i<N; i++)
		if((p[i].y < p[k].y) ||(p[i].y == p[k].y && p[i].x < p[k].x))
			k = i;
	swap(p[0], p[k]);
	sort(p+1, p+N, cmp);

	Hull[0] = p[0], Hull[1] = p[1], Hull[2] = p[2];
	int top = 2, i = 3;

	while(i < N)
	{
		if(crossProduct(Hull[top], p[i], Hull[top-1]) >= 0)
			Hull[++top] = p[i++];
		else
			top--;
	}
	while(crossProduct(Hull[top], p[0], Hull[top-1]) < 0) top--;
	return top;
}

int main()
{
	FILE* in = fopen("fc.in", "r");
	FILE* out = fopen("fc.out", "w");
	
	fscanf(in, "%d", &N);fgetc(in);
	for(int i=0; i<N; i++)
	{
		fscanf(in, "%lf %lf", &p[i].x, &p[i].y);
		fgetc(in);
	}

	int cnt = graham();
	double len = 0;
	for(int i=1; i<=cnt; i++)
		len += dist(Hull[i], Hull[i-1]);
	len += dist(Hull[cnt], Hull[0]);

	fprintf(out, "%.2lf\n", len);
	return 0;
}