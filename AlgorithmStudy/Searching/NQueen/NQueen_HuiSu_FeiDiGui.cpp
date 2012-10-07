#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int a[20], n;

int check(int s)
{
	for(int i=1; i<s; i++)
		if(a[i] == a[s] || abs(a[i] - a[s]) == abs(i-s))	return false;
	return true;
}

int main()
{
	while(cin>>n, n)
	{
		memset(a, 0, sizeof(a));
		int k = 1, cnt = 0;

		while(k > 0)
		{
			a[k]++;
			while(a[k] <= n && !check(k)) a[k]++;
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