#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *next;
};

struct queue
{
	struct node *stack1;
	struct node *stack2;
};
void push(struct node **head,int data);
int pop(struct node **stack);
void enqueue(struct queue *q,int data)
{
	push(&q->stack1,data);
}

void push(struct node **head,int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *node = *head;
	temp->data = data;
	temp->next = NULL;
	if(*head == NULL)
	{
		*head = temp;
		return;
	}
	
	else
	{
		while(node->next!=NULL)
		{
			node = node->next;
		}
		node->next = temp;
	}
}

int pop(struct node *stack)
{
	int data;
	if(stack == NULL)
	{
		printf("Stack is Empty\n");
		return NULL;
	}
	
	else
	{
		struct node *temp = stack;
		struct node *prev = NULL;
		while(temp->next !=NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		data = temp->data;
		prev->next = NULL;
		free(temp);
		return data;
	}
}
bool isEmpty(struct node *stack)
{
	if(stack == NULL)
	return true;
	else
	return false;
}


int dequeue(struct queue *q)
{
	int data;
	if(q->stack1 == NULL)
	{
		printf("Queue is empty\n");
		return 0;
	}
	while(q->stack1!=NULL)
	{
		push(&q->stack2,pop(q->stack1));
	}
	
	data = pop(q->stack2);
	while(q->stack2!=NULL)
	{
		push(&q->stack1,pop(q->stack2));
	}
	
	return data;
	
}
int main()
{
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	printf("Popped element is %d\n ",dequeue(q));
	printf("Popped element is %d\n ",dequeue(q));
	printf("Popped element is %d\n ",dequeue(q));
}
