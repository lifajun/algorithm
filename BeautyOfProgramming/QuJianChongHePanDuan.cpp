#include <iostream>
#include <algorithm>
using namespace std;

#define max(a, b)(a > b  ? a : b)

struct line
{
	int low, high;
	bool operator<(line e) const
	{return low < e.low;}
}Line[1000];

int n, cnt = 0;

int getIndex(int key)
{
	int l = 0, r = cnt-1;
	while(l < r)
	{
		int m = (l+r) >> 1;
		if(key >= Line[m].low)
			l = m;
		else
			r = m-1;
	}
	return l;
}

int main()
{
	int low, high;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>Line[i].low>>Line[i].high;
	cin>>low>>high;
	sort(Line, Line+n);//≈≈–Ú
	int lasthigh = Line[0].high;
	for(int i=1; i<n; i++)//∫œ≤¢
	{
		if(Line[i].low <= lasthigh)
			lasthigh = max(lasthigh, Line[i].high);
		else
		{
			Line[cnt++].high = lasthigh;
			Line[cnt].low = Line[i].low;
			lasthigh = Line[i].high;
		}
	}
	Line[cnt++].high = lasthigh;
	int s1 = getIndex(low);//≤È’“
	int s2 = getIndex(high);
	if(s1 == s2 && high <= Line[s1].high)
		cout<<"Yes"<<endl;
	else	cout<<"No"<<endl;

	return 0;
}