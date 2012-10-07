#include <iostream>
#include <cstring>
using namespace std;

int digit[10], digit2[10];

void getDigit(int number)
{
	memset(digit, 0, sizeof(digit));
	int factor = 1;
	int high,  current, low;

	while(number / factor)
	{
		high = number/(factor*10);
		current = (number/factor)%10;
		low = number - (number/factor)*factor;

		for(int i=0; i<current; i++)
			digit[i] += (high + 1) * factor;
		digit[current] += high * factor + low + 1;
		for(int i=current+1; i<10; i++)
			digit[i] += high*factor;
		digit[0] -= factor;
		factor *= 10;
	}
}

void getDigit2(int n)
{
	memset(digit2, 0, sizeof(digit2));
	for(int i=1; i<=n; i++)
	{
		int j=i;
		while(j)
		{
			digit2[j%10]++;
			j /= 10;
		}
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		getDigit(n);
		getDigit2(n);
		for(int i=0; i<10; i++)
			cout<<digit[i]<<" ";
		cout<<endl;
		for(int i=0; i<10; i++)
			cout<<digit2[i]<<" ";
		cout<<endl;
	}
	return 0;
}