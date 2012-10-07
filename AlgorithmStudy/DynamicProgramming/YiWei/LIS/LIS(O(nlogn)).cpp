#include <iostream>
#include <cstring>
using namespace std;

int arr[40000], dp[40000], rear;
//��һ������dp��¼�˳���Ϊi��������е����һ��Ԫ��
//������Ԫ�������dp[i]����ô���϶�����ͨ��dp[i]����һ������
//Ϊi+1�����У����Զ���ÿ��������������ҪѰ��dp�б���С�����һ������
//�����ŵ���������һ��λ�ü��ɡ��ٶ��ϵ�������½�������

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