#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int data;
	node *left;
	node *right;
};

struct node *newnode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

void inorderSuc(struct node *root, int data)
{
	static int prev = 0;
	if(root == NULL)
	{
		return ;
	}
	
	inorderSuc(root->right,data);
	if(root->data == data)
	{
		printf("Inorder successor is %d",prev);
		return;
	}
	prev = root->data;
	inorderSuc(root->left,data);
	
}

int main()
{
	int data;
	struct node *root = newnode(4);
	root->left = newnode(2);
	root->right = newnode(6);
	root->left->left = newnode(1);
	root->left->right = newnode(3);
	root->right->left = newnode(5);
	root->right->right = newnode(7);
	
	inorderSuc(root,5);
	printf("Inorder successor is %d\n",data);
}
