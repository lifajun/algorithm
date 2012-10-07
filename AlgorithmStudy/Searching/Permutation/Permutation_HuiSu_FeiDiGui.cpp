#include <iostream>
#include <cstring>
using namespace std;

int a[10], n;

bool check(int s)
{
	for(int i=1; i<s; i++)
		if(a[i] == a[s])	return false;
	return true;
}

void output()
{
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	while(cin>>n, n)
	{
		memset(a, 0, sizeof(a));
		int k=1, cnt = 0;

		while(k > 0)
		{
			a[k]++;
			while(a[k] <= n && !check(k))	a[k]++;
			if(a[k] <= n)
			{
				if(k == n)	cnt++;
				else	{k++, a[k] = 0;}
			}
			else	k--;
		}
		cout<<cnt<<endl;
	}
	return 0;
}