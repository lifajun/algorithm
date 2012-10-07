#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int N, temp, ans = 0;
	cin>>N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=N; i++)
	{
		cin>>temp;
		pq.push(temp);
	}
	for(int i=1; i<N; i++)
	{
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();
		ans += (num1+num2);
		pq.push(num1+num2);
	}

	cout<<ans<<endl;
	return 0;
}