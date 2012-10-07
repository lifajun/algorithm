#include <iostream>
#include <cstring>
using namespace std;

#define MAX 30005

int father[MAX], under[MAX], num[MAX];
//每一个集合（堆栈）的代表都是栈底元素
//father数组用于记录所属集合
//under数组用于记录其所属集合中在它下面的元素的个数
//num数组用于记录每个集合中的元素的个数
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
		father[x] = find(father[x]);/*压缩路径*/
		under[x] += under[t];/*递归依次累加在它下面的元素的个数*/
	}
	return father[x];
}

void union_set(int a, int b)
{
	int f1 = find(a), f2 = find(b);/*合并前需要更新一次父节点*/
	/*只是单纯的把一个堆栈的东西搬到另一个堆栈上，对于被搬的堆栈没有重新定父，也基本无法定*/
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
			find(a);//需要重新定父
			printf("%d\n", under[a]);
		}
	}
	return 0;
}