/*
BINARY SEARCH TREE: PREORDER, POSTORDER, INORDER
INORDER: SORTED IN ASCENDING ORDER
#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
	malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 
int showpost(struct node* node) 
{ 
	if (node == NULL) 
	{
		return; 
	}
	showpost(node->left); 
	showpost(node->right); 
	printf("%d ", node->data); 
} 
int showin(struct node* node) 
{ 
	if (node == NULL) 
	{
	    return; 
	}
	showin(node->left); 
	printf("%d ", node->data); 
	showin(node->right); 
} 
int showpre(struct node* node) 
{ 
	if (node == NULL) 
	{
	    return; 
	}
	printf("%d ", node->data); 
	showpre(node->left); 
	showpre(node->right); 
}	 
int main() 
{ 
    int a=5; int b=10; int c=21; int d=36; int e=45; int f=72;
	struct node *root = newNode(a); 
	root->left = newNode(b); 
	root->right = newNode(c); 
	root->left->left = newNode(d); 
	root->left->left->left = newNode(e); 
	root->left->right = newNode(f); 
	
    	printf("\nThe Binary Tree Elements: %d, %d, %d, %d, %d, %d",a,b,c,d,e,f);
printf("\nPreorder traversal of binary tree is \n"); 
	showpre(root); 
	printf("\nInorder traversal of binary tree is \n"); 
	showin(root); 
	printf("\nPostorder traversal of binary tree is \n"); 
	showpost(root); 
}
*/