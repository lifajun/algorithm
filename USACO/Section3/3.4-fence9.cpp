/*
ID: lifajun2
PROG: fence9
LANG: C++
*/
#include <fstream>
using namespace std;

int gcd(int m, int n)
{
	return n == 0 ? m : gcd(n, m%n);
}

int main()
{
	int n, m, p;
	ifstream infile("fence9.in");
	ofstream outfile("fence9.out");

	infile>>n>>m>>p;
	int S = (p*m)>>1;
	int b = gcd(n, m);//�ӣ�0,0������m, n��������ĸ���Ϊ���Լ����1
	if(n > p) b += gcd(n-p, m);
	else	b += gcd(p-n, m);
	b += p;

	outfile<<S+1-(b>>1)<<endl;//Ƥ�˹�ʽ
	return 0;
}