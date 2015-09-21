#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100
char A[MAX_SIZE];
int Top =-1;

void push(char ch)
{
	if(Top == MAX_SIZE)
	{
		printf("Stack is full");
		return;
	}
	
	else
	{
		A[++Top] = ch;
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
char pop()
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

char peek()
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

bool isMatchingPair(char character1, char character2)
{
	 if(character1 == '(' && character2 == ')')
     return 1;
   else if(character1 == '{' && character2 == '}')
     return 1;
   else if(character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}

bool balancedParanthesis(char ch[])
{
	int i;
	int strlength = strlen(ch);
	for(i=0;i<strlength;i++)
	{
		if(ch[i] == '('||ch[i] == '{'||ch[i] == '[')
		{
			push(ch[i]);
		}
		else
		{
		
			if(ch[i] == ')'||ch[i] == '}'||ch[i] == ']')
			{
				if(isEmpty())
				{
					return 0;
				}
				
				else if(!(isMatchingPair(pop(),ch[i])))
					return 0;
			}
		}
	}
	
	if(isEmpty())
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
	char exp[100] = "{()}[]";
 if(balancedParanthesis(exp))
    printf("\n Balanced ");
  else
    printf("\n Not Balanced ");  
}

