#include <iostream>
#include <cstring>
using namespace std;

int arr[40000], dp[40000], rear;
//用一个数组dp记录了长度为i的最长子序列的最后一个元素
//新来的元素如果比dp[i]大，那么它肯定可以通过dp[i]构建一个长度
//为i+1的序列，所以对于每个新来的数，需要寻找dp中比它小的最后一个数，
//把它放到该数的下一个位置即可。百度上的是最长不下降子序列

int binarySearch(int a)
{
	int l = 1, r = rear;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(dp[mid] >= a)	r = mid-1;
		else	l = mid+1;
	}
	if(r + 1 > rear)
		rear++;
	return r+1;
}

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d", &arr[i]);
		dp[rear=1] = arr[1];
		for(int i=2; i<=n; i++)
			dp[binarySearch(arr[i])] = arr[i];
		printf("%d\n", rear);
	}
	return 0;
}