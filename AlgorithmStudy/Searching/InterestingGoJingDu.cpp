#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[105], b[105], n;

bool check(int s)
{
	int r = 0;
	for(int i=1; i<=s; i++)
		r = (r*10 + a[i]) % s;
	return r==0;
}

void dfs(int s)
{
	if(s > 100)
		return;
	for(int i=0; i<=9; i++)
	{
		a[s] = i;
		if(check(s))
		{
			if(s >= n)
			{
				for(int i=1; i<=s; i++)
					b[i] = a[i];
				n = s;
			}
			dfs(s+1);
		}
	}
}

int main()
{
	int time = GetTickCount();
	n=1;
	for(int i=1; i<=9; i++)
	{
		a[1] = i, b[1] = i;
		dfs(2);
	}
	cout<<"n = "<<n<<endl;
	for(int i=1; i<=n; i++)
		cout<<b[i];
	cout<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}