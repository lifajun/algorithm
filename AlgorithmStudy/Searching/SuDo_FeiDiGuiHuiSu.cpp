#include <iostream>
#include <cstring>
using namespace std;

int sudo[10][10], n;

bool check(int i, int j)
{
	int temp = sudo[i][j];
	for(int p = 0; p < 9; p++)
	{
		if(p != j && sudo[i][p] == temp)
			return false;
	}

	for(int q = 0; q < 9; q++)
	{
		if(q != i && sudo[q][j] == temp)
			return false;
	}

	int _p = i/3, _q = j/3;
	for(int p = _p*3; p<_p*3 + 3; p++)
	{
		for(int q = _q*3; q<_q*3 + 3; q++)
			if(p != i && q != j && sudo[p][q] == temp)
				return false;
	}
	return true;
}

void output(int n)
{
	cout<<n<<":"<<endl;
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
			cout<<sudo[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	memset(sudo, 0, sizeof(sudo));
	int k=0, i, j, cnt=0;

	while(k >= 0)
	{
		i = k/9;
		j = k%9;
		sudo[i][j]++;
		while(sudo[i][j] <= 9 && !check(i, j))	sudo[i][j]++;
		if(sudo[i][j] <= 9)
		{
			if(k == 80)		{output(cnt++);if(cnt == 3)	return 0;}
			else	{k++, sudo[k/9][k%9] = 0;}
		}
		else	k--;
	}
	cout<<cnt<<endl;
	return 0;
}