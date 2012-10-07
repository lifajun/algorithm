#include <iostream>
#include <cmath>
using namespace std;

//Å·À­º¯Êý£º
//phi(n) = n*(1-1/p1)*(1-1/p2)*...*(1-1/pn)

int main()
{
	int n, ans;
	cin>>n;
	ans = n;
	for(int i=2; i<sqrt((double)n); i++)
	{
		if(n%i == 0)
		{
			ans -= ans/i;
			while(n%i)	n /= i;
		}
	}
	if(n>1)
		ans -= ans/n;
	cout<<ans<<endl;
	return 0;
}