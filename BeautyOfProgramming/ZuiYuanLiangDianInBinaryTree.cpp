#include <iostream>
using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int maxLeft;
	int maxRight;
	int height;//³õÊ¼»¯Îª-2;
	char value;
};

int maxDist = 0;

void findMax(Node *root)
{
	if(root->height != -1)	return;
	if(root == NULL)	return;
	if(root -> left == NULL)	root->maxLeft = 0;
	if(root -> right == NULL)	root->maxRight = 0;
	if(root -> left != NULL)
	{
		findMax(root -> left);
		if(root ->left->maxLeft > root->left->maxRight)
			root->maxLeft = root->left->maxLeft + 1;
		else
			root->maxLeft = root->left->maxRight + 1;
	}
	if(root ->right != NULL)
	{
		findMax(root->right);
		if(root->right->maxLeft > root->right->maxRight)
			root->maxRight = root->right->maxLeft+1;
		else
			root->maxRight = root->right->maxRight+1;
	}
	if(root->maxLeft + root->maxRight > maxDist)
		maxDist = root->maxLeft + root->maxRight;
	root->height = max(root->maxLeft, root->maxRight);
}

int main()
{
	return 0;
}