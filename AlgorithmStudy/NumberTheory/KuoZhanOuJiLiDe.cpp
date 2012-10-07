#include <iostream>
using namespace std;

int extend_gcd(int a, int b, int& x, int& y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	else
	{
		int _x, _y, result = extend_gcd(b, a%b, _x, _y);
		x = _y, y = _x - (a/b)*_y;
		return result;
	}
}

int main()
{
	int a, b, c, x, y, g;
	while(cin>>a>>b>>c)
	{
		g = extend_gcd(a, b, x, y);
		if(c % g != 0)
		{
			cout<<"No Answer"<<endl;
			continue;
		}
		cout<<a<<" * "<<x*(c/g)<<" + "<< b <<" * " <<y*(c/g)<<" = "<<c<<endl;
	}
	return 0;
}