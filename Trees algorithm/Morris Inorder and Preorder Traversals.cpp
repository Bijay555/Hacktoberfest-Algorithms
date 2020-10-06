#include "../Tree.h"

/**
 * O(N) Time | O(1) Space
 * Every node traversed atmost 3 times
 * Inorder = after we are done with left subtree then we print root->data
 * Preorder = we print root->data first and then go to left subtree
 * We can do reverse inorder traversal also using morris
 */

//In the left subtree of current the rightmost node (whose right is either NULL or current)
Node* getInorderPredecessor(Node* current) {
    Node* predecessor = current->left;
    while (predecessor->right != NULL && predecessor->right != current) {
        predecessor = predecessor->right;
    }
    return predecessor;
}

void morrisInorder(Node* root) {
    Node* current = root;
    while (current != NULL) {
        //If left subtree is null then we can visit this node and go to the right subtree since we have no further use for this node
        if (current->left == NULL) {
            cout << current->data << " ";  //Visit that node
            current = current->right;
        } else {
            Node* predecessor = getInorderPredecessor(current);
            /*
                Need to visit left subtree. 
                So create a link from inorder predecessor to current so that we can visit the current after visiting entire left subtree
            */
            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            }
            //Now the entire left subtree of current node is visited so visit the current node and go to its right subtree
            else if (predecessor->right == current) {
                predecessor->right = NULL;
                cout << current->data << " ";  //Visit that node
                current = current->right;
            }
        }
    }
}

void morrisPreorder(Node* root) {
    Node* current = root;
    while (current != NULL) {
        //If left subtree is null then we can visit this node and go to the right subtree since we have no further use for this node
        if (current->left == NULL) {
            cout << current->data << " ";  //Visit that node
            current = current->right;
        } else {
            Node* predecessor = getInorderPredecessor(current);
            //Left subtree is not visited if pred->right == NULL.
            //The Visit this node & then go to left subtree
            //Create a link from inorder predecessor to current so that we can visit the current after visiting entire left subtree
            if (predecessor->right == NULL) {
                predecessor->right = current;
                cout << current->data << " ";  //Visit that node
                current = current->left;
            }
            //Now the entire left subtree of current is visited, go to its right subtree
            else {
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}

//Unit tests
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    morrisInorder(root);
}
