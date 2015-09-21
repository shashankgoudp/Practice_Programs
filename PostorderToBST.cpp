#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int Search(int key,int array[],int start_index,int end_index);
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
// A utility function to create a node
struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

int Search(int key,int array[],int start_index,int end_index)
{
	int i;
	for(i=end_index;i>=start_index;i--)
	{
		if(array[i]<key)
		return i;
	}
}



struct node* BuildTree(int post_order_Array[],int start_index,int end_Index)
{
	struct node* node = newNode(post_order_Array[end_Index]);
	int newIndex;
	
	if(start_index == end_Index)
	{
		return node;
	}
	
	
	newIndex = Search(node->data,post_order_Array,start_index,end_Index-1);
	
	
	
	node->left = BuildTree(post_order_Array,start_index,newIndex);
	node->right = BuildTree(post_order_Array,newIndex+1,end_Index-1);
	
	
	return node;
	
}

void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main ()
{
    int pre[] = {1,7,5,40,10};
   // int size = sizeof( pre ) / sizeof( pre[0] );
 
    struct node *root = BuildTree(pre,0,4);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}
