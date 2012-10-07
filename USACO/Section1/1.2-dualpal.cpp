/*
ID: lifajun2
PROG: dualpal
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

int used[16], cnt = 0;

void trans(int num, int base, int res[], int& idx)
{
	idx = 0;
	while(num)
	{
		res[idx++] = num % base;
		num /= base;
	}
}

int is_P(int res[], int idx)
{
	int l = 0, r = idx - 1;
	while(l < r)
		if(res[l++] != res[r--])	return 0;
	return 1;
}

bool has_used(int num)
{
	for(int i=0; i<cnt; i++)
		if(used[i] == num)	return true;
	return false;
}

int main()
{
	int N, S, res[40], idx;
	FILE* in = fopen("dualpal.in", "r");
	FILE* out = fopen("dualpal.out", "w");
	fscanf(in, "%d%d", &N, &S);
	for(int s = S+1;;s++)
	{
		int times = 0;
		for(int b = 2; b<=10; b++)
		{
			trans(s, b, res, idx);
			times += is_P(res, idx);
			if(times == 2)
			{
				if(!has_used(s))
				{
					fprintf(out, "%d\n", s);
					used[cnt++] = s;
					if(cnt == N)	return 0;
				}
				break;
			}
		}
	}
	return 0;
}