#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;
struct node{
	int data;
	struct node* left;
	struct node * right;
};
bool isCompleteTree(struct node * root)
{
	queue<struct node*> q;
	q.push(root);
	while(q.back()!=NULL)
	{
		struct node * temp=q.front();
		q.pop();
		if(temp->left==NULL)
		{
			if(temp->right!=NULL)
			return 0;
			else
			q.push(temp->left);
		}
		else
		{
			q.push(temp->left);
			q.push(temp->right);
		}
	}
	while(q.size()!=1)
	{
		struct node * item=q.front();
		q.pop();
		if(item->left!=NULL)
		return 0;
		if(item->right!=NULL)
		return 0;
	}
	return 1;	
}
struct node * newnode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->right=NULL;
	node->left=NULL;
	return node;

}
int main()
{
	struct node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	//root->left->left=newnode(4);
	root->left->right=newnode(5);
	//root->right->right=newnode(6);
	if(isCompleteTree(root))
	cout<<"IT is a complete tree.";
	else
	cout<<"Incomplete Tree";
}
