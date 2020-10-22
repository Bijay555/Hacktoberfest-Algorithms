/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void left_boundary(Node* root, vector<int>& v)
{
    if(root)
    {
        if(root->left){
            v.push_back(root->data);
            left_boundary(root->left,v);
        }
        else if(root->right){
            v.push_back(root->data);
            left_boundary(root->right,v);
        }
    }
}

void right_boundary(Node* root, vector<int>& v)
{
    if(root){
        if(root->right){
            right_boundary(root->right,v);
            v.push_back(root->data);
        }
        else if(root->left){
            right_boundary(root->left,v);
            v.push_back(root->data);
        }
    }
}

void leafnodes(Node* root, vector<int>& v)
{
    if(root==NULL)   
        return;
    leafnodes(root->left,v);
    if(root->left==NULL && root->right==NULL)
        v.push_back(root->data);
    leafnodes(root->right,v);
}

vector <int> printBoundary(Node *root)
{
    vector<int>v;
    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
        return v;
    left_boundary(root->left,v);
    leafnodes(root,v);
    right_boundary(root->right,v);
    return v;
}
