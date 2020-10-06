#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
struct node *lca( struct node *root, int v1, int v2 ) {
    if(!root) return NULL;
    
    if(root->data ==v1 || root->data==v2){
        return root;
    }
    else{
        struct node* l= lca(root->left,v1,v2);
        struct node* r= lca(root->right,v1,v2);
        if(l && r)
            return root;
        else if(l)
            return l;
        else
            return r;
        
    }
}

int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  	int v1;
  	int v2;
  
  	scanf("%d%d", &v1, &v2);
	struct node *ans = lca(root, v1, v2);
  	printf("%d", ans->data);
  	
    return 0;
}
