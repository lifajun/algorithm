#include <iostream>
using namespace std;

int count1(int n)
{
	int cnt = 0;
	while(n)
	{
		n &= (n-1);
		cnt++;
	}
	return cnt;
}

int count2(int n)
{
	int cnt = 0;
	while(n)
	{
		cnt += (n & 1);
		n>>=1;
	}
	return cnt;
}

int main()
{
	int n;
	while(cin>>n, n)
		cout<<count1(n)<<endl<<count2(n)<<endl;
	return 0;
}