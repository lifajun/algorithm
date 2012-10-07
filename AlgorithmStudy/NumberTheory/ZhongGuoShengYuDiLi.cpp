#include <iostream>
using namespace std;

//�й���������
//x = ((y1 * M1 * b1) + (y2 * M2 * b2) + ���� + (yk * Mk * bk)) % M;
//M = m[1] * m[2] * ����*m[k];
//Mi = M/m[i]
//(yi * Mi) % bi == 1����Ϊ�����ܱ�֤yi * Mi * bi��mi��bi, ��������0, 
//��ô����������x������Ҫ�Ľ����

void ext_gcd(int a, int b, int& x, int& y)
{
	if(b == 0)
		x = 1, y = 0;
	else
	{
		int _x, _y;
		ext_gcd(b, a%b, _x, _y);
		x = _y, y = _x - (a/b)*_y;
	}
}

int Mod_China(int m[], int b[], int k)
{
	int x, y, M = 1, Mi, a = 0;
	for(int i=0; i<k; i++)
		M *= m[i];
	for(int i=0; i<k; i++)
	{
		Mi = M/m[i];
		ext_gcd(Mi, m[i], x, y);
		a = (a + x*Mi*b[i]) % M;
	}
	return (a + M) % M;
}

int main()
{
	int k, m[10], b[10];
	cin>>k;
	for(int i=0; i<k; i++)
		cin>>m[i]>>b[i];
	cout<<Mod_China(m, b, k)<<endl;
	return 0;
}