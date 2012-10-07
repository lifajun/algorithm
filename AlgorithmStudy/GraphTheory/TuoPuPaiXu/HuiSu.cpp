#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int in_degree[25], n;
bool visited[25], G[25][25];
int result[25];
map<int, char> m1;
map<char, int> m2;

void dfs(int s)
{
	if(s == n+1)
	{
		for(int i=1; i<=n; i++)
			cout<<m1[result[i]];
		cout<<endl;
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(!visited[i] && in_degree[i] == 0)
		{
			visited[i] = true;
			result[s] = i;
			for(int j=1; j<=n; j++)
				if(G[i][j])	in_degree[j]--;
			dfs(s+1);
			visited[i] = false;
			for(int j=1; j<=n; j++)
				if(G[i][j])	in_degree[j]++;
		}
	}
}

int main()
{
	int times = 0;
	char input1[200], in2[200], input2[250];
	while(gets(input1))
	{
		gets(input2);
		if(times)	cout<<endl;
		times++;

		n = 0;
		m1.clear();
		m2.clear();
		memset(in_degree, 0, sizeof(in_degree));
		memset(visited, false, sizeof(visited));
		memset(G, false, sizeof(G));

		int count = 0;
		for(unsigned i=0; i<strlen(input1); i++)
		{
			if(input1[i] != ' ')
				in2[count++] = input1[i];
		}
		sort(in2, in2+count);
		for(int i=0; i<count; i++)
		{
			m1[++n] = in2[i];
			m2[in2[i]] = n;
		}

		bool cnt = true;
		char pre;
		for(unsigned i=0; i<strlen(input2); i++)
		{
			if(input2[i] != ' ')
			{
				if(cnt)
					cnt = false, pre = input2[i];
				else
					G[m2[pre]][m2[input2[i]]] = true, cnt = true;
			}
		}

		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
				if(G[i][j])
					in_degree[j]++;
		}
		dfs(1);
	}
	return 0;
}