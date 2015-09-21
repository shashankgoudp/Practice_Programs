#include<stdio.h>

int main()
{
	int A[] ={20, 10, 8, 6, 4, 2};
	int i;
	int temp;
	for(i=0;i<5;i++)
	{
		if((A[i]<A[i+1])&& (A[i+1]>A[i+2]))
		{
		}
		else if((A[i] < A[i+1]) && (A[i+1] < A[i+2]))
		{
			temp = A[i+1];
			A[i+1] = A[i+2];
			A[i+2] = temp;
		}
		else if((A[i] > A[i+1]) && (A[i+1] < A[i+2]))
		{
		
		}
		else
		{
			temp = A[i+1];
			A[i+1] = A[i+2];
			A[i+2] = temp;
		}
		
	}
	for(i=0;i<6;i++)
	{
		printf("%d\n",A[i]);
	}
}
