#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool vis[1000];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(vis, false, sizeof(vis));
		queue<__int64> q;
		q.push(1);
		vis[1] = true;

		while(!q.empty())
		{
			__int64 temp = q.front();
			q.pop();
			if(temp % n == 0)
			{
				cout<<temp<<endl;
				break;
			}
			if(!vis[temp*10 % n])
			{
				q.push(temp*10);
				vis[temp*10%n] = true;
			}
			if(!vis[(temp*10+1)% n])
			{
				q.push(temp*10+1);
				vis[(temp*10+1)%n] = true;
			}
		}	
	}
	return 0;
}