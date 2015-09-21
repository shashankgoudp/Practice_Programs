#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	node *left;
	node *right;	
};


int height(struct node *root)
{
	struct node *node = root;
	int leftheight;
	int rightheight;
	
	if(node == NULL)
	{
		return NULL;
	}
	
	leftheight = height(node->left);
	rightheight = height(node->right);
	
	if(leftheight > rightheight)
	return leftheight+1;
	
	else
	return rightheight+1;
}
struct node* newnode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	
}


bool isBalanced(struct node *root)
{
	struct node *node = root;
	if(node == NULL)
	return true;
	
	int heightdiff = height(node->left)-height(node->right);
	if(heightdiff > 1 || heightdiff < -1)
	return false;
	else
	return isBalanced(root->left)&&isBalanced(root->right);
	
}

int main()
{
	struct node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->left->left->left = newnode(8);
	root->left->left->right = newnode(9);
	root->left->left->left->left = newnode(10);
	root->left->left->left->right = newnode(11);
	
	if(isBalanced(root)	)
	{
		printf("It is balanced\n");
	}
	
	else
	{
		printf("It is not balanced");
	}
	
	
}
