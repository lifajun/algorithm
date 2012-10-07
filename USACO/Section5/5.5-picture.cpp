/*
ID: lifajun2
PROG: picture
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
struct Line
{
	int id, l, r, start;
}lnx[MAX], lny[MAX];
int N, level[2*MAX+10];

int cmp(Line l1, Line l2)
{
	if(l1.id == l2.id)
	{
		if(l1.start && !l2.start)
			return 1;
		else if(!l1.start && l2.start)
			return 0;
		else
			return l1.l < l2.l;
	}
	return l1.id < l2.id;
}

int getAnswer(Line ln[])
{
	int ans = 0;
	memset(level, 0, sizeof(level));
	for(int i=0; i<2*N; i++)
	{
		if(ln[i].start)
		{
			for(int j=ln[i].l; j<ln[i].r; j++)
			{
				level[j]++;
				if(level[j] == 1)	ans++;
			}
		}
		else
		{
			for(int j=ln[i].l; j<ln[i].r; j++)
			{
				level[j]--;
				if(level[j] == 0)	ans++;
			}
		}
	}
	return ans;
}

int main()
{
	int x1, y1, x2, y2;
	ifstream fin("picture.in");
	ofstream fout("picture.out");

	fin>>N;
	for(int i=0; i<N; i++)
	{
		fin>>x1>>y1>>x2>>y2;
		lnx[2*i].id = y1, lnx[2*i].start = 1, lnx[2*i].l = x1 + MAX, lnx[2*i].r = x2 + MAX;
		lnx[2*i+1].id = y2, lnx[2*i+1].start = 0, lnx[2*i+1].l = x1 + MAX, lnx[2*i+1].r = x2 + MAX;
		lny[2*i].id = x1, lny[2*i].start = 1, lny[2*i].l = y1 + MAX, lny[2*i].r = y2 + MAX;
		lny[2*i+1].id = x2, lny[2*i+1].start = 0, lny[2*i+1].l = y1 + MAX, lny[2*i+1].r = y2 + MAX;
	}

	sort(lnx, lnx+2*N, cmp);
	sort(lny, lny+2*N, cmp);

	fout<<getAnswer(lnx) + getAnswer(lny)<<endl;

	return 0;
}