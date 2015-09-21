#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	struct node *prev;
};


void insert(struct node **head, int data )
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *temp = *head;
	struct node *prev = NULL;
	if(*head == NULL)
	{
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = prev;
		*head = newnode;
		return;
	
	}
	
	else if(temp->next ==NULL)
	{
		prev= temp;
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = prev;
		temp->next = newnode;
		
	}
	
	else{
	
	while(temp->next!=NULL)
	{
	//	prev = temp;
		temp = temp->next;
	}
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = temp;
	temp->next = newnode;
	
	}
	
		
	
}

void printlist(struct node *head)
{
	struct node *temp = head;
	struct node *last;
	
		printf("Traversal in forward direction");
	while(temp!=NULL)
	{
	
		printf("%d ",temp->data);
		last = temp;
		temp = temp->next;
	}
	
	printf("\n");
		printf("Traversal in reverse direction");
	while(last!=NULL)
	{
	
		printf(" %d ",last->data);
		last = last->prev;
	}
	
	
	
}

void deletenode(struct node **head,int data)
{
	struct node *temp = *head;
	struct node *next;
	struct node *prev = NULL;
	if(temp->data == data)
	{
		next = temp->next;
		next->prev = prev;
		*head = next;
		free(temp);
		return;
	}
	
	else if(temp->data !=data)
	{
	
	while(temp->data !=data)
	{
		prev= temp;
		temp = temp->next;
	}
	
	if(temp->next !=NULL)
	{
	
	next = temp->next;
	prev->next = next;
	next->prev = prev;
	free(temp);
	return;
	}
	
	else if(temp->next == NULL)
	{
		prev->next = NULL;
		free(temp);
	}
	
	
	}
	
	else
	{
		printf("Number not found");
		return;
	}
}

void swap(struct node *head, int k)
{
	struct node *first = head;
	struct node *last;
	struct node *temp = head;
	int first_count = 1;
	int last_count = 1;
	int var;
	
	while(first->next!=NULL && first_count!=k)
	{
		first = first->next;
		first_count++;
	}
	
	printf("after first count\n");
	printf("%d\n",first_count);
	printf("first data is %d\n",first->data);
	
	if(first == NULL)
	{
		printf("k is greater than length of list\n");
		return;
	}
	
	while(temp!=NULL)
	{
		last = temp;
		temp = temp->next;
	}
	
	while(last->prev !=NULL && last_count!=k)
	{
		last = last->prev;
		last_count++;
	}
	printf("after last count\n");
	printf("%d\n",last_count);
	printf("last data is %d\n",last->data);
	
	if(first_count ==k && last_count ==k )
	{
		var = first->data;
		first->data = last->data;
		last->data = var;
	}
	
	
	
}
int main()
{
	struct node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	
	printlist(head);
	swap(head,2);
	//deletenode(&head,5);
	printlist(head);
}
