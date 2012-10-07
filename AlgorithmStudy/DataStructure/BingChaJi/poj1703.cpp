#include <iostream>
#include <cstring>
using namespace std;

//father�������ڽڵ�n�ĸ��ڵ㣬opp�������ڼ�¼�ڵ�n���෴�ڵ㣬����˵
//n��opp[n]��Ȼ����һ���������棬��ӹ�ϵʱ�������ж�x, y��������ԭ������һ������
//ֻҪ֪��x����y�Ķ������ϣ�y����x�Ķ������Ͼ����ˣ��������Ƿֱ�ӵ���Ӧ�ļ��ϣ�
//
//����ʱ�����x��y��ͬһ���ϣ������ͣ����x��y��opp[x]���ϣ������ͣ������޷�ȷ����

int father[100005], opp[100005];

int find(int x){return father[x] == x ? x : father[x] = find(father[x]);}

void union_set(int x, int y)
{
	int f1 = find(x), f2 = find(y);
	if(f1 != f2)
		father[f1] = f2;
}

int main()
{
	int T, N, M, x, y;
	char cmd[2];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=0; i<=N; i++)
			father[i] = i;
		memset(opp, 0, sizeof(opp));
		while(M--)
		{
			scanf("%s%d%d", cmd, &x, &y);
			if(cmd[0] == 'D')
			{
				if(!opp[x] && !opp[y])
					opp[x] = y, opp[y] = x;
				else if(!opp[x])
				{
					opp[x] = y;
					union_set(x, opp[y]);
				}
				else if(!opp[y])
				{
					opp[y] = x;
					union_set(y, opp[x]);
				}
				else
				{
					union_set(x, opp[y]);
					union_set(y, opp[x]);
				}
			}
			else
			{
				if(find(x) == find(y))
					printf("In the same gang.\n");
				else if(find(x) == find(opp[y]))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}