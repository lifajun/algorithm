#include <iostream>
#include <cstring>
using namespace std;

int big_mod(char m[], int n)
{
	int ans = 0;
	for(unsigned i=0; i<strlen(m); i++)
		ans = (ans*10+m[i]-'0')%n;
	return ans;
}

int main()
{
	char m[10];
	int n;
	while(cin>>m>>n)
		cout<<big_mod(m, n)<<endl;
	return 0;
}