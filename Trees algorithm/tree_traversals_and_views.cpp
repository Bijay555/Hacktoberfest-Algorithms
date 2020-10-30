//Manav Dhiman
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
struct node{
    char data;
    node* left;
    node* right;
    node(char x){
        data=x;
        left=right=NULL;
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
void preorder2(node* root){
    if(root==NULL) return;
    stack<node* > s;
    s.push(root);
    node* temp=NULL;
    while(!s.empty()){
        temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right!=NULL) s.push(temp->right);
        if(temp->left!=NULL) s.push(temp->left);
    }
    // cout<<endl;
}
void inorder2(node* root){
    if(root==NULL) return;
    stack<node*> s;
    // s.push(root);
    node* temp=root;
    while(!s.empty()||temp!=NULL){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void postorder2(node* root){
    if(root==NULL) return;
    stack<node*> s1,s2;
    s1.push(root);
    node* temp=NULL;
    while(!s1.empty()){
        temp=s1.top();
        s2.push(temp);
        s1.pop();
        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }
    while(!s2.empty()){
        temp=s2.top();
        cout<<temp->data<<" ";
        s2.pop();
    }
}
void postorder3(node* root){
    if(root==NULL) return;
    stack<node*> s;
    node *temp=root;
    while(temp||!s.empty()){
        if(temp!=NULL){
            s.push(temp);
            temp=temp->left;    
        }
        else{
            node *temp2=s.top()->right;
            if(!temp2){
                temp2=s.top();
                s.pop();
                cout<<temp2->data<<" ";
                while(!s.empty()&&temp2==s.top()->right){
                    temp2=s.top();
                    s.pop();
                    cout<<temp2->data<<" ";
                }
            }
            else  temp=temp2;
        }
    }
}
void levelorder(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
    cout<<endl;
}
int nodes(node* root){
    if(root==NULL) return 0;
    return 1+nodes(root->left)+nodes(root->right); 
}
int finddepth(node* root){
    if(root==NULL) return 0;
    return max(finddepth(root->left),finddepth(root->right))+1;
}
void topview(node* head){
    if(head==NULL) return;
    map<int,int> m;
    queue<pair<node*,int>> q;
    q.push({head,0});
    int temp;
    node *temp2=NULL;
    while(!q.empty()){
        temp=q.front().second;
        temp2=q.front().first;
        q.pop();
        if(m.find(temp)==m.end()){
            cout<<temp2->data<<" "; 
            m[temp]=temp2->data;    
        }
        if(temp2->left) q.push({temp2->left,temp-1});
        if(temp2->right) q.push({temp2->right,temp+1});
    }
    cout<<endl;
}

node* buildtree(char in[],char pre[],int s,int e){
    if(s>e) return NULL;
    static int i=0;
    char c=pre[i++];
    node* temp=new node(c);
    if(s==e) return temp;
    int id=0;
    for(int i=s;i<=e;i++){
        if(c==in[i]){
            id=i;
            break;
        }
    }
    temp->left=buildtree(in,pre,s,id-1);
    temp->right=buildtree(in,pre,id+1,e);
    return temp;    
}
void inorder_leftview(node* root,int *level,int curr){
    if(root==NULL) return;
    if(curr>*level){
        cout<<root->data<<" ";
        *level=curr;
    }  
    inorder_leftview(root->left,level,curr+1);
    inorder_leftview(root->right,level,curr+1);
}
void leftview(node* root){
    int level=0;
    inorder_leftview(root,&level,1);
}
void inorder_rightview(node* root,int *level,int curr){
    if(root==NULL) return;
    if(curr>*level){
        cout<<root->data<<" ";
        *level=curr;
    }  
    inorder_rightview(root->right,level,curr+1);
    inorder_rightview(root->left,level,curr+1);
}
void rightview(node* root){
    int level=0;
    inorder_rightview(root,&level,1);
}
int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}
void bottomview(node* root){
    if(root==NULL) return;
    map<int,char> m;
    queue<pair<node*,int>> q;
    q.push({root,0});
    node* temp=NULL;
    m[0]=root->data;
    int hd=0;
    while(!q.empty()){
        temp=q.front().first;
        hd=q.front().second;
        q.pop();
        m[hd]=temp->data;
        if(temp->left) q.push({temp->left,hd-1});
        if(temp->right) q.push({temp->right,hd+1});
    }
    for(auto x:m)   cout<<x.second<<" ";
    cout<<endl;
}
void printlevel(node* root,int level,bool b){
    if(root==NULL) return;
    if(level==1) cout<<root->data<<" ";
    else if(level>1){
        if(b){
            printlevel(root->left,level-1,b);
            printlevel(root->right,level-1,b);
        }
        else{
            printlevel(root->right,level-1,b);
            printlevel(root->left,level-1,b);
        }
    }
}
void spiral(node* root){
    int h=height(root);
    bool b=false;
    for(int i=0;i<=h;i++){
        printlevel(root,i,b);
        b=!b;
    }
}
int main(){
    node* head=new node('A');
    head->left = new node('B');
    head->right = new node('C');
    head->right->right = new node('G');
    head->right->left = new node('F');
    head->right->left->left = new node('I');
    head->right->left->right = new node('J');
    head->left->left = new node('D');
    head->left->right = new node('E');
    head->left->left->right = new node('H');
    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
    postorder(head);
    cout<<endl;
    levelorder(head);
    cout<<nodes(head)<<endl;
    cout<<finddepth(head)<<endl;
    topview(head);
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };  
    int len = sizeof(in) / sizeof(in[0]);  
    node* root = buildtree(in, pre, 0, len - 1);
    inorder(root);
    cout<<"\n";
    leftview(head);
    cout<<"\n";
    rightview(head);
    cout<<"\n";
    bottomview(head);
    spiral(head);
    return 0;   
}