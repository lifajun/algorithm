#include <iostream>
using namespace std;

#define INF 100000000

//��������ı��ʣ�ֻ��ҪѰ�Ҵ�0ʱ��֮�������ʱ�����ٵ��Ǹ��˾�����
int main()
{
	int N, v, t, total_time;
	while(scanf("%d", &N), N)
	{
		total_time = INF;
		for(int i=1; i<=N; i++)
		{
			scanf("%d%d", &v, &t);
			if(t >= 0)
			{
				double ti = 4.5*3600/(double)v;
				if(ti - (int)ti > 0)	ti++;
				if(ti + t < total_time)	total_time = ti + t;
			}
		}
		printf("%d\n", total_time);
	}
	return 0;
}