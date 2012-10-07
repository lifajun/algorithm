/*
ID: lifajun2
PROG: crypt1
LANG: C++
*/
#include <cstdio>
#include <cstring>

int digit[10], N;

bool find(int d)
{
	for(int i=0; i<N; i++)
		if(d == digit[i])	return true;
	return false;
}

bool is_valid(int num)
{
	while(num)
	{
		if(!find(num%10))	return false;
		num /= 10;
	}
	return true;
}

int main()
{
	FILE* in = fopen("crypt1.in", "r");
	FILE* out = fopen("crypt1.out", "w");

	fscanf(in, "%d", &N);
	for(int i=0; i<N; i++)	fscanf(in, "%d", &digit[i]);

	int ans = 0;
	for(int a=0; a<N; a++)
	{
		for(int b=0; b<N; b++)
		{
			for(int c=0; c<N; c++)
			{
				int num1 = digit[a]*100+digit[b]*10+digit[c];
				for(int d=0; d<N; d++)
				{
					int p1 = num1 * digit[d];
					if(p1 >= 1000 || !is_valid(p1)) continue;
					for(int e=0; e<N; e++)
					{
						int p2 = num1 * digit[e], num = num1*(digit[d]*10 + digit[e]);
						if(p2 >= 1000 || num >= 10000 || !is_valid(p2) || !is_valid(num))	continue;
						ans++;
					}
				}
			}
		}
	}
	fprintf(out, "%d\n", ans);
	return 0;
}