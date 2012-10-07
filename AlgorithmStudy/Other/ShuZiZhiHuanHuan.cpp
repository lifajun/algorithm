#include <iostream>
using namespace std;

int arr[10005];

//数字置换环
/*思路：其实就是把一个数放到正确的位置上然后把这个位置上的数放到正确的位置上，
依次循环最后一个数肯定会回到开始那个数的位置上来如3 1 2 ；[1]上的3->[3] ，[3]上的
2->[2]，[2]上的1->[1]。环上个数减一就是环最少移动次数*/
int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d", &arr[i]);
		int ans = 0;
		for(int i=1; i<=n; i++)
		{
			if(arr[i] != i)
			{
				int m = i, tmp, c = 0;//m把当前的i记录下来
				do
				{
					tmp = arr[m];//用tmp把arr[m]暂时存储起来
					arr[m] = m;//把m放到正确的位置上
					m = tmp;//更新m
					c++;
				}while(m != i);
				ans += c-1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}