#include<stdio.h>
#include<stdlib.h>

//int path1[10];
//int path2[10];
struct node
{
	int data;
	node *left;
	node *right;
};
bool findpath(struct node *root, int &path,int n)
{
	static int i = 0;
	if(root == NULL)
	{
		return true;
	}
	
	
	path[i++] = root->data;
	if(root->data == n)
	{
		return true;
	}
	
	if(findpath(root->left,path,n)||findpath(root->right,path,n))
	return true;
	
	return false;
	
}
int lca(struct node *root, int n1, int n2)
{
	int path1[10],path2[10],i,j;
	
	if(!findpath(root,path1,n1) || !findpath(root,path,n2))
	
	for(i=0;i<10;i++)
	{
		printf(" %d \n",path1[i]);
	}
	
	return -1;
	
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
	
	data = lca(root,1,3);
}
