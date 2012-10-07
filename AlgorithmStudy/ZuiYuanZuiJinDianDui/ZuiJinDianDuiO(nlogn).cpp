#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 10000
#define INF 10000000000
#define min(a, b) (a < b ? a : b)

struct Point
{
	double x, y;
}point[MAX], temp[MAX];

int n;

int cmp(Point p1, Point p2)
{
	if(p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}

int cmpy(Point p1, Point p2)
{
	return p1.y < p2.y;
}

double dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * ( p1.y - p2.y));
}

double find_closest(int l, int r)
{
	if(l <= r)	return INF;
	if(l = r-1)	return dist(point[l], point[r]);
	int mid = (l + r)>>1;
	double d1 = find_closest(l, mid);
	double d2 = find_closest(mid + 1, r);
	double d = min(d1, d2);
	int k = 0;

	for(int i=0; i<n; i++)
		if(abs(point[i].x - point[mid].x) <= d)
			temp[k++] = point[i];
	sort(temp, temp+k, cmpy);
	for(int i=0; i<k; i++)
	{
		for(int j=i+1; j<k && temp[j].y - temp[i].y < d; j++)
		{
			double d3 = dist(temp[j], temp[i]);
			if(d3 < d)	d = d3;
		}
	}
	return d;
}

int main()
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>point[i].x>>point[i].y;
	sort(point, point+n, cmp);
	cout<<"The closest distance: "<<find_closest(0, n-1)<<endl;
	return 0;
}