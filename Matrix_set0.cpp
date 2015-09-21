#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[4][4] ={1,2,3,4,5,6,7,8,1,2,3,0,5,6,7,8};
	
	int i;
	int j;
	char row[4];
	char column[4];
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			//printf(" %d ",A[i][j]);
			if(A[i][j]==0)
			{
				row[i] = 't';
				column[j] = 't';
			}
		}
		
	//	printf("\n");
	}
	
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(row[i]=='t' || column[j]=='t')
			{
				A[i][j] = 0;
			}
		}
	}
	
	
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf(" %d ",A[i][j]);
		}
		
		printf("\n");
	}
}
