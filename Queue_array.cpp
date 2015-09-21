#include<stdio.h>
#include<stdlib.h>

//int Queue[100];
//int front= 0;
//int rear = -1;
//int size = 0;
int isEmpty();
int stack1[100];
int stack2[100];
int Top1 = -1;
int Top2 = -2;
void enqueue(int data)
{
	push(stack1,data,++Top1);
	
}

int dequeue()
{
	int data ;
	if(Top1 == -1 && Top2 == -1)
	{
		printf("Queue is empty\n");
	}
	
	else
	{
		while(Top1 !=-1)
		{
			push(stack2,pop(stack1),++Top2);
		}
	}
	
	data = pop(stack2);
	
	while(Top2 != -1)
	{
		push(stack1,pop(stack2),Top1);
	}
}


void push(int A[],int data,int Top)
{
	A[Top] = data;
	
	
}
void printqueue()
{
	int x = front;
	while(x<=rear)
	{
		printf(" %d ",A[x]);
		x = x+1;
		
	}
}

int isEmpty()
{
	if(size == 0)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}
int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	printqueue();
	printf("popped element is %d\n",dequeue());
	printf("popped element is %d\n",dequeue());
	printf("popped element is %d\n",dequeue());
	printqueue();
}



