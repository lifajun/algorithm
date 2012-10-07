/*
ID: lifajun2
PROG: shopping
LANG: C++
*/
#include <fstream>
#include <map>
using namespace std;

#define min(a, b) (a < b ? a : b)

map<int, int> m;
int s_offers[100][6], num[6], price[6], s, cnt = 0;
int dp[6][6][6][6][6];

int getCnt(int c)
{
	map<int, int>::iterator it = m.find(c);
	if(it == m.end())	m[c] = ++cnt;
	return m[c];
}

int main()
{
	int n, c, k, b, p;
	ifstream in("shopping.in");
	ofstream out("shopping.out");

	in>>s;
	for(int i=1; i<=s; i++)
	{
		in>>n;
		for(int j=1; j<=n; j++)
		{
			in>>c>>k;
			s_offers[i][getCnt(c)] = k;
		}
		in>>s_offers[i][0];
	}
	in>>b;
	for(int i=1; i<=b; i++)
	{
		in>>c>>k>>p;
		num[getCnt(c)] = k;
		price[getCnt(c)] = p;
	}

	for(int a=0; a<=num[1]; a++)
	for(int b=0; b<=num[2]; b++)
	for(int c=0; c<=num[3]; c++)
	for(int d=0; d<=num[4]; d++)
	for(int e=0; e<=num[5]; e++)
	{
		dp[a][b][c][d][e] = a*price[1] + b*price[2] + c*price[3] + d*price[4] + e*price[5];
		for(int i=1; i<=s; i++)
		{
			if(a >= s_offers[i][1] && b >= s_offers[i][2] && c >= s_offers[i][3] 
			&& d >= s_offers[i][4] && e >= s_offers[i][5])
				dp[a][b][c][d][e] = min(dp[a][b][c][d][e], 
				dp[a-s_offers[i][1]][b-s_offers[i][2]][c-s_offers[i][3]][d-s_offers[i][4]][e-s_offers[i][5]] + s_offers[i][0]);
		}
	}

	out<<dp[num[1]][num[2]][num[3]][num[4]][num[5]]<<endl;
	return 0;
}