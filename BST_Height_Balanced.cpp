#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *left;
	node *right;
};

struct node* newnode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* BST(int ARR[],int startIndex,int endIndex)
{
	if(startIndex > endIndex)
	{
		return NULL;
	}
	int mid = (startIndex+endIndex)/2;
	struct node *root = newnode(ARR[mid]);
	root->left = BST(ARR,startIndex,mid-1);
	root->right = BST(ARR,mid+1,endIndex);
	
	return root;
}

void Inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	Inorder(root->left);
	printf("%d\n",root->data);
	Inorder(root->right);
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	struct node *root = BST(arr,0,6);
	Inorder(root);
}
