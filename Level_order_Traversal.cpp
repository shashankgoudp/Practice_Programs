#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;

};
void printGivenLevel(struct node* node, int level,bool ltr);
struct node *newnode(int data)
{
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}
void printTree(struct node *node)
{
	if(node == NULL)
	return;
	else
	printTree(node->left);
	printf("%d\n",node->data);
	printTree(node->right);
}
int heightOfTree(struct node *node)
{
	struct node *temp = node;
	int lheight;
	int rheight;
	 if(temp == NULL)
	 {
	 	return 0;
	 }
	 
	 else
	 {
	 	lheight = heightOfTree(temp->left)+1;
	 	rheight = heightOfTree(temp->right)+1;
	 }
	 
	 if (lheight >rheight)
	 	return lheight;
	else
		return rheight;
	 
	 
}

void levelOrder(int height,struct node *node)
{
	struct node *temp =node;
	int i;
	bool ltr = false;
	for(i = 1;i<=height;i++)
	{
		printGivenLevel(temp,i,ltr);
		ltr = !ltr;
	}

}
void printGivenLevel(struct node *node,int level,bool ltr)
{
	if(node == NULL)
	return;
	
	if(level == 1)
		printf("%d ",node->data);
	else{
	
	if( ltr)
	{
	printGivenLevel(node->left,level-1,ltr);
	printGivenLevel(node->right,level-1,ltr);
	}
	else
	{
	printGivenLevel(node->right,level-1,ltr);
	printGivenLevel(node->left,level-1,ltr);	
	}
	}
		
}
int main()
{
	struct node *root = newnode(1);
	int height;
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(7);
	root->left->right = newnode(6);
	root->right->left = newnode(5);
	root->right->right = newnode(4);
	height = heightOfTree(root);
	printf("Height of tree is %d\n",height);
	levelOrder(height,root);
//	printTree(root);
	
}
