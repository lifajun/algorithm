#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[20], total;
bool c[40], d[40];

void dfs(int s, int n)
{
	if(s > n)
		total++;
	else
	{
		int temp;
		for(int i=s; i<=n; i++)
		{
			temp = a[s], a[s] = a[i], a[i] = temp;
			if(!c[s+a[s]] && !d[s-a[s]+n])
			{
				c[s+a[s]] = true, d[s-a[s]+n] = true;
				dfs(s+1, n);
				c[s+a[s]] = false, d[s-a[s]+n] = false;
			}
			temp = a[i], a[i] = a[s], a[s] = temp;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int time = GetTickCount();
	total = 0;
	memset(c, false, sizeof(c));
	memset(d, false, sizeof(d));
	for(int i=1; i<=n; i++)
		a[i] = i;
	dfs(1, n);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}