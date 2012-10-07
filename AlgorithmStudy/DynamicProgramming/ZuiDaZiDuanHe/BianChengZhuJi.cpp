#include <iostream>
using namespace std;

int main()
{
	int val, n;
	int max = 0, cur = 0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>val;
		cur += val;
		if(cur > max)	max = cur;
		if(cur < 0)	cur = 0;
	}
	cout<<max<<endl;
	return 0;
}