/*
ID: lifajun2
PROG: namenum
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

char str[15], res[15];
char map[100];

int main()
{
	map['A'] = '2'; map['B'] = '2'; map['C'] = '2'; 
	map['D'] = '3'; map['E'] = '3'; map['F'] = '3'; 
	map['G'] = '4'; map['H'] = '4'; map['I'] = '4'; 
	map['J'] = '5'; map['K'] = '5'; map['L'] = '5'; 
	map['M'] = '6'; map['N'] = '6'; map['O'] = '6'; 
	map['P'] = '7'; map['R'] = '7'; map['S'] = '7'; 
	map['T'] = '8'; map['U'] = '8'; map['V'] = '8'; 
	map['W'] = '9'; map['X'] = '9'; map['Y'] = '9'; 
	FILE* in1 = fopen("dict.txt", "r");
	FILE* in2 = fopen("namenum.in", "r");
	FILE* out = fopen("namenum.out", "w");
	fscanf(in2, "%s", res);
	int len1 = strlen(res), sol = 0;
	while(fscanf(in1, "%s", str) == 1)
	{
		int len2 = strlen(str);
		if(len1 == len2)
		{
			bool flag = true;
			for(int i=0; i<len1; i++)
				if(res[i] != map[str[i]]) {flag = false;break;}
			if(flag) {fprintf(out, "%s\n", str);sol++;}
		}
	}
	if(sol == 0)
		fprintf(out, "NONE\n");
	return 0;
}