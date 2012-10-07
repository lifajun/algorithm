//树状数组使用：
//1.更新一点，查询一段（正树状数组）
//2.更新一段，查询一点（反数组数组）

#include <iostream>
#include <cstring>
using namespace std;

int matrix[1005][1005], n;

int lowbit(int i)
{
	return i&(-i);
}

void add(int x, int y, int c)
{
	for(int i=x; i<=n; i+=lowbit(i))
		for(int j=y; j<=n; j+=lowbit(j))
			matrix[i][j] += c;
}

int query(int x, int y)
{
	int res = 0;
	for(int i=x; i>0; i-=lowbit(i))
		for(int j=y; j>0; j-=lowbit(j))
			res += matrix[i][j];
	return res;
}

int main()
{
	int T, Q, x1, y1, x2, y2;
	char cmd[5];
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		scanf("%d%d", &n, &Q);
		memset(matrix, 0, sizeof(matrix));
		while(Q--)
		{
			scanf("%s", cmd);
			if(cmd[0] == 'C')
			{
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(x1, y1, 1);
				add(x1, y2+1, -1);
				add(x2+1, y1, -1);
				add(x2+1, y2+1, 1);
			}
			else
			{
				scanf("%d%d", &x1, &y1);
				printf("%d\n", query(x1, y1)&1);
			}
		}
		printf("\n");
	}
	return 0;
}