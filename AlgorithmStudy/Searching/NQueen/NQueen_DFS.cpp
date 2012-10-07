#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int a[15], total;

bool ok(int s)
{
	for(int i=1; i<s; i++)
		if(a[i] == a[s] || abs(a[i] - a[s]) == abs(i - s))
			return false;
	return true;
}

void dfs(int s, int n)
{
	if(s >  n)
		total++;
	else
	{
		for(int i=1; i<=n; i++)
		{
			a[s] = i;
			if(ok(s))
				dfs(s+1, n);
		}
	}
}

int main()
{
	int time = GetTickCount();
	total = 0;
	dfs(1, 9);
	cout<<total<<endl;
	cout<<GetTickCount() - time<<endl;
	return 0;
}