#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[20], total;
bool prime[50];

void getPrime()
{
	prime[1] = false;
	for(int i=2; i<50; i++)
	{
		if(prime[i])
			for(int j=i*i; j<50; j+=i)
				prime[j] = false;
	}
}

bool check(int s, int n)
{
	if(s != n)
		return prime[a[s]+a[s-1]];
	else
		return prime[a[s]+a[s-1]] && prime[a[s]+a[1]];
}

void dfs(int s, int n)
{
	if(s > n)
	{
		for(int i=1; i<=n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
		total++;
	}
	else
	{
		int temp;
		for(int i=s; i<=n; i++)
		{
			temp = a[s], a[s] = a[i], a[i] = temp;
			if(check(s, n))
				dfs(s+1, n);
			temp = a[s], a[s] = a[i], a[i] = temp;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int time = GetTickCount();
	total = 0;
	for(int i=1; i<=n; i++)
		a[i] = i;
	memset(prime, true, sizeof(prime));
	getPrime();
	dfs(2, n);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}