#include <stdio.h>
#include <stdlib.h>

void MaxSubArray(int arr[],int arr_size,int size)
{
	int i;
	for(i=0;i<arr_size-2;i++)
	{
		if(arr[i]>arr[i+1] && arr[i+1]<arr[i+2])
		{
			if(arr[i]<arr[i+2])
			printf("%d",arr[i+2]);
			else
			printf("%d",arr[i]);
		}
		
		else if(arr[i]>arr[i+1] && arr[i+1]>arr[i+2])
		{
			printf("%d",arr[i]);
		}
		else if(arr[i]<arr[i+1] && arr[i+1]<arr[i+2])
		printf("%d",arr[i+2]);
		else
		printf("%d",arr[i+1]);
		
	}
}
 
int main()
{
  int arr[] =  {1, 2, 3, 1, 4, 5, 2, 3, 6};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  MaxSubArray(arr,arr_size,3);

}
