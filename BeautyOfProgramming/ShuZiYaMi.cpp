#include <iostream>
#include <cstring>
using namespace std;

int arr[10];
bool vis[10];

bool check(int s)
{
	int val = 0;
	for(int i=1; i<=s; i++)
		val = val*10 + arr[i];
	return val % s == 0;
}

void dfs(int s)
{
	if(s > 9)
	{
		for(int i=1; i<=9; i++)	cout<<arr[i];
		cout<<endl;
		return;
	}
	for(int i=1; i<=9; i++)
	{
		if(!vis[i])
		{
			vis[i] = true, arr[s] = i;
			if(check(s))
				dfs(s+1);
			vis[i] = false;
		}
	}
}

int main()
{
	memset(vis, false, sizeof(vis));
	dfs(1);
	return 0;
}