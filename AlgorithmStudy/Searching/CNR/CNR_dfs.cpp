#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[25], total, n, r;

bool check(int s)
{
	if(a[s] < s ||  a[s] > (n-r+s))
		return false;
	for(int i=1; i<s; i++)
		if(a[i] >= a[s])
			return false;
	return true;
}

void dfs(int s)
{
	if(s > r)
	{
		for(int i=1; i<=r; i++)
			cout<<a[i]<<" ";
		cout<<endl;
		total++;
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			a[s] = i;
			if(check(s))
				dfs(s+1);
		}
	}
}

int main()
{
	cin>>n>>r;
	int time = GetTickCount();
	total = 0;
	dfs(1);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}