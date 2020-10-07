#include<stdlib.h>
#include<iostream>

using std::cout;
using std::endl;

bool isNull(void*);

class Tree {
	int data;
	Tree *root = NULL, *left, *right;
	
	public:
		//Constructors
		Tree() : Tree(0) {}
		Tree(int data) {
			this->data = data;
			this->left = this->right = NULL;
		}
		
		//Destructor
		~Tree() {
			delete(root);
			delete(left);
			delete(right);
		}
		
		bool insert(int data) {
			// Wrapper function for insert in which the initial tree node is the root itself
			return insert(data, root);
		}
		
		void display() {
			// Wrapper function for display in which the depth defaults to zero
			display(root, 0);
		}
		
		bool isLeaf(Tree *node) {
			// Any given node is said to be a leaf if the node has no children
			return (isNull(node->left) && isNull(node->right));
		}
		
		int getChildren(Tree *node) {
			// Utility function to retrieve the number of childs that this tree possess
			if (isLeaf(node)) return 0;
			else if (!isNull(node->left) && !isNull(node->right)) return 2;
			else return 0;
		}
		
		int getWeight() {
			// Wrapper function for the weight
			int weight = 0;
			return getWeight(&weight, root);
		}
		
		bool isIsomorphicTo(Tree *node_b) {
			// Wrapper function
			return isIsomorphicTo(root, node_b->root);
		}
	private:
		bool insert(int data, Tree *&tree) {
			// Standar insertion algorithm
			Tree *node = new Tree(data);
			if (isNull(tree)) {
				tree = node;
			} else if (data <= tree->data) {
				insert(data, tree->left);
			} else if (data > tree->data) {
				insert(data, tree->right);
			}
			
			return true;
		}
		
		void display(Tree *tree, int depth) {
			// This function displays the nodes in the console
			// in a tree-way based on the depth of the node that goes up for each recursive call
			if (isNull(tree)) {
				return;
			} else {
				display(tree->right, depth + 1);
				for(int i = 0; i < depth; i++) cout << "   ";
				cout << tree->data << endl;
				display(tree->left, depth + 1);
			}
		}
		
		int getWeight(int *weight, Tree *tree) {
			// The weight of a tree is the number of nodes it has
			if(!isNull(tree)) {
				*weight = *weight + 1;
				getWeight(weight, tree->left);
				getWeight(weight, tree->right);
			}
			
			return *weight;
		}
		
		bool isIsomorphicTo(Tree *node_a, Tree *&node_b) {
			/* 
				In this context, two trees are said to be isomorphic if they have the same
			   structure regardless of the value of their respective nodes.
			   The algorithm checks this by traveling both trees in the same direction.
			   If one of the two nodes is null OR the number of direct children differs
			   Then the structure of both trees is not the same and hence are not isomorphic
			   But if the are both null (which means there is a dead-end in both trees)
			   then we can be sure both trees are isomorphic. 
			*/
			if (isNull(node_a) && !isNull(node_b)) {
				return false;
			} else if (!isNull(node_a) && isNull(node_b)) {
				return false;
			} else if (isNull(node_a) && isNull(node_b)) {
				return true;
			} else {
				if (getChildren(node_a) == getChildren(node_b)) {
					return isIsomorphicTo(node_a->left, node_b->left);
					return isIsomorphicTo(node_a->right, node_b->right);
				} else {
					return false;
				}
			}
		}
};


int main(int argc, char **argv) {
	
	// Here we defined a fixed number of nodes to insert in both trees
	// As said earlier, the value of this nodes does not matter
	
	const int n = 7;
	int nodes_tree_a[] = {5, 3, 1, 4, 7, 6, 10};
	int nodes_tree_b[] = {130, 115, 100, 125, 150, 140, 200};
	Tree *tree_a = new Tree(), *tree_b = new Tree();
	
	for (int i = 0; i < n; i++) {
		tree_a->insert(nodes_tree_a[i]);
		tree_b->insert(nodes_tree_b[i]);
	}
	
	// Then we display the trees
	
	cout << "Tree A" << endl << endl;
	tree_a->display();
	cout << endl << endl << "Tree B" << endl << endl;
	tree_b->display();
	cout << endl;
	
	if (tree_a->getWeight() != tree_b->getWeight()) {
		cout << "The weight of both trees are not same. They are not isomorphic.";
	} else {
		if (tree_a->isIsomorphicTo(tree_b)) {
			cout << "The trees are isomorphic";
		} else {
			cout << "The trees are not isomorphic";
		}
	}
	
	return EXIT_SUCCESS;
}

bool isNull(void *ptr) {
	// Utility function to tell wheter a pointer is null or not
	// because of the type of the pointer is void, it can accept any kind of pointer
	return ptr == NULL;
}
