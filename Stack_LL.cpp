#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
};

void push(struct node **root, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
//	temp->next = NULL;
	if(*root == NULL)
	{
		temp->next = NULL;
		*root = temp;
		return;
	}
	
	else
	{
		temp->next = *root;
		*root = temp;
		return;
	}
	
}

void printStack(struct node *root)
{
	struct node *temp = root;
	if(root == NULL)
	{
		printf("Stack is empty\n");
	}
	
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp = temp->next;
		}
		
	}
	
}

int isEmpty(struct node *root)
{
	return (root==NULL? 1:0);
}
int pop(struct node **root)
{
	int popped_data;
	if(isEmpty(*root))
	{
		printf("Stack is empty\n");
	}
	struct node *temp = *root;
	*root = (*root)->next;
	popped_data = temp->data;
	free(temp);
	return popped_data;
}
int main()
{
	struct node *root = NULL;
	push(&root,1);
	push(&root,2);
	push(&root,3);
	push(&root,4);
	push(&root,5);
	printStack(root);
	printf("\n");
	printf("%d popped from stack\n", pop(&root));
	printf("%d popped from stack\n", pop(&root));
	printf("%d popped from stack\n", pop(&root));
	printf("%d popped from stack\n", pop(&root));
	printf("%d popped from stack\n", pop(&root));
	printf("%d popped from stack\n", pop(&root));
	printf("\n");
	printStack(root);
}
