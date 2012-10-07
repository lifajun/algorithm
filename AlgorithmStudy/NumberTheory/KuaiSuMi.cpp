#include <iostream>
using namespace std;

int pow_a(int a, int n)
{
	int result = 1;
	while(n)
	{
		if(n & 1)
			result *= a;
		a *= a;
		n >>= 1;
	}
	return result;
}

int pow_b(int a, int n)
{
	if(n == 0)	return 1;
	int temp = pow_b(a, n/2);
	temp *= temp;
	if(n %2 == 1)
		temp *= a;
	return temp;
}

int main()
{
	int a, n;
	while(cin>>a>>n)
		cout<<pow_a(a, n)<<" "<<pow_b(a, n)<<endl;
	return 0;
}