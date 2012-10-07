#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct Node
{
	Node *left, *right;
	char value;
};

void rebuild(char *pPreOrder, char *pInOrder, int nTreelen, Node *&root)
{	
	root = new Node;
	root->left = NULL;
	root->right = NULL;
	root->value = *pPreOrder;

	if(nTreelen == 1)	return;
	char *left = pInOrder;
	while(*left != *pPreOrder)	left++;

	int leftLen = (int)(left-pInOrder);
	int rightLen = (int)(nTreelen - leftLen - 1);

	if(leftLen > 0)
		rebuild(pPreOrder + 1, pInOrder, leftLen, root->left);
	if(rightLen > 0)
		rebuild(pPreOrder + leftLen + 1, pInOrder + leftLen + 1, rightLen,  root->right);
}

void inOrder(Node *root)
{
	if(root->left) inOrder(root->left);
	cout<<root->value;
	if(root->right) inOrder(root->right);
}

void preOrder(Node* root)
{
	cout<<root->value;
	if(root->left) preOrder(root->left);
	if(root->right) preOrder(root->right);
}

void freeNode(Node *root)
{
	if(root->left)	freeNode(root->left);
	if(root->right)	freeNode(root->right);
	delete root;
}

int PrintNodeAtLevel(Node* root, int level)
{
	if(!root)	return 0;
	if(level == 0){cout<<root->value<<" "; return 1;}
	return PrintNodeAtLevel(root->left, level-1) + PrintNodeAtLevel(root->right, level-1);
}

void PrintByLevel_queue1(Node* root)
{
	queue<Node*> q;
	queue<int> level;
	q.push(root);level.push(0);
	int currentLevel = 0;

	while(!q.empty())
	{
		Node *temp = q.front();q.pop();
		int l = level.front(); level.pop();
		if(l > currentLevel){cout<<endl;currentLevel = l;}
		cout<<temp->value<<" ";
		if(temp->left)	{q.push(temp->left); level.push(l+1);}
		if(temp->right){q.push(temp->right); level.push(l+1);}
	}
}

void PrintByLevel_queue2(Node *root)
{
	queue<Node*> q;
	q.push(root);q.push(0);
	
	while(!q.empty())
	{
		Node *temp = q.front();q.pop();
		if(temp)
		{
			cout<<temp->value<<" ";
			if(temp->left)		q.push(temp->left);
			if(temp->right)	q.push(temp->right);
		}
		else	if(!q.empty())
		{
			q.push(0);
			cout<<endl;
		}
	}
}

void PrintByLevel_vector(Node* root)
{
	vector<Node*> v;
	v.push_back(root);
	int cur = 0, last;

	while(cur < v.size())
	{
		last = v.size();
		while(cur < last)
		{
			cout<<v[cur]->value<<" ";
			if(v[cur]->left)	v.push_back(v[cur]->left);
			if(v[cur]->right) v.push_back(v[cur]->right);
			cur++;
		}
		cout<<endl;
	}
}

void PrintByLevel_D2T(Node *root, int l2r)
{
	vector<Node*> v;
	v.push_back(root);
	int cur = 0, last;

	while(cur < v.size())
	{
		last = v.size();
		v.push_back(NULL);
		while(cur < last)
		{
			if(l2r)
			{
				if(v[cur]->right)	v.push_back(v[cur]->right);
				if(v[cur]->left)	v.push_back(v[cur]->left);
			}
			else
			{
				if(v[cur]->left)	v.push_back(v[cur]->left);
				if(v[cur]->right)	v.push_back(v[cur]->right);
			}
			cur++;
		}
		cur++;
	}
	for(int i=v.size()-2; i>=0; i--)
	{
		if(!v[i])	cout<<endl;
		else	cout<<v[i]->value<<" ";
	}
	cout<<endl;
}

int main()
{
	char pre[] = "abdcef", in[] = "dbaecf";
	Node *root = NULL;
	rebuild(pre, in, strlen(pre), root);
	PrintByLevel_queue1(root);
	cout<<endl;
	PrintByLevel_queue2(root);
	cout<<endl;
	PrintByLevel_vector(root);
	PrintByLevel_D2T(root, 1);
	PrintByLevel_D2T(root, 0);
	freeNode(root);
	return 0;
}