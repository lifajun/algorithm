#include <iostream>
#include <memory.h>
using namespace std;

int main()
{ 
	int count[101];
	memset(count, 0, sizeof(count));
	count[0] = 1;
	int w[7] = {0, 1, 5, 10, 20, 50, 100};

	for(int i=1; i<=6; i++)
	{
		for(int j=w[i]; j<=100; j++)
			count[j] += count[j-w[i]];
	}

	cout<<count[100]<<endl;
	return 0;
}