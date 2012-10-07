#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int map[10][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[10][10], has_finished;

struct Node
{
	int x, y, step;
	string path;
	Node(){}
	Node(int xx, int yy, string p, int s=0)
	{x = xx, y = yy, path = p, step = s;}
};

bool is_valid(int x, int y)
{
	return x >= 1 && x <= 8 && y >= 1 && y <= 8 && map[x][y] == 0;
}

void dfs(Node n)
{
	if(n.x == 8 && n.y == 8)
	{
		cout<<n.step<<endl<<n.path<<endl;
		has_finished = true;
		return;
	}
	visited[n.x][n.y] = true;
	for(int i=0; i<4; i++)
	{
		int xx = n.x + dx[i], yy = n.y + dy[i];
		if(!has_finished && is_valid(xx, yy) && !visited[xx][yy])
		{
			char x[2], y[2];
			sprintf(x, "%d", xx);
			sprintf(y, "%d", yy);
			dfs(Node(xx, yy, n.path + "->(" + x + ", " + y + ")", n.step+1));
		}
	}	
}

int main()
{
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			cin>>map[i][j];

	memset(visited, false, sizeof(visited));
	Node start(1, 1, "(1, 1)");
	has_finished = false;
	dfs(start);
	return 0;
}