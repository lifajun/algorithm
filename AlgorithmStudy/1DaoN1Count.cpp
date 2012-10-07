#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n) 
	{
		int high = 0;
		int current = 0;
		int low = 0;

		int count = 0;
		int factor =  1;

		while(n/factor)
		{
			high = n/(10*factor);
			current = (n/factor)%10;
			low = n-(n/factor)*factor;

			switch(current)
			{
			case 0:
				count += (high*factor);
				break;
			case 1:
				count += (high*factor + low + 1);
				break;
			default:
				count += ((high+1)*factor);
				break;
			}
			factor *= 10;
		}

		cout<<count<<endl;
	}
	return 0;
}