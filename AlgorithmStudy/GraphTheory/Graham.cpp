#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
	int x, y;
}p[50005], a[50005];
int n;

int crossMulti(Point p0, Point p1, Point p2)//叉乘
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int dist(Point p1, Point p2)
{
	return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

int cmp(Point p1, Point p2)
{
	int res = crossMulti(p[0], p1, p2);
	if(res > 0)	return 1;
	if(res < 0)	return 0;
	return dist(p1, p[0]) < dist(p2, p[0]);
}

int Graham()
{
	int k = 0, top = 0;
	for(int i=1; i<n; i++)
		if((p[i].y < p[k].y) || (p[i].y == p[k].y && p[i].x < p[k].x))
			k = i;
	swap(p[0], p[k]);
	sort(p+1, p+n, cmp);//根据夹角排序，夹角可以通过叉乘来定义，如果P0P1 x P0P2 > 0表示P2在P1的左边
	a[top++] = p[0], a[top++] = p[1], a[top++] = p[2];
	for(int i=3; i<n; i++)
	{
		if(crossMulti(a[top-1], a[top-2], p[i]) <= 0)//循环寻找凸包上的点，如果方向相反，回溯
			a[top++] = p[i];
		else
			top--;
	}
	while(crossMulti(a[top-1], p[0], a[top-2] < 0)	top--;
	return top;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	int cnt = Graham(), ans = 0;
	for(int i=0; i<cnt; i++)
	{
		for(int j=i+1; j<cnt; j++)
		{
			int d = dist(a[i], a[j]);
			if(d > ans)	ans = d;
		}
	}
	printf("%d\n", ans);
	return 0;
}