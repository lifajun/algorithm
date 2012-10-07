#include <iostream>
using namespace std;

int tran[101][101];

int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			cin>>tran[i][j];
	for(int i=n-1; i>=1; i--)
		for(int j=1; j<=i; j++)
			tran[i][j] = max(tran[i+1][j],  tran[i+1][j+1]) + tran[i][j];
	cout<<tran[1][1]<<endl;
	return 0;
}