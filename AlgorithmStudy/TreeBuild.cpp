#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node
{
	string data;
	Node *left, *right;
	Node(){left=NULL, right=NULL;}
	Node(string s){data = s, left = NULL, right = NULL;}
};
bool isOperator(char c)
{
	return c=='+' || c == '-' || c == '*' || c =='/';
}

bool has_no_operator(string s)
{
	for(unsigned int i=0; i<s.length(); i++)
		if(!isdigit(s[i]))
			return false;
	return true;
}

Node *build_tree(string s)
{
	int c1 = -1, c2 = -1, p=0;
	if(has_no_operator(s))
	{
		Node *new_node = new Node(s);
		return new_node;
	}

	for(unsigned int i=0; i<s.length(); i++)
	{
		switch(s[i])
		{
		case '(': p++; break;
		case ')': p--; break;
		case '+': case '-': if(!p) c1=i; break;
		case '*': case '/': if(!p) c2=i; break;
		}
	}

	if(c1 < 0)	c1 = c2;
	if(c1 < 0)	return build_tree(s.substr(1, s.length() -2));

	Node *new_node = new Node(string(1, s[c1]));
	new_node->left = build_tree(s.substr(0, c1));
	new_node->right = build_tree(s.substr(c1+1, s.length()-c1-1));
	return new_node;
}

int compute(Node* n)
{
	if(has_no_operator(n->data))
		return atoi(n->data.c_str());

	int result;
	switch(n->data[0])
	{
	case '+':
		result = compute(n->left) + compute(n->right);
		break;
	case '-':
		result = compute(n->left) - compute(n->right);
		break;
	case '*':
		result = compute(n->left) * compute(n->right);
		break;
	case '/':
		result = compute(n->left) / compute(n->right);
		break;
	}
	return result;
}

string convert_to_post(Node *n)
{
	if(n->left == NULL && n->right == NULL)
		return n->data;

	return convert_to_post(n->left) + convert_to_post(n->right) + n->data;
}

void free_node(Node *n)
{
	if(n->left) free_node(n->left);
	if(n->right)free_node(n->right);
	delete n;
}

int main()
{
	string s1 = "1+2+3";
	string s2 = "((3+4)*5+6)*7";
	string s3 = "1+2*3";
	string s4 = "2*5+10";
	string s5 = "(4+5)*(2+2)";
	string s6 = "378+456-500*12/2";

	Node *root1 = build_tree(s1);
	cout<<compute(root1)<<endl;
	cout<<convert_to_post(root1)<<endl;
	free_node(root1);

	Node *root2 = build_tree(s2);
	cout<<compute(root2)<<endl;
	cout<<convert_to_post(root2)<<endl;
	free_node(root2);

	Node *root3 = build_tree(s3);
	cout<<compute(root3)<<endl;
	cout<<convert_to_post(root3)<<endl;
	free_node(root3);

	Node *root4 = build_tree(s4);
	cout<<compute(root4)<<endl;
	cout<<convert_to_post(root4)<<endl;
	free_node(root4);

	Node *root5 = build_tree(s5);
	cout<<compute(root5)<<endl;
	cout<<convert_to_post(root5)<<endl;
	free_node(root5);

	Node *root6 = build_tree(s6);
	cout<<compute(root6)<<endl;
	cout<<convert_to_post(root6)<<endl;
	free_node(root6);
	
	return 0;
}