#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	};
void removeLoop(struct node *loop_node, struct node *head);
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
	printf("NULL\n");
}
void reverse(struct node **head, int k)
{
	struct node *prev = NULL;
	struct node *current = *head;
	struct node * next;
	
	
	while(current != NULL)
	{
		
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	*head = prev;
	
	
}

void _delLesserNodes(struct node *head)
{
     struct node *current = head;
 
     /* Initialize max */
     struct node *maxnode = head;
     struct node *temp;
 
     while (current != NULL && current->next != NULL)
     {
         /* If current is smaller than max, then delete current */
         if(current->next->data < maxnode->data)
         {
             temp = current->next;
             current->next = temp->next;
             free(temp);
         }
 
         /* If current is greater than max, then update max and
            move current */
         else
         {
             current = current->next;
             maxnode = current;
         }
 
     }
}

void segregate(struct node *head)
{
	struct node* temp = head;
	struct node *even  = head;
	struct node *odd = head;
	int data;
	while(odd != NULL)
	{
		if(odd->data%2 == 0)
		{
			data = odd->data;
			odd->data = even->data;
			even->data = data;
			even = even->next;
			odd = odd->next;
		}
		else
		{
			odd = odd->next;
		}
	}
}

int detectLoop(struct node *head)
{
	struct node *first = head;
	struct node *second = head;
	
	while(first && second->next && second->next)
	{
		first = first->next;
		second = second->next->next;
		if(first == second)
		{
			printf("Loop exists");
			removeLoop(first,head);
			return 1;			
		}
	}
	
	return 0;
}
void removeLoop(struct node *loop_node, struct node *head)	
{
	struct node *ptr1 = loop_node;
	struct node *ptr2 = loop_node;
	unsigned int k = 1;
	int i;
	printf("In remove Loop\n");
	
	while(ptr2->next !=ptr1)
	{
		ptr2 = ptr2->next;
		k++;
	}
	
	printf("K value is %d\n");
	ptr1 = head;
	ptr2 = head;
	
	for(i = 0; i < k; i++)
      {
      	ptr2 = ptr2->next;	
      	printf("In for loop\n");
	  }
	
	while(ptr1!=ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	ptr2 = ptr2->next;
	while(ptr2->next !=ptr1)
	{
		ptr2 = ptr2->next;
	}
	
	printf("ptr2 data is %d",ptr2->data);
	ptr2->next = NULL;
}

struct node* RotateList(struct node **head, int size)
{
	struct node *temp = *head;
	struct node *next = *head;
	struct node *rot;
	int i =1;
	while(i<size)
	{
		temp = temp->next;
		i++;
	}
	
	printf("temp data is %d \n",temp->data);
	rot = temp->next;
	temp->next = NULL;
	
	*head = rot;
	printf("rot data is %d \n",rot->data);
	
	while(rot->next!=NULL)
	{
		rot = rot->next;
	}
	
	rot->next = next;
	
	return *head;
	
	
}
int main(void) {
	struct node* list1 = NULL;
	struct node *roratedList = NULL;
	
  	push(&list1, 60);
    push(&list1, 50);
    push(&list1, 40);
    push(&list1, 30);
    push(&list1, 20);
    push(&list1, 10);
    printlist(list1);
    roratedList = RotateList(&list1,4);
    printlist(roratedList);
  	
}
