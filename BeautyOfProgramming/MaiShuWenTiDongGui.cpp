#include <iostream>
#include <algorithm>
using namespace std;

#define max 10000000
#define min(a, b) (a < b ? a : b)

double dp[5][5][5][5][5];
int arr[5];

int cmp(double a, double b){return a > b;}
double deal(double m[][5][5][5][5], int a, int b, int c, int d, int e)
{
	int x[5];
	x[0] = a, x[1] = b, x[2] = c, x[3] = d, x[4] = e;
	sort(x, x+5, cmp);
	return m[x[0]][x[1]][x[2]][x[3]][x[4]];
}

int main()
{
	for(int i=0; i<5; i++)	cin>>arr[i];
	sort(arr, arr+5, cmp); 
	dp[0][0][0][0][0] = 0.0, dp[1][0][0][0][0] = 8.0;
	for(int a=1; a<=arr[0]; a++)
	{
		for(int b=0; b<=a; b++)
			for(int c=0; c<=b; c++)
				for(int d=0; d<=c; d++)
					for(int e=0; e<=d; e++)
					{
						dp[a][b][c][d][e] = max;
						if(e >= 1)	dp[a][b][c][d][e] = min(dp[a][b][c][d][e], 5*8*0.75 + deal(dp, a-1, b-1, c-1, d-1, e-1));
						if(d >= 1)  dp[a][b][c][d][e] = min(dp[a][b][c][d][e], 4*8*0.8 +  deal(dp, a-1, b-1, c-1, d-1, e));
						if(c >= 1)	dp[a][b][c][d][e] = min(dp[a][b][c][d][e], 3*8*0.9 +  deal(dp, a-1, b-1, c-1, d, e));
						if(b >= 1)	dp[a][b][c][d][e] = min(dp[a][b][c][d][e], 2*8*0.95 +  deal(dp, a-1, b-1, c, d, e));
						if(a >= 1)	dp[a][b][c][d][e] = min(dp[a][b][c][d][e], 8 +  deal(dp, a-1, b, c, d, e));
					}
	}
	cout<<dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]]<<endl;
	return 0;
}