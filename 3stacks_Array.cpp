#include<stdio.h>
#include<stdlib.h>

int A[75];
int Top1= -1;
int Top2=24;
int Top3=49;
int size = 25;

void push(int stackno,int data)
{
	if(stackno == 1)
	{
		if(Top1 == 24)
		{
			printf("Stack1 is full");
			return;
		}
		else
		{
			A[++Top1]=data;
		}
		
	}
	
	if(stackno == 2)
	{
		if(Top2 == 49)
		{
			printf("Stack2 is full");
			return;
		}
		else
		{
			A[++Top2]=data;
		}
		
	}
	
	if(stackno == 3)
	{
		if(Top3 == 74)
		{
			printf("Stack3 is full");
			return;
		}
		else
		{
			A[++Top3]=data;
		}
		
	}
}


int pop(int stackno)
{
	int data;
	if(stackno ==1)
	{
		
		data = A[Top1--];
	}
	
	if(stackno ==2)
	{
		
		data = A[Top2--];
	}
	
	if(stackno ==3)
	{
		
		data = A[Top3--];
	}
	
	return data;
}

void printstack(int stackno)
{
	if(stackno ==1)
	{
		
		int i =0;
		while(i<=Top1)
		{
			printf(" %d ",A[i]);
			i++;
		}
	}
	
	if(stackno ==2)
	{
		int i =25;
		while(i<=Top2)
		{
			printf(" %d ",A[i]);
			i++;
		}
	}
	
	if(stackno ==3)
	{
		int i =50;
		while(i<=Top3)
		{
			printf(" %d ",A[i]);
			i++;
		}
	}
}
int main()
{
	push(1,1);
	push(1,2);
	push(2,3);
	push(2,4);
	push(3,5);
	push(3,6);
	
	printstack(1);
	printstack(2);
	printstack(3);
	
	printf("Popping from stack1 %d \n",pop(1));
	printf("Popping from stack1 %d \n",pop(2));
	printf("Popping from stack1 %d \n",pop(3));
}

