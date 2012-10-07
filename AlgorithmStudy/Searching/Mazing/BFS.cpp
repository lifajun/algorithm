#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int map[10][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[10][10];

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

int main()
{
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			cin>>map[i][j];

	queue<Node> q;
	memset(visited, false, sizeof(visited));
	Node start(1, 1, "(1, 1)");
	q.push(start);
	visited[1][1] = true;

	while(!q.empty())
	{
		Node temp = q.front();
		q.pop();
		if(temp.x == 8 && temp.y == 8)
		{
			cout<<temp.step<<endl<<temp.path<<endl;
			return 0;
		}
		for(int i=0; i<4; i++)
		{
			int xx = temp.x + dx[i];
			int yy = temp.y + dy[i];
			if(is_valid(xx, yy) && !visited[xx][yy])
			{
				char x[2], y[2];
				sprintf(x, "%d", xx);
				sprintf(y, "%d", yy);
				Node temp2(xx, yy, temp.path + "->(" + x + ", "+ y + ")",  temp.step+1);
				visited[xx][yy] = true;
				q.push(temp2);
			}
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}