#include <iostream>
using namespace std;

int arr[10005];

//�����û���
/*˼·����ʵ���ǰ�һ�����ŵ���ȷ��λ����Ȼ������λ���ϵ����ŵ���ȷ��λ���ϣ�
����ѭ�����һ�����϶���ص���ʼ�Ǹ�����λ��������3 1 2 ��[1]�ϵ�3->[3] ��[3]�ϵ�
2->[2]��[2]�ϵ�1->[1]�����ϸ�����һ���ǻ������ƶ�����*/
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
				int m = i, tmp, c = 0;//m�ѵ�ǰ��i��¼����
				do
				{
					tmp = arr[m];//��tmp��arr[m]��ʱ�洢����
					arr[m] = m;//��m�ŵ���ȷ��λ����
					m = tmp;//����m
					c++;
				}while(m != i);
				ans += c-1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}