#include <iostream>
using namespace std;

#define MAX 100
#define max(a, b) (a > b ? a : b)

class Stack
{
private:
	int number[100];
	int stackTop;
	int nextMax[100];
	int maxIndex;
public:
	Stack(){stackTop = -1, maxIndex = -1;}

	bool empty() const{return stackTop == -1;}

	int getMax()
	{
		if(maxIndex == -1)	return -1;
		return number[maxIndex];
	}

	void push(int x)
	{
		number[++stackTop] = x;
		if(x > getMax())
		{
			nextMax[stackTop] = maxIndex;
			maxIndex = stackTop;
		}
		else	nextMax[stackTop] = -1;
	}

	int pop()
	{
		if(stackTop == maxIndex)
			maxIndex = nextMax[stackTop];
		return number[stackTop--];
	}
};

class Queue
{
private:
	Stack A;
	Stack B;
public:
	int MaxElement()
	{
		return max(A.getMax(), B.getMax());
	}

	void Enqueue(int v)
	{
		B.push(v);
	}

	int Dequeue()
	{
		if(A.empty())
		{
			while(!B.empty())
				A.push(B.pop());
		}
		return A.pop();
	}

	bool empty()
	{
		return A.empty() && B.empty();
	}
};

int main()
{
	Queue q;
	q.Enqueue(3);
	cout<<q.MaxElement()<<endl;
	q.Enqueue(5);
	cout<<q.MaxElement()<<endl;
	q.Enqueue(4);
	cout<<q.MaxElement()<<endl;
	q.Enqueue(7);
	cout<<q.MaxElement()<<endl;
	q.Enqueue(2);
	cout<<q.MaxElement()<<endl;

	while(!q.empty())
	{	
		q.Dequeue();
		cout<<q.MaxElement()<<endl;
	}
	return 0;
}