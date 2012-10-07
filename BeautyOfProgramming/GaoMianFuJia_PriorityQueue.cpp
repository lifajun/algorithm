#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct node
{
	int b, e;
}a[100];

int cmp(node n1, node n2)
{
	return n1.b < n2.b;
}

int main()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	int n, m = 0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[m].b>>a[m].e;
		m++;
	}
	sort(a, a+m, cmp);

	int cnt = 1;
	pq.push(a[0].e);
	for(int i=1; i<m; i++)
	{
		int top = pq.top();
		if(top <= a[i].b)	pq.pop();
		else	cnt++;
		pq.push(a[i].e);
	}
	cout<<cnt<<endl;
	return 0;
}