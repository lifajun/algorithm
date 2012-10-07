#include <iostream>
using namespace std;

int main()
{
	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n%(m+1))
			cout<<"first"<<endl;
		else
			cout<<"second"<<endl;
	}
	return 0;
}