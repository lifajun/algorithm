/*
ID: lifajun2
PROG: holstein
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int min;
	vector<int> path;
};

int V, req[1005], get[1005], G, vit[16][1005];
FILE* in = fopen("holstein.in", "r");
FILE *out = fopen("holstein.out", "w");

bool hasFound(Node n)
{
	memset(get, 0, sizeof(get));
	for(unsigned i=0; i<n.path.size(); i++)
		for(int j=1; j<=V; j++)
			get[j] += vit[n.path[i]][j];
	for(int i=1; i<=V; i++)
		if(get[i] < req[i])	return false;
	return true;
}

void bfs()
{
	queue<Node> q;
	Node start;
	start.min = 0;
	q.push(start);

	while(!q.empty())
	{
		Node temp = q.front(); q.pop();
		if(hasFound(temp))
		{
			fprintf(out, "%d", temp.path.size());
			for(unsigned i=0; i<temp.path.size(); i++)
				fprintf(out, " %d", temp.path[i]);
			fprintf(out, "\n");
			return;
		}
		for(int i=temp.min+1; i<=G; i++)
		{
			Node t = temp;
			t.path.push_back(i);
			t.min = i;
			q.push(t);
		}
	}
}

int main()
{
	fscanf(in, "%d", &V);
	for(int i=1; i<=V; i++)
		fscanf(in, "%d", &req[i]);
	fscanf(in, "%d", &G);
	for(int i=1; i<=G; i++)
		for(int j=1; j<=V; j++)
			fscanf(in, "%d", &vit[i][j]);

	bfs();

	return 0;
}