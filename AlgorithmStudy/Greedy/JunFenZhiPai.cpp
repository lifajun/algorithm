#include <iostream>
using namespace std;

int a[105];

int main()
{
	int n, sum = 0;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i], sum+=a[i];
	int ans = 0, v = sum/n;
	for(int i=1; i<n; i++)
	{
		if(a[i] != v)
		{
			ans ++;
			a[i+1] = a[i+1] + a[i] - v;
		}
	}
	cout<<ans<<endl;
	return 0;
}