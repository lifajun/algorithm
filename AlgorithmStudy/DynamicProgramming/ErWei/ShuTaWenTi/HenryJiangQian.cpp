#include <iostream>
using namespace std;

int map[100][100];

int main()
{
	int m, n;
	cin>>m>>n;

	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			cin>>map[i][j];

	for(int i=2; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int max = map[i-1][j];
			for(int k=j-2; k<=j+2; k++)
			{
				if(k>= 0 && k<=n && (map[i-1][k] > max))
					max = map[i-1][k];
			}
			map[i][j] = max +map[i][j];
		}
	}

	int ans = map[m][n/2];
	for(int i=n/2-2; i<=n/2+2; i++)
		if(i>= 0 && i<=n && map[m][i] > ans)
			ans = map[m][i];

	cout<<ans<<endl;
	return 0;
}
