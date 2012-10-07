/*
ID: lifajun2
PROG: concom
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int own[105][105];
bool con[105][105];

int main()
{
	int n, a, b, c;
	FILE* in = fopen("concom.in", "r");
	FILE* out = fopen("concom.out", "w");

	fscanf(in, "%d", &n);
	memset(con, false, sizeof(con));
	for(int i=1; i<=n; i++)
	{
		fscanf(in, "%d%d%d", &a, &b, &c);
		own[a][b] = c;
		if(own[a][b] > 50)	con[a][b] = true;
	}

	for(int i=1; i<=100; i++)
	{
		con[i][i] = true;
		vector<int> v;
		for(int j=1; j<=100; j++)
			if(con[i][j])	v.push_back(j);
		bool flag = true;
		while(flag)
		{
			flag = false;
			for(int k=1; k<=100; k++)
			{
				if(!con[i][k])
				{
					int sum = 0;
					for(unsigned j=0; j<v.size(); j++)
						sum += own[v[j]][k];
					if(sum > 50)	{flag = true;con[i][k] = true;v.push_back(k);}
				}
			}
		}
	}

	for(int i=1; i<=100; i++)
		for(int j=1; j<=100; j++)
			if(i != j && con[i][j])
				fprintf(out, "%d %d\n", i, j);
	return 0;
}