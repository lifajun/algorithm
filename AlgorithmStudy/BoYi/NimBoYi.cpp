#include <iostream>
using namespace std;

int main()
{
	int n, a[100];
	while(cin>>n)
	{
		int sum = 0, ans = 0;
		for(int i=1; i<=n; i++)
			cin>>a[i], sum ^= a[i];
		for(int i=1; i<=n; i++)
			if(a[i] > (sum ^ a[i]))
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}