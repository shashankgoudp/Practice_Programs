#include<stdio.h>
#include<stdlib.h>

struct MaxHeap{
	int size;
	int *array;
	};
	void maxheapify(struct MaxHeap *maxheap,int index);
	void swap(int* a, int* b);
struct MaxHeap* createandBuildHeap(int *arr,int size)
{
	int i;
	struct MaxHeap* maxheap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
	maxheap->size = size;
	maxheap->array = arr;
	
	for(i =maxheap->size;i>=0;i++)
	{
		maxheapify(maxheap,i);
	}
	
	return maxheap;
	
}


void maxheapify(struct MaxHeap *maxheap,int index)
{
	int largest = index;
	int left = 2*index;
	int right = 2*index+1;
	
	if((left < maxheap->size)&& (maxheap->array[left] > maxheap->array[largest]))
	{
		largest = left;
	}
	
	if((right < maxheap->size)&& (maxheap->array[right] > maxheap->array[largest]))
	{
		largest = right;
	}
	
	if(largest!=index)
	{
		swap(&maxheap->array[index],&maxheap->array[largest]);
		maxheapify(maxheap,largest);
	}
	
}
void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t;}
void heapsort(int *arr,int size)
{
	struct MaxHeap* maxheap = createandBuildHeap(arr,size)	;
	
	while(maxheap->size > 1)
	{
		swap(&maxheap->array[0],&maxheap->array[maxheap->size-1]);
		--maxheap->size;		
		maxheapify(maxheap,0);
	}
	
	
}

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
int main()
{
	int arr[] ={12,11,13,5,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	heapsort(arr,size);
	printArray(arr,size);
	  return 0;
}
