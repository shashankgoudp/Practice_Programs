#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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
int evaluatePostfix(char ch[])
{
	int i =0;
	int strlength = strlen(ch);
	for(i=0;i<strlength;i++)
	{
		if(isdigit(ch[i]))
		{
			push(ch[i]-'0');
		}
		
		else
		{
			int num1 = pop();
			int num2 = pop();
			switch(ch[i])
			{
				case '+':
					push(num1+num2);
					break;
				case '-':
					push(num1-num2);
					break;
				case '*':
					push(num1*num2);
					break;
				case '/':
					push(num1/num2);
					break;
			}
		}
	}
	
	return pop();
}
int main()
{
	char exp[] = "231*+9-";
	printf ("Value of %s is %d", exp, evaluatePostfix(exp));
    return 0;

}

