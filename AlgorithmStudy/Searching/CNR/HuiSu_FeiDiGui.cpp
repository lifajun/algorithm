#include <iostream>
#include <cstring>
using namespace std;

int a[10], n, r;

bool check(int s)
{
	for(int i=1; i<s; i++)
		if(a[i] >= a[s])	return false;
	return true;
}

void output()
{
	for(int i=1; i<=r; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	while(cin>>n>>r)
	{
		memset(a, 0, sizeof(a));
		int k = 1;

		//�ǵݹ���ݵĻ������
		while(k > 0)//������û�н���������
		{
			a[k]++;
			while(a[k] <= n && !check(k))	a[k]++;//��k���С���������п��ܵ�ֵ
			if(a[k] <= n)//�����k�����ҵ��Ϸ�ֵ
			{
				if(k == r)	output();//�ﵽĿ�꣬���
				else	{k++, a[k] = 0;}//������һ�㣬������һ�α����ͷ��ʼ��������Ϊ�п���k�ǻ��ݻ�ȥ��
			}
			else	k--;//���ݵ���һ��
		}
	}
	return 0;
}