#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

struct stack{
	
	int capacity;
	int *array;
	int top;
};
void printstack(struct stack* stack);
struct stack* createstack(int capacity)
{
	struct stack *newstack = (struct stack*)malloc(sizeof(struct stack));
	newstack->capacity = capacity;
	newstack->top = -1;
	newstack->array = (int*)malloc(sizeof(int)*newstack->capacity);
	return newstack;
}

void push(struct stack *stack, int data)
{
	if(stack->top == stack->capacity -1)
	{
		printf("Stack is full\n");
		return;
	}
	
	else
	{
		stack->array[++stack->top] = data;
	}
}

int pop(struct stack *stack)
{
	int data;
	if(stack->top == -1)
	{
	//	printf("Stack is empty");
		return NULL;
	}
	
	data = stack->array[stack->top--];
	printf("Popped Item is %d\n",data);
	return data;
	
}

void MoveDisk(struct stack *src, struct stack *des)
{
	int pole1Top = pop(src);
	int pole2Top = pop(des);
	
	printf("pole1Top is %d", pole1Top);
	printf("pole2Top is %d", pole2Top);
	
	if(pole1Top == NULL)
	{
		push(src,pole2Top);
	}
	else if(pole2Top == NULL)
	{
		push(des,pole1Top);
	}
	else if(pole1Top > pole2Top)
	{
		push(src,pole1Top);
		push(src,pole2Top);
	}
	else
	{
		push(des,pole2Top);
		push(des,pole1Top);
		
	}
	
	printstack(src);
	printstack(des);
}

void ToH(struct stack *src, struct stack *aux, struct stack *des,int num_of_disks)
{
	int i;
	int num_of_moves = pow(2,num_of_disks) - 1;
	for(i=num_of_disks;i>0;i--)
	{
		push(src,i);
	}
	
	printstack(src);
	for(i=1;i<=num_of_moves;i++)
	{
		if(i%3==1)
		{
			MoveDisk(src,des);
		}
		
		if(i%3==2)
		{
			MoveDisk(src,aux);
		}
		
		if(i%3==0)
		{
			MoveDisk(aux,des);
		}
	}
}

void printstack(struct stack *stack)
{
	while(stack->top != -1)
	{
		printf("%d\n",stack->array[stack->top--]);
	}
}
int main()
{
	int num_of_disks = 3;
	struct stack *src = createstack(num_of_disks);
	struct stack *aux = createstack(num_of_disks);
	struct stack *des = createstack(num_of_disks);
	
	ToH(src,aux,des,num_of_disks);
	printstack(des);
	
}
