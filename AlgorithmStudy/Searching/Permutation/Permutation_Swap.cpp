#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int a[25], total;

void permutation(int s, int n)
{
	if(s > n)
		total++;
	else
	{
		int temp;
		for(int i=s; i<=n; i++)
		{
			temp = a[s], a[s] = a[i], a[i] = temp;
			permutation(s+1, n);
			temp = a[i], a[i] = a[s], a[s] = temp;
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