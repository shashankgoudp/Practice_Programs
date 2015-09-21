#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	};


void push(struct node **head,int data)
{
	struct node *tempnode = (struct node *)malloc(sizeof(struct node));
	tempnode->data = data;
	tempnode->next = *head;
	*head =tempnode;
}


void printlist(struct node *node)
{
	while(node !=NULL)
	{
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL");
}


struct node* addDigits(struct node *a,struct node *b,struct node **c)
{
	struct node *temp1 = a;
	struct node *temp2 = b;
	struct node *temp3 = *c;
	
	int data1;
	int data2;
	int data3;
	int carrybit = 0;
	int i =0;
	int j =0;
	int k = 0;
	int l = 0;
	
	while(temp1 && temp2)
	{
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		data1 = temp1->data;
		printf("data1 is %d after %d iteration ",data1, ++j);
		printf("\n");
		data2 = temp2->data;
		printf("data2 is %d after %d iteration ",data2, ++k);
		printf("\n");
		data3 = data1 + data2 + carrybit;
		printf("data3 is %d after %d iteration ",data3, ++l);
		printf("\n");
	
		carrybit = data3/10;
		printf("carry bit is %d\n ",carrybit);
		data3 = data3%10;
		printf("data3 is %d\n ",data3);
		newnode->data = data3;
		newnode->next = NULL;
		
		printf("newnode data is  %d\n",newnode->data);
		printf("newnode next is %d\n",newnode->next);
			
	
		if(temp3 == NULL)
		{
			printf("i value in loop is %d\n ",++i);
			temp3 = newnode;
			printf("temp3 data is %d\n",temp3->data);
			*c = temp3;
			printf("temp3 next is %d\n",temp3->next);
		//	temp1 = temp1->next;
		//	temp2 = temp2->next;
		}
		
		else
		{
			printf("temp3 data is  dash %d\n",temp3->data);
			printf("temp3 next is %d\n",temp3->next);
			
			temp3->next = newnode;
			temp3 = temp3->next;
			printf("temp3 data is %d\n",temp3->data);
			printf("temp3 next is %d\n",temp3->next);
		}
		
		temp1 = temp1->next;
		temp2 = temp2->next;
		
	}
	
	// while(temp1)
	// {
	// 	data1 = temp1->data;
	// 	data3 = data1 + carrybit;
		
	// 	carrybit = data3/10;
	// 	data3 = data3%10;
	// 	newnode->data = data3;
	// 	newnode->next = NULL;
	// 	if(temp3 == NULL)
	// 	{
	// 		temp3 = newnode;
	// 		*c = temp3;
	// 	}
		
	// 	else
	// 	{
	// 		temp3->next = newnode;
	// 		temp3 = temp3->next;
			
	// 	}
		
	// }
	
	// while(temp2)
	// {
	// 	data2 = temp2->data;
	// 	data3 = data2 + carrybit;
		
	// 	carrybit = data3/10;
	// 	data3 = data3%10;
	// 	newnode->data = data3;
	// 	newnode->next = NULL;
	// 	if(temp3 == NULL)
	// 	{
	// 		temp3 = newnode;
	// 		*c = temp3;
	// 	}
		
	// 	else
	// 	{
	// 		temp3->next = newnode;
	// 		temp3 = temp3->next;
			
	// 	}
		
	// }
	
	return *c;
	
	
}

int main(void) {
	struct node* first_number = NULL;
	struct node* second_number = NULL;
	struct node* third_number = NULL;
 
  	push(&first_number, 1); 
    push(&first_number, 2); 
    push(&first_number, 3); 
    
    
    push(&second_number, 4);
    push(&second_number, 5);
    push(&second_number, 6);  
   
    printlist(first_number);  
    printf("\n");
    printlist(second_number);  
    printf("\n");
    third_number = addDigits(first_number,second_number,&third_number);
    printlist(third_number);  
    getchar();
}
