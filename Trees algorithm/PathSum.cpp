//Sejal Chowdhury
//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

//Example :

//Given the below binary tree and sum = 22,

  //            5
    //         / \
      //      4   8
        //   /   / \
         // 11  13  4
        // /  \      \
       // 7    2      1
//return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

//Return 0 / 1 ( 0 for false, 1 for true ) for this problem

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Recursive Function to find path sum

void recur(TreeNode* A, int B, vector<int> curr, vector<vector<int>> &res)
{
  //If A is NULL
    if(!A)
    {
        return;
    }
    
    //If Left and right side of the tree are not NULL
    if(!A->left && !A->right)
    {
        curr.push_back(A->val);
    }
    
    // Target-Root value to find the path sum
    if(B-A->val == 0)
    {
        res.push_back(curr);
    }
    
    //Push the value in the vector and recur
    curr.push_back(A->val);
    recur(A->left,B-A->val,curr,res);
    recur(A->right,B-A->val,curr,res);
}

int Solution::hasPathSum(TreeNode* A, int B) 
{
    vector<vector<int>>res;
    vector<int> curr;
    recur(A,B,curr,res);
    cout<<res;
}
