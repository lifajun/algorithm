/*
ID: lifajun2
PROG: bigbrn
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;

int min(int a, int b, int c)
{
	int temp = a < b ? a : b;
	return temp < c ? temp : c;
}

int N, dp[1005][1005];

int main()
{
	int M, x, y, max = 0;
	ifstream fin("bigbrn.in");
	ofstream fout("bigbrn.out");
	
	fin>>N>>M;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			dp[i][j] = 1;
	for(int i=1; i<=M; i++)
	{
		fin>>x>>y;
		dp[x][y] = 0;
	}

	for(int i=N; i>=1; i--)
	for(int j=N; j>=1; j--)
	if(dp[i][j])
	{
		dp[i][j] = min(dp[i][j+1], dp[i+1][j], dp[i+1][j+1]) + 1;
		if(dp[i][j] > max)
			max = dp[i][j];
	}

	fout<<max<<endl;
	return 0;
}