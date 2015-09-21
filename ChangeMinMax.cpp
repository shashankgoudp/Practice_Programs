#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int key;
    struct node *left, *right;
};
  
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
    
    printf("\n");
}
  
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    /* return the (unchanged) node pointer */
    return node;
}
  
void ChangeMin(struct node *node,int min)
{
	if(node == NULL)
	return;
	else
	ChangeMin(node->left,min);
	
	if(node->key <min)
	{
		if(node->right == NULL)
		node->key =NULL;
		else if(node->right->key>min)
		node->key = node->right->key;
		else
		node == NULL;
	}
}

void changeMax(struct node *node,int max)
{
	if(node == NULL)
	return;
	ChangeMax(node->right,max);
	
	if(node->key > max)
	{
		if(node->left == NULL || node->left->data >max )
		node ==NULL;
		else 
		node->data = node->left->data;
	}
}
int main()
{

    struct node *root = NULL;
    root = insert(root, 6);
    insert(root, -13);
    insert(root, -8);
    insert(root, 14);
    insert(root, 13);
    insert(root, 7);
    insert(root, 15);
  
    // print inoder traversal of the BST
    inorder(root);
    ChangeMin(root,-10);
    inorder(root);
    ChangeMax(root,13)
    inorder(root);
  
    return 0;
}
