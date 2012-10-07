/*
ID: lifajun2
PROG: namenum
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

char dict[5000][15], str[15], res[15];
char map[10][3] = {{}, {}, {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'},
{'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};
int dict_cnt = 0, len;
FILE* in, *out;
bool flag;

bool b_search(char *str)
{
	int l = 0, r = dict_cnt, mid, res;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		res = strcmp(str, dict[mid]);
		if(res == 0)
			return true;
		else if(res < 0)
			r = mid - 1;
		else	l  = mid + 1;
	}
	return false;
}

void dfs(int s)
{
	if(s == len)
	{
		res[len] = '\0';
		if(b_search(res))	
		{
			flag = true;fprintf(out, "%s\n", res);
		}
	}
	else
	{
		for(int i=0; i<3; i++)
		{
			res[s] = map[str[s]-'0'][i];
			dfs(s+1);
		}
	}
}

int main()
{
	flag = false;
	in = fopen("dict.txt", "r");
	while(fscanf(in, "%s", str) == 1)
		strcpy(dict[dict_cnt++], str);
	in = fopen("namenum.in", "r");
	fscanf(in, "%s", str);
	len = strlen(str);
	out = fopen("namenum.out", "w");
	dfs(0);
	if(!flag)	fprintf(out, "NONE\n");
	return 0;
}