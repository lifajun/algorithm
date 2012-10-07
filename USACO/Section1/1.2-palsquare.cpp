/*
ID: lifajun2
PROG: palsquare
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

int base, tmp1[20], id1, tmp2[20], id2;

void trans(int num, int res[], int& idx)
{
	idx = 0;
	while(num)
	{
		res[idx++] = num % base;
		num /= base;
	}
}

bool is_P(int res[], int idx)
{
	int l = 0, r = idx - 1;
	while(l < r)
		if(res[l++] != res[r--])	return false;
	return true;
}

void output(int res[], int idx, FILE* out)
{
	for(int i=idx-1; i>=0; i--)
	{
		if(res[i] >= 10)
			fprintf(out, "%c", (char)(res[i] - 10 + 'A'));
		else
			fprintf(out, "%d", res[i]);
	}
}

int main()
{
	FILE* in = fopen("palsquare.in", "r");
	FILE* out = fopen("palsquare.out", "w");
	fscanf(in, "%d", &base);
	for(int i=1; i<=300; i++)
	{
		trans(i*i, tmp1, id1);
		if(is_P(tmp1, id1))
		{
			trans(i, tmp2, id2);
			output(tmp2, id2, out);
			fprintf(out, " ");
			output(tmp1, id1, out);
			fprintf(out, "\n");
		}
	}
	return 0;
}