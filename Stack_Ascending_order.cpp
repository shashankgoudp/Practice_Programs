#include<stdio.h>
#include<stdlib.h>

struct stack{
	int capacity;
	int *array;
	int top;
	
};

struct stack* createstack(int capacity)
{
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	s->capacity = capacity;
	s->top = -1;
	s->array = (int*)malloc(s->capacity * sizeof(int));
	return s;
}

void push(struct stack *s, int data)
{
	if(s->top == s->capacity -1)
	{
		printf(" stack is full");
	}
	
	else
	{
		s->array[++s->top] = data;
	}
}

void printstack(struct stack *s)
{
	int x = s->top;
	while(x != -1)
	{
		printf("%d\n",s->array[x])	;
		x--;
	}
}

int pop(struct stack *s)
{
	if(s->top == -1)
	{
		printf("stack is empty\n");
		return NULL;
	}
	else
	{
		return(s->array[s->top--]);
	}
}

int peek(struct stack *s)
{
	if(s->top == -1)
	return NULL;
	else
	return(s->array[s->top]);
}
void AscendingOrder(struct stack *s1, struct stack *s2)
{

	
	while(s1->top != -1)
	{
		int temp = pop(s1);
		
		if(s2->top == -1)
		{
			push(s2,temp);
		}
		while((s2->top != -1 ))
		{
			if(temp>peek(s2))
			{
				push(s2,temp);
				break;
			}
			else if (temp == peek(s2))
			{
				break;
			}
			else
			{
				push(s1,pop(s2));
			}
		}
	}
	
	
}
int main()
{
	struct stack *s1 = createstack(10);
	struct stack *s2 = createstack(10);
	push(s1,2);
	push(s1,6);
	push(s1,7);
	push(s1,4);
	push(s1,3);
	push(s1,1);
	printstack(s1);
	AscendingOrder(s1,s2);
	printstack(s2);
	
//	printf("Item popped is %d\n",pop(s1));
//	printf("Item popped is %d\n",pop(s1));
//	printf("Item popped is %d\n",pop(s1));
//	
	
	
}
