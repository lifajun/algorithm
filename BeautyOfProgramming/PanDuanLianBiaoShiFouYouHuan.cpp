#include <iostream>
using namespace std;

struct Node
{
	Node *next;
	char val;
};

bool isCycle(Node *head)
{
	if(!head)	return false;
	Node *slow = head, *fast = head;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)	return true;
	}
	return false;
}

Node* cycle(Node *head)
{
	if(!head)	return NULL;
	Node *slow = head, *fast = head;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)	break;
	}

	if(!fast || !(fast->next))	return NULL;

	slow = head;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

int main()
{
	return 0;
}