/*
Given a binary tree, find out if the tree can be folded or not.
A tree can be folded if the left and right subtrees of the tree are structure-wise mirror images of each other

Input:
       10
     /     \
   7      15
     \     /
    9  11
Output: Can be folded

Input:
        10
       /  \
     7   15
   /    /
5   11
Output: Cannot be folded

Time complexity: O(N), Visiting all the nodes of the tree of size N.
Auxiliary Space: O(N), If stack space is considered else O(1)s

*/
// C++ program to check foldable binary tree
#include <bits/stdc++.h>
using namespace std;

/* You would want to remove below
3 lines if your compiler supports
bool, true and false */

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

/* converts a tree to its mirror image */
void mirror(node* node);

/* returns true if structure of
two trees a and b is same only
structure is considered for comparison, not data! */
bool isStructSame(node* a, node* b);

/* Returns true if the given tree is foldable */
bool isFoldable(node* root)
{
	bool res;

	/* base case */
	if (root == NULL)
		return true;

	/* convert left subtree to its mirror */
	mirror(root->left);

	/* Compare the structures of the
	right subtree and mirrored
	left subtree */
	res = isStructSame(root->left, root->right);

	/* Get the original tree back */
	mirror(root->left);

	return res;
}

bool isStructSame(node* a, node* b)
{
	if (a == NULL && b == NULL) {
		return true;
	}
	if (a != NULL && b != NULL
		&& isStructSame(a->left, b->left)
		&& isStructSame(a->right, b->right)) {
		return true;
	}

	return false;
}

/* UTILITY FUNCTIONS */
/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.
	See https:// www.geeksforgeeks.org/?p=662 for details */
void mirror(node* Node)
{
	if (Node == NULL)
		return;
	else {
		node* temp;

		/* do the subtrees */
		mirror(Node->left);
		mirror(Node->right);

		/* swap the pointers in this node */
		temp = Node->left;
		Node->left = Node->right;
		Node->right = temp;
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* Driver program to test mirror() */
int main(void)
{
	/* The constructed binary tree is
			1
		/ \
		2 3
		\ /
		4 5
	*/
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);

	if (isFoldable(root) == 1) {
		cout << "tree is foldable";
	}
	else {
		cout << "\ntree is not foldable";
	}
	return 0;
}
/*

Time Complexity: O(N), Visiting every node of the tree of size N.
Auxiliary Space: O(N), If stack space is considered

#include <bits/stdc++.h>
using namespace std;

/* You would want to remove below 3 lines if your compiler
supports bool, true and false */

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

/* A utility function that checks
if trees with roots as n1 and n2
are mirror of each other */
bool IsFoldableUtil(node* n1, node* n2);

/* Returns true if the given tree can be folded */
bool IsFoldable(node* root)
{
	if (root == NULL) {
		return true;
	}

	return IsFoldableUtil(root->left, root->right);
}

/* A utility function that checks
if trees with roots as n1 and n2
are mirror of each other */
bool IsFoldableUtil(node* n1, node* n2)
{
	/* If both left and right subtrees are NULL,
	then return true */
	if (n1 == NULL && n2 == NULL) {
		return true;
	}

	/* If one of the trees is NULL and other is not,
	then return false */
	if (n1 == NULL || n2 == NULL) {
		return false;
	}

	/* Otherwise check if left and right subtrees are
	mirrors of their counterparts */
	return IsFoldableUtil(n1->left, n2->right)
		&& IsFoldableUtil(n1->right, n2->left);
}

/*UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* Driver code */
int main(void)
{
	/* The constructed binary tree is
		1
		/ \
		2 3
		\ /
		4 5
	*/
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);

	if (IsFoldable(root) == true) {
		cout << "tree is foldable";
	}
	else {
		cout << "tree is not foldable";
	}

	return 0;
}

// This is code is contributed by rathbhupendra


*/

