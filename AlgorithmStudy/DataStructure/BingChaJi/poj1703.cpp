#include <iostream>
#include <cstring>
using namespace std;

//father数组用于节点n的父节点，opp数组用于记录节点n的相反节点，即是说
//n和opp[n]必然不在一个集合里面，添加关系时，不必判断x, y到底属于原来的哪一个集合
//只要知道x属于y的对立集合，y属于x的对立集合就行了（即把他们分别加到对应的集合）
//
//查找时，如果x，y在同一集合，不解释，如果x在y的opp[x]集合，不解释，否则无法确定。

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