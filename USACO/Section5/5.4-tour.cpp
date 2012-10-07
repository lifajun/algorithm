/*
ID: lifajun2
PROG: tour
LANG: C++
*/
#include <fstream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int N, M, dp[105][105];
bool cand[105][105];

int main()
{
	ifstream fin("tour.in");
	ofstream fout("tour.out");

	map<string, int> m;
	string city, city2;
	fin>>N>>M;

	for(int i=1; i<=N; i++)
	{
		fin>>city;
		m[city] = i;
	}

	memset(cand, false, sizeof(cand));
	for(int i=1; i<=M; i++)
	{
		fin>>city>>city2;
		cand[m[city]][m[city2]] = true;
		cand[m[city2]][m[city]] = true;
	}

	memset(dp, -1, sizeof(dp));
	dp[1][1] = 1;
	for(int i=1; i<N; i++)
	for(int j=i+1; j<=N; j++)
	{
		for(int k=1; k<j; k++)
		if(cand[k][j] && dp[i][k] &&dp[i][k] > dp[i][j])
			dp[i][j] = dp[i][k];
		dp[j][i] = ++dp[i][j];
	}

	int max = 1;
	for(int i=1; i<N; i++)
		if(cand[i][N] && dp[i][N] > max)
			max = dp[i][N];

	fout<<max<<endl;
	return 0;
}