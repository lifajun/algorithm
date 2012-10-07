/*
ID: lifajun2
PROG: contact
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int fre[13][5000], n_cnt;/*换位思考，匹配不行就用统计*/
char record[200005], str[85];
struct Node
{
	int fre, len, num;
}nod[10000];

int cmp(Node n1, Node n2)
{
	if(n1.fre == n2.fre)
	{
		if(n1.len == n2.len)
			return n1.num < n2.num;
		else
			return n1.len < n2.len;
	}
	else
		return n1.fre > n2.fre;
}	

int getValue(char* str)
{
	int result = 0;
	for(unsigned i=0; i<strlen(str); i++)
		result = (result<<1) + str[i]-'0';
	return result;
}

void getStr(int value, char res[], int len)
{
	int cnt = 0;
	while(value)
	{
		res[cnt++] = (char)((value&1) + '0');
		value >>= 1;
	}
	for(int i=cnt; i<len; i++)
		res[i] = '0';
	res[len] = '\0';
	int l = 0, r = len-1;
	while(l < r)
		swap(res[l++], res[r--]);
}

int main()
{
	int A, B, N, len = 0;
	FILE* in = fopen("contact.in", "r");
	FILE* out = fopen("contact.out", "w");

	fscanf(in, "%d %d %d", &A, &B, &N);
	fgetc(in);
	while(fgets(str, 81, in))
	{
		int l = strlen(str);
		fgetc(in);
		strcat(record, str);
		len += l;
	}

	memset(fre, 0, sizeof(fre));
	for(int i=0; i<len; i++)
	{
		for(int j=A; j<=B && i+j <= len; j++)
		{
			strncpy(str, record+i, j);
			str[j] = '\0';
			fre[j][getValue(str)]++;
		}
	}

	n_cnt = 0;
	for(int l=A; l<=B; l++)
		for(int n=0; n<(1<<l); n++)
			if(fre[l][n])
				nod[n_cnt].fre = fre[l][n], nod[n_cnt].len = l, nod[n_cnt++].num = n;
	sort(nod, nod+n_cnt, cmp);

	int mod;
	if(n_cnt > 0)
	{
		mod = 1, N--;
		fprintf(out, "%d\n", nod[0].fre);
	}
	for(int i=0; i<n_cnt; i++)
	{
		if(mod != 1)	fprintf(out, " ");
		getStr(nod[i].num, str, nod[i].len);
		fprintf(out, "%s", str);
		
		if(nod[i+1].fre != nod[i].fre)
		{
			if(!(N--))	{fprintf(out, "\n");break;}
			mod =1; fprintf(out, "\n");
			if(i+1 < n_cnt)
				fprintf(out, "%d\n", nod[i+1].fre);
		}
		else if(mod++ == 6)	{mod = 1; fprintf(out, "\n");}
	}
	return 0;
}