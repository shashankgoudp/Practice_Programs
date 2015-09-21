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

bool isBST(struct node *root, int min, int max)
{
	if(root == NULL)
	{
		return true;
	}
	
	if(root->data < min || root->data > max)
	{
		return false;
	}
	
	return (isBST(root->left,min,root->data) && isBST(root->right,root->data-1,max));
}

int main()
{
	struct node *root = newnode(4);
	root->left = newnode(2);
	root->right = newnode(6);
	root->left->left = newnode(1);
	root->left->right = newnode(3);
	root->right->left = newnode(5);
	root->right->right = newnode(7);
	
	if(isBST(root,INT_MIN,INT_MAX))
	{
		printf("It is BST\n");
	}
	else
	{
		printf("It is not BST");
	}
}
