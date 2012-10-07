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

void deal(int n)
{
	int factor = 1, idx = 0, low, current, high;

	while(n/factor)
	{
		low = n - (n/factor)*factor;
		current = (n/factor)%10;
		high = n/(factor*10);

		for(int i=1; i<current; i++)
			for(unsigned j=0; j<strlen(num[idx][i]); j++)
				cnt[num[idx][i][j]-'A'] += (high+1)*factor;
		for(unsigned j=0; j<strlen(num[idx][current]); j++)
			cnt[num[idx][current][j]-'A'] += (low+1);
		for(int i=current; i<=9; i++)
			for(unsigned j=0; j<strlen(num[idx][i]); j++)
				cnt[num[idx][i][j]-'A'] += high*factor;

		idx++, factor*=10;
	}
}

int main()
{
	FILE* in = fopen("preface.in", "r");
	FILE* out = fopen("preface.out", "w");

	fscanf(in, "%d", &N);
	deal(N);

	if(cnt['I'-'A'])fprintf(out, "I %d\n", cnt['I'-'A']);
	if(cnt['V'-'A'])fprintf(out, "V %d\n", cnt['V'-'A']);
	if(cnt['X'-'A'])fprintf(out, "X %d\n", cnt['X'-'A']);
	if(cnt['L'-'A'])fprintf(out, "L %d\n", cnt['L'-'A']);
	if(cnt['C'-'A'])fprintf(out, "C %d\n", cnt['C'-'A']);
	if(cnt['D'-'A'])fprintf(out, "D %d\n", cnt['D'-'A']);
	if(cnt['M'-'A'])fprintf(out, "M %d\n", cnt['M'-'A']);

	return 0;
}