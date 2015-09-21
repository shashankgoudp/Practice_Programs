#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_SIZE 100
char S[MAX_SIZE];
char A[MAX_SIZE];
char D[MAX_SIZE];
int Top =-1;
void move(char fromPeg, char toPeg, int disk);
void push(char A[],char ch)
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
void printStack(char A[])
{
	int x = Top;
	if(Top == -1)
	{
	//	printf("Stack is empty");
	}
	
	while(x >= 0)
	{
		printf("%d\n",A[x]);
		x--;
	}
}
char pop(char A[])
{
	if(Top == -1)
	{
	//	printf("Stack is empty");
		return NULL;
	}
	int x = A[Top--];
	return x;
	
}
void movedisks(char src[],char des[],char s,char d)
{
	int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(des);
 
	 if(pole1TopDisk == NULL)
	 {
		push(src,pole2TopDisk);
		//move(d,s,pole2TopDisk);	
	 }
	 
	 else if(pole2TopDisk == NULL)
	 {
		push(des,pole1TopDisk);
	//	move(s,d,pole1TopDisk);	
	 }
	 
	 else if(pole1TopDisk > pole2TopDisk)
	 {
	 	push(src,pole1TopDisk);
	 	push(src,pole2TopDisk);
	 //	move(d,s,pole2TopDisk);	
	 }
	 else
	 {
	 	push(des,pole2TopDisk);
	 	push(des,pole1TopDisk);
	//	move(s,d,pole1TopDisk);	
	 }
	 
	 
}

//void move(char fromPeg, char toPeg, int disk)
//{
//    printf("Move the disk %d from \'%c\' to \'%c\'\n",
//           disk, fromPeg, toPeg);
//}
void ToH(int num_of_disks, char S[], char A[], char D[])
{
	int i;
	char s = 'S';
	char a = 'A';
	char d = 'D';
	int no_of_moves = pow(2, num_of_disks) - 1;
	for(i=num_of_disks;i>=1;i--)
	{
		push(S,i);
	}
	printStack(S);
	for(i = 1; i <= no_of_moves; i++)
	{
		if(i%3==1)
		{
			movedisks(S,D,s,d);
			printStack(D);
		}
	
		else if(i%3==2)
		{
			movedisks(S,A,s,a);
		}
		else
		{
			movedisks(A,D,a,d);
		}
		
	}
	
	
}

int main()
{
	int no_of_disks = 3;
	ToH(no_of_disks,S,A,D);
		printStack(D);
}

