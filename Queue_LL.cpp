#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *stack1;
	struct node *stack2;
};

void push(struct node **stack, int data);
int pop(struct node **stack);
void enqueue(struct queue *q, int data)
{
					//	struct node *temp = (struct node*)malloc(sizeof(struct node));
					//	temp->data = data;
					//	temp->next = NULL;
					//	if(*root == NULL)
					//	{
					//		
					//		*root = temp;
					//		
					//	}
					//	
					//	else
					//	{
					//		struct node *current = *root;
					//		while(current->next!=NULL)
					//		{
					//			current = current->next;
					//		}
					//		
					//		current->next = temp;
					//	}
					
	push(&q->stack1,data);
}

void push(struct node **stack,int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *current = *stack;
	
	temp->data = data;
	temp->next = NULL;
	
	if(*stack == NULL)
	{
		*stack = temp;
	}
	else
	{
		while(current->next!=NULL)
		{
			current = current->next;
		}
		
		current->next = temp;
	}
}


int pop(struct node **stack)
{
	struct node *current = *stack;
	int data = current->data;
	*stack = current->next;
	free(current);
	return data;
	
}

int dequeue(struct queue *q)
{
					//	struct node *current = *root;
					//	int data = current->data;
					//	*root = current->next;
					//	free(current);
					//	return data;
					//	
	int data;
	if(q->stack1 == NULL)
	{
		printf("Queue is empty\n");
		return 0;
	}
	
	while(q->stack1!=NULL)				
	{
		push(&q->stack2,pop(&q->stack1));
	}
	
	data = pop(&q->stack2);
	
	while(q->stack2!=NULL)
	{
		push(&q->stack1,pop(&q->stack2));
	}
	return data;
	
}
void printqueue(struct node *root)
{
	struct node *current = root;
	while(current!=NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}
}
int main()
{
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
   printf("%d  ", dequeue(q));
   printf("%d  ", dequeue(q));
 //  printf("%d  ", dequeue(q));  
		
}
