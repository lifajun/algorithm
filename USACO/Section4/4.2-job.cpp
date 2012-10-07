/*
ID: lifajun2
PROG: job
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

#define max(a, b)(a > b ? a : b)

int jobA[1005], jobB[1005], N;
int machA[35], machB[35], M1, M2;

struct Mach
{
	int st, delay;
	Mach(int s, int d)
	{
		st = s, delay = d;
	}
	bool operator<(Mach m) const
	{
		return st+delay > m.st + m.delay;
	}
};

int main()
{
	ifstream in("job.in");
	ofstream out("job.out");
	
	in>>N>>M1>>M2;
	for(int i=1; i<= M1; i++)
		in>>machA[i];
	for(int i=1; i<= M2; i++)
		in>>machB[i];

	priority_queue<Mach> pq;
	for(int i=1; i<=M1; i++)
		pq.push(Mach(0, machA[i]));
	for(int i=1; i<=N; i++)
	{
		Mach t = pq.top(); pq.pop();
		jobA[i] = t.st + t.delay;
		pq.push(Mach(t.st+t.delay, t.delay));
	}
	while(!pq.empty()) pq.pop();
	for(int i=1; i<=M2; i++)
		pq.push(Mach(0, machB[i]));
	for(int i=1; i<=N; i++)
	{
		Mach t = pq.top(); pq.pop();
		jobB[i] = t.st + t.delay;
		pq.push(Mach(t.st + t.delay, t.delay));
	}

	int ans = jobA[1] + jobB[N];
	for(int i=2; i<=N; i++)
		ans = max(ans, jobA[i] + jobB[N+1-i]);

	out<<jobA[N]<<" "<<ans<<endl;
	return 0;
}