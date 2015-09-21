#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	node *left;
	node *right;
};

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}
bool areIdentical(struct node *T, struct node *S)
{
	if(T==NULL && S==NULL){
		return true;
	}
	
	if(T==NULL || S==NULL)
	{
		return false;
	}
	
	return ((T->data == S->data)&&areIdentical(T->left,S->left)&&areIdentical(T->right,S->right));
}
bool isSubtree(struct node *T, struct node *S)
{
	if(S==NULL)
	{
		return true;
	}
	
	if(T==NULL)
	{
		return false;
	}
	
	if(areIdentical(T,S))
	{
		return true;
	}
	
	return (isSubtree(T->left,S)||isSubtree(T->right,S));
}
int main()
{
	struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(5);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
    
    
    
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
    
    if (isSubtree(T, S))
        printf("Tree S is subtree of tree T");
    else
        printf("Tree S is not a subtree of tree T");
}
