#include <iostream>
using namespace std;

int P[150005];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &P[i]);
	int ans = 0, flag = 0;
	for(int i=1; i<=n; i++)
	{
		if(P[i] >= P[i-1] && P[i] >= P[i+1] && !flag)
			ans += P[i], flag = 1;
		else if(P[i] <= P[i-1] && P[i] <= P[i+1] && flag)
			ans -= P[i], flag = 0;
	}
	printf("%d\n", ans);
	return 0;
}