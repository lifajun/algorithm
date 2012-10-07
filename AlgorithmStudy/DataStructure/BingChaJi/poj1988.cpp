#include <iostream>
#include <cstring>
using namespace std;

#define MAX 30005

int father[MAX], under[MAX], num[MAX];
//ÿһ�����ϣ���ջ���Ĵ�����ջ��Ԫ��
//father�������ڼ�¼��������
//under�������ڼ�¼���������������������Ԫ�صĸ���
//num�������ڼ�¼ÿ�������е�Ԫ�صĸ���
void init()
{
	for(int i=0; i<MAX; i++)
	{
		father[i] = i;
		under[i] = 0;
		num[i] = 1;
	}
}

int find(int x)
{
	if(father[x] != x)
	{
		int t = father[x];
		father[x] = find(father[x]);/*ѹ��·��*/
		under[x] += under[t];/*�ݹ������ۼ����������Ԫ�صĸ���*/
	}
	return father[x];
}

void union_set(int a, int b)
{
	int f1 = find(a), f2 = find(b);/*�ϲ�ǰ��Ҫ����һ�θ��ڵ�*/
	/*ֻ�ǵ����İ�һ����ջ�Ķ����ᵽ��һ����ջ�ϣ����ڱ���Ķ�ջû�����¶�����Ҳ�����޷���*/
	father[f1] = f2;
	under[f1] += num[f2];
	num[f2] += num[f1];
}

int main()
{
	int P, a, b;
	char cmd[2];
	scanf("%d", &P);
	init();
	while(P--)
	{
		scanf("%s", cmd);
		if(cmd[0] == 'M')
		{
			scanf("%d%d", &a, &b);
			union_set(a, b);
		}
		else
		{
			scanf("%d", &a);
			find(a);//��Ҫ���¶���
			printf("%d\n", under[a]);
		}
	}
	return 0;
}