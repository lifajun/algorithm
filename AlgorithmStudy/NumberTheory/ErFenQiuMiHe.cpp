#include <iostream>
#include <cstring>
using namespace std;

#define MOD 9901
int divisor[100], count[100];

__int64 pow(int p, int n)//快速幂，二分
{
	__int64 res = 1, fac = p;
	while(n)
	{
		if(n & 1)	res = res * fac % MOD;
		n >>= 1;
		fac = fac* fac % MOD;
	}
	return res;
}

__int64 sum(int p, int n)//二分求1+p+p^2+p^3+……+p^n
{
	if(n == 0)	return 1;
	if(n & 1)	return ((1 + pow(p, (n+1)>>1))  * sum(p, (n-1)>>1)) % MOD;
	else	return ((1+pow(p, (n>>1)+1)) * sum(p, (n-1)>>1) % MOD + pow(p, n>>1)) % MOD;
}

int main()
{
	int A, B, cnt = 0;
	__int64 res = 1;
	memset(count, 0, sizeof(count));
	cin>>A>>B;

	for(int i=2; i*i <= A; i++)
	{
		if(A % i == 0)
		{
			divisor[cnt] = i;
			while(A % i == 0){count[cnt]++;A /= i;}
			cnt++;
		}
	}
	if(A > 1) divisor[cnt] = A, count[cnt++] = 1;
	for(int i=0; i<cnt; i++)
		res = res * (sum(divisor[i], count[i] * B) % MOD)%MOD;

	cout<<res<<endl;
	return 0;
}