// Manav Dhiman
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
struct node{
    int data;
    node* left;
    node* right;
    int ht;
    node(int x){
        data=x;
        left=right=NULL;
        ht=1;
    }
};
void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void preorder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}
int balancefactor(node* root){
    if(root==NULL) return 0;
    int hl=root->left?root->left->ht:0;
    int hr=root->right?root->right->ht:0;
    return hl-hr; 
}
node* LLrotation(node* root){
    node* p=root->left;
    node* temp=p->right;
    p->right=root;
    root->left=temp;
    root->ht=height(root);
    p->ht=height(p);
    return p;
}
node* LRrotation(node* root){
    node *temp=(root)->left;
    node* temp2=temp->right;
    temp->right=temp2->left;
    (root)->left=temp2->right;
    temp2->left=temp;
    temp2->right=root;
    temp2->ht=height(temp2);
    temp->ht=height(temp);
    (root)->ht=height(root);
    return temp2;
}
node* RRrotation(node* root){
    node* temp=(root)->right;
    node* temp2=temp->left;
    temp->left=root;
    (root)->right=temp2;
    temp->ht=height(temp);
    (root)->ht=height(root);
    return temp;
}
node* RLrotation(node* root){
    node* temp=(root)->right;
    node* temp2=temp->left;
    (root)->right=temp2->left;
    temp->left=temp2->right;
    temp2->left=root;
    temp2->right=temp;
    temp->ht=height(temp);
    temp2->ht=height(temp2);
    (root)->ht=height(root);
    return temp2;
}
node* insert(node* root,int x){
    node* temp=new node(x);
    if(root==NULL){
        root=temp;
        return root;
    }
    else if((root)->data>x) root->left=insert(((root)->left),x);
    else root->right=insert(((root)->right),x);
    (root)->ht=height(root);
    if(balancefactor(root)>1&&x<(root)->left->data){
        return LLrotation((root));
    }
    else if(balancefactor(root)>1&&x>(root)->left->data){
        return LRrotation(root);
    }
    else if(balancefactor(root)<-1&&x>(root)->right->data){
        return RRrotation((root));
    }
    else if(balancefactor(root)<-1&&x<(root)->right->data){
        return RLrotation((root));
    }
    return root;
}
node* minval(node* root){
    node* curr=root;
    if(root==NULL) return NULL;
    while(curr&&curr->left!=NULL) curr=curr->left;
    return curr;
}
node* avldel(node* root,int x){
    if(root==NULL) return root;
    else if((root)->data>x) root->left=avldel(root->left,x);
    else if(root->data<x) root->right=avldel(root->right,x);
    else{
        if(root->right==NULL&&(root)->left==NULL){
            node* temp=root;
            delete temp;
            root==NULL;
        }
        else if((root)->left==NULL){
            node* t=(root);
            (root)=(root)->right;
            delete t;
        }
        else if((root)->right==NULL){
            node* t=(root);
            (root)=(root)->left;
            delete t;
        }
        else{
            node* t=minval(root->right);
            (root)->data=t->data;
            root->right=avldel(root->right,t->data);
        }
    }
    if(root==NULL) return root;
    root->ht=height(root);
    int bal=balancefactor(root);
    if(bal>1 && balancefactor(root->left)>=0){
        return LLrotation((root));
    }
    else if(bal>1 && balancefactor(root->left)<0){
        return LRrotation((root));
    }
    else if(bal<-1 && balancefactor(root->right)<=0){
        return RRrotation((root));
    }
    else if(bal<-1 && balancefactor(root->right)>0){
        return RLrotation((root));
    }
    return root;
}
int main(){
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    node* root=NULL;
    root = insert(root, 9);  
    root = insert(root, 5);  
    root = insert(root, 10);  
    root = insert(root, 0);  
    root = insert(root, 6);  
    root = insert(root, 11);  
    root = insert(root, -1);  
    root = insert(root, 1);  
    root = insert(root, 2); 
    preorder(root);
    root=avldel(root,10);
    cout<<endl;
    preorder(root);
    return 0;
}