/*
ID: lifajun2
PROG: clocks
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

char move[10][7] = {"FAJUN", "ABDE", "ABC", "BCEF", 
	"ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
bool vis[300000];

struct Node
{
	int step[10];
	int status[10];
	vector<int> path;
}start;

bool isfinal(Node n)
{
	int sum = 0;
	for(int i=1; i<10; i++)
		sum += n.status[i];
	return sum == 0;
}

int hash(int status[])
{
	int res = 0;
	for(int i=1; i<10; i++)
		res = res*4 + status[i];
	return res;
}

void bfs()
{
	FILE* out = fopen("clocks.out", "w");
	queue<Node> q;
	q.push(start);
	vis[hash(start.status)] = true;

	while(!q.empty())
	{
		Node temp = q.front();q.pop();
		if(isfinal(temp) && temp.path.size())
		{
			fprintf(out, "%d", temp.path[0]);
			for(int i=1; i<temp.path.size(); i++)
				fprintf(out, " %d", temp.path[i]);
			fprintf(out, "\n");
			return;
		}
		for(int i=1; i<=9; i++)
		{
			if(temp.step[i] >= 3)	continue;
			Node t = temp;
			int val;
			for(int j=0; j<strlen(move[i]); j++)
				t.status[move[i][j]-'A'+1] = (t.status[move[i][j]-'A'+1] + 1)%4;
			val = hash(t.status);
			if(!vis[val])
			{
				vis[val] = true;
				t.step[i]++;
				t.path.push_back(i);
				q.push(t);
			}
		}
	}
}

int main()
{
	FILE* in = fopen("clocks.in", "r");
	int temp;

	memset(start.step, 0, sizeof(start.step));
	memset(vis, false, sizeof(vis));
	for(int i=1; i<10; i++)
	{
		fscanf(in, "%d", &temp);
		start.status[i] = (temp/3)%4;
	}
	
	bfs();

	return 0;
}