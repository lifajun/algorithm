#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[20], total;
bool b[20], c[40], d[40];

void dfs(int s, int n)
{
	if(s > n)
		total++;
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(!b[i] && !c[i-s+n] && !d[i+s])
			{
				b[i] = true, c[i-s+n] = true, d[i+s] = true;
				a[s] = i;
				dfs(s+1, n);
				b[i] = false, c[i-s+n] = false, d[i+s] = false;
			}
		}
	}
}

int main()
{
	int time = GetTickCount();
	total = 0;
	memset(b, false, sizeof(b));
	memset(c, false, sizeof(c));
	memset(d, false, sizeof(d));
	dfs(1, 11);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}