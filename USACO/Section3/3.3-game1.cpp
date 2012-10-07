/*
ID: lifajun2
PROG: game1
LANG: C++
*/
#include <fstream>
using namespace std;

#define max(a, b)(a > b ? a : b)
int a[105], dp[105][105], sum[105][105], N;

int main()
{
	ifstream in("game1.in");
	ofstream out("game1.out");
	
	in>>N;
	for(int i=1; i<=N; i++)
		in>>a[i];
	for(int i=1; i<=N; i++)
		for(int j=i; j<=N; j++)
			sum[i][j] = sum[i][j-1] + a[j];

	for(int i=N; i>=1; i--)
		for(int j=i; j<=N; j++)
			dp[i][j] = max(sum[i+1][j]-dp[i+1][j] + a[i], sum[i][j-1] - dp[i][j-1] + a[j]);

	out<<dp[1][N]<<" "<<sum[1][N] - dp[1][N]<<endl;
	return 0;
}