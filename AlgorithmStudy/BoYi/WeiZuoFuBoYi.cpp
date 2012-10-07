#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b;
	while(cin>>a>>b)
	{
		if(a > b)
		{
			int temp = a;
			a = b, b = temp;
		}
		int k = b -a;
		int ak = (int)(k*(1.0+sqrt(5.0))/2.0);
		if(ak == a)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}