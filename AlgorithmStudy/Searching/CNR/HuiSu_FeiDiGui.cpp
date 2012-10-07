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

		//非递归回溯的基本框架
		while(k > 0)//当回溯没有结束，继续
		{
			a[k]++;
			while(a[k] <= n && !check(k))	a[k]++;//第k层从小到大尝试所有可能的值
			if(a[k] <= n)//加入第k层能找到合法值
			{
				if(k == r)	output();//达到目标，输出
				else	{k++, a[k] = 0;}//进入下一层，但是下一次必须从头开始搜索，因为有可能k是回溯回去的
			}
			else	k--;//回溯到上一层
		}
	}
	return 0;
}