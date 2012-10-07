#include <iostream>
using namespace std;

int gcd1(int x, int y)
{
	if(x < y)	return gcd1(y, x);
	if(y == 0)	return x;
	if((x & 1) == 0)
	{
		if((y & 1) == 0)	return (gcd1(x >> 1, y >> 1) << 1);
		else	gcd1(x >> 1, y);
	}
	else	if((y & 1) == 0)	return gcd1(x, y >> 1);
	return gcd1(x-y, y);
}

int gcd2(int x, int y){return !y ? x : gcd2(y, x%y);}

int main()
{
	int x, y;
	while(cin>>x>>y)
		cout<<gcd2(x, y)<<endl;
	return 0;
}