/*
ID: lifajun2
PROG: preface
LANG: C++
*/
#include <cstdio>
#include <cstring>

char num[4][10][5] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
{"", "M", "MM", "MMM", "", "", "", "", "", ""}};

int cnt[27] = {0}, N;

inline void deal(int n)
{
	int idx=0;
	while(n)
	{
		int temp = n%10;
		for(unsigned i=0; i<strlen(num[idx][temp]); i++)
			cnt[num[idx][temp][i]-'A']++;
		n/=10, idx++;
	}
}

int main()
{
	FILE* in = fopen("preface.in", "r");
	FILE* out = fopen("preface.out", "w");

	fscanf(in, "%d", &N);
	for(int i=1; i<=N; i++)
		deal(i);

	if(cnt['I'-'A'])fprintf(out, "I %d\n", cnt['I'-'A']);
	if(cnt['V'-'A'])fprintf(out, "V %d\n", cnt['V'-'A']);
	if(cnt['X'-'A'])fprintf(out, "X %d\n", cnt['X'-'A']);
	if(cnt['L'-'A'])fprintf(out, "L %d\n", cnt['L'-'A']);
	if(cnt['C'-'A'])fprintf(out, "C %d\n", cnt['C'-'A']);
	if(cnt['D'-'A'])fprintf(out, "D %d\n", cnt['D'-'A']);
	if(cnt['M'-'A'])fprintf(out, "M %d\n", cnt['M'-'A']);

	return 0;
}