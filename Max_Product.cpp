#include<stdio.h>
int main()
{
	int A[10] = {-15,-1,4,8,0,9,3,10,7,6};
	int B[3];
	int k =0;
	int first_high;
	int second_high;
	int third_high;
	
	int first_small;
	int second_small;
	
	int max_product_high;
	int max_product_lowandhigh;
	int i;
	int j;
	for(int j = 0;j<10;j++)
	{
		if(A[j] == 0)
		{
			
		}
		else
		{
			B[k++] = A[j];
			if(k == 3)
			{
				break;
			}
		}
	}
	
	
	if(B[0] > B[1])
	{
		if(B[0] < B[2])
		{
			first_high = B[2];
			second_high = B[0];
			third_high = B[1];
		}
		else if(B[0] > B[2])
		{
			if(B[1] < B[2])
			{
				first_high = B[0];
				second_high = B[2];
				third_high = B[1];
			}
			else
			{
				first_high = B[0];
				second_high = B[1];
				third_high = B[2];
			}
		}
	}
	
	else if(B[0] < B[1])
	{
		if(B[1] < B[2])
		{
			first_high = B[2];
			second_high = B[1];
			third_high = B[0];
		}
		else if(B[1] > B[2])
		{
			if(B[0] < B[2])
			{
			first_high = B[1];
			second_high = B[2];
			third_high = B[0];
			}	
			else
			{
			first_high = B[1];
			second_high = B[0];
			third_high = B[2];
			}
		}
	}
	
	first_small = third_high;
	second_small = second_high;
	
	for(i = j;i<10;i++)
	{
		if(A[i] == 0)
		{
		
		}
		else
		{
			if(A[i] > first_high)
			{
				third_high = second_high;
				second_high = first_high;
				first_high = A[i];
			}
		
			else if(A[i] < first_high && A[i] > second_high)
			{
				third_high = second_high;
				second_high = A[i];
			}
			else if(A[i] < first_high && A[i] < second_high && A[i] > third_high)
			{
				third_high = A[i];
			}
			
			else
			{
				
			}
			
			if(A[i] < first_small)
			{
				second_small = first_small;
				first_small = A[i];
			
			}
		}
	}
	
	max_product_high = first_high*second_high*third_high;
	max_product_lowandhigh = first_small*second_small*first_high;
	
	printf("Maximum product is %d\n",max_product_high > max_product_lowandhigh ? max_product_high : max_product_lowandhigh );
	}
