#include <iostream>
using namespace std;

int count(int n, int k)
{
	int cnt = 0;
	while(n)
	{
		n /= k;
		cnt += n;
	}
	return cnt;
}

int main()
{
	int n, k;
	while(cin>>n>>k)
		cout<<count(n, k)<<endl;
	return 0;
}