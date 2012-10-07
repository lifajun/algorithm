#include <iostream>
#include <cmath>
using namespace std;

#define min(a, b) ( a<b ? a : b)
#define ROW 100
#define COL 100

int arr[ROW+2][COL+2];

bool isLineConnection(int x1, int y1, int x2, int y2)
{
	if( !(x1 == x2 || y1 == y2))	return false;

	if(x1 == x2)
	{
		int temp = abs(y1 - y2), s = min(y1, y2);
		for(int i=1; i<temp; i++)
			if(arr[x1][s+i] != 0)
				return false;
	}
	if(y1 == y2)
	{
		int temp = abs(x1 - x2), s = min(x1, x2);
		for(int i=1; i<temp; i++)
			if(arr[s+i][y1] != 0)
				return false;
	}

	return true;
}

bool isOneCornerConnection(int x1, int y1, int x2, int y2)
{
	if(arr[x1][y2] == 0 && isLineConnection(x1, y1, x1, y2) && isLineConnection(x1, y2, x2, y2))
		return true;
	
	if(arr[x2][y1] == 0 && isLineConnection(x1, y1, x2, y1) && isLineConnection(x2, y1, x2, y2))
		return true;

	return false;
}

bool isTwoCornerConnection(int x1, int y1, int x2, int y2)
{
	for(int i=y1-1; i>=0; i--)
	{
		if(arr[x1][i] != 0)	break;
		if(isOneCornerConnection(x1, i, x2, y2))
			return true;
	}

	for(int i=y1+1; i<=COL+1; i++)
	{
		if(arr[x1][i] != 0)	break;
		if(isOneCornerConnection(x1, i, x2, y2))
			return true;
	}

	for(int i=x1-1; i>=0; i--)
	{
		if(arr[i][y1] != 0)	break;
		if(isOneCornerConnection(i, y1, x2, y2))
			return true;
	}

	for(int i=x1+1; i<=ROW+1; i++)
	{
		if(arr[i][y1] != 0)	break;
		if(isOneCornerConnection(i, y1, x2, y2))
			return true;
	}
	
	return false;
}

int main()
{
	return 0;
}