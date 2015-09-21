#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
int A[MAX_SIZE];
int Top =-1;

void push(int data)
{
	if(Top == MAX_SIZE)
	{
		printf("Stack is full");
		return;
	}
	
	else
	{
		A[++Top] = data;
	}
}
void printStack()
{
	int x = Top;
	if(Top == -1)
	{
		printf("Stack is empty");
	}
	
	while(x >= 0)
	{
		printf("%d\n",A[x]);
		x--;
	}
}
int pop()
{
	if(Top == -1)
	{
		printf("Stack is empty");
		return NULL;
	}
	int x = A[Top--];
	return x;
	
}
int isOperand(char ch)
{
	return( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') );
}

int isEmpty()
{
	if(Top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int peek()
{
	return A[Top];
}

int prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		
	}
	return -1;
}
int infixToPostfix(char exp[])
{
	int k = -1;
	int i;
	int strlength = strlen(exp);
//	printf("string length is %d",strlength);
	for(i =0;i<strlength;i++)
	{
		if(isOperand(exp[i]))
		{
			exp[++k] = exp[i];
		}
		
		else if(exp[i] == '(')
		{
			push(exp[i]);
		}
		
		else if(exp[i] == ')')
		{
			while(!isEmpty() && peek()!='(')
			{
				exp[++k] = pop();
			}
			
			if(!isEmpty() && peek()!='(')
			{
				return -1;
			}
			else
			{
				pop();
			}
		}
		
		else
		{
			while(!isEmpty() && prec(exp[i]) <= prec(peek()))
			{
				exp[++k] = pop();
			}
			push(exp[i]);
		}
	}
	
	while(!isEmpty())
	{
		exp[++k] = pop();
	}
	exp[++k] = '\0';
	printf("Postfix string is %s\n",exp);
	
	
}
int main()
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
//	int x;
//	push(1);
//	push(2);
//	push(3);
//	push(4);
//	push(5);
//	
//	printStack();
//	printf("popped element is %d\n",pop());
//		printf("popped element is %d\n",pop());
//
//	printf("popped element is %d\n",pop());
//
//	printf("popped element is %d\n",pop());
//
//	printf("popped element is %d\n",pop());
//		printf("popped element is %d\n",pop());
//
//
//		printStack();
}

