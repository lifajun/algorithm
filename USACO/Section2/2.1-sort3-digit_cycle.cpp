/*
ID: lifajun2
PROG: sort3
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int a[1005], sorted[1005];
queue<int> pa[1005];
//�����û�����һ��δ�����������Ҫ�Ľ������ٵĴ����Դﵽ����
//����ÿ�������ȷŵ�����ȷ��λ����ȥ���Ӷ��γ���һ������

//ͨ��һ������������Ѱ�������û�����
//pa[i]��ʾδ����������iռ������������������Щ����λ�ã�
//Ȼ������������飬������ͬʱɾ��һ���������ֻ������ֳ��ӣ���ÿһ����
//��Ҫ��������С����Ϊ���ĳ��ȼ�һ������ֱ�����еĶ���Ϊ�գ�ֹͣ��
int main()
{
	int N, ans = 0;
	FILE* in = fopen("sort3.in", "r");
	FILE *out = fopen("sort3.out", "w");

	fscanf(in, "%d", &N);
	for(int i=0; i<N; i++)
		fscanf(in, "%d", &a[i]);
	memcpy(sorted, a, sizeof(a));
	
	sort(sorted, sorted+N);
	for(int i=0; i<N; i++)
		if(a[i] != sorted[i])
			pa[a[i]].push(sorted[i]);

	for(int i=1; i<=3; i++)
	{
		while(!pa[i].empty())
		{
			int  t = pa[i].front(), len = 1;
			pa[i].pop();
			while(t != i)
			{
				int temp = t;
				t = pa[temp].front();pa[temp].pop();
				len++;
			}
			ans += len-1;
		}
	}
	fprintf(out, "%d\n", ans);
	return 0;
}