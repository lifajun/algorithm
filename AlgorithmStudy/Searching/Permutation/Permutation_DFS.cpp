#include <iostream>
#include <windows.h>
using namespace std;

int a[15], total;

bool ok(int s)
{
	for(int i=1; i<s; i++)
		if(a[i] == a[s])
			return false;
	return true;
}

void permutation(int s, int n)
{
	if(s > n)
		total++;
	else
	{
		for(int i=1; i<=n; i++)
		{
			a[s] = i;
			if(ok(s))
				permutation(s+1, n);
		}
	}
}

int main()
{
	int time = GetTickCount();
	total = 0;
	permutation(1, 10);
	cout<<total<<endl;
	cout<<GetTickCount()-time<<endl;
	return 0;
}