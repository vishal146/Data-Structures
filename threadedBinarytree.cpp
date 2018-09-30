#include <iostream> 
# include<stdlib.h>
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *left, *right;
	bool  rightThread;
}; 
struct Node* newNode(int data,bool f){
	struct Node* root=(struct Node*)(malloc(sizeof(struct Node)));
	root->left=NULL;
	root->data=data;
	root->right=NULL;
	root->rightThread=f;
	return(root);
}
struct Node* leftMost(struct Node *n) 
{ 
	if (n == NULL) 
	return NULL; 

	while (n->left != NULL) 
		n = n->left; 

	return n; 
} 


void inOrder(struct Node *root) 
{ 
	struct Node *cur = leftMost(root); 
	while (cur != NULL) 
	{ 
		printf("%d ", cur->data); 

/* If this node is a thread node
 then go to inorder successor */
		if (cur->rightThread) 
			cur = cur->right; 
		else 
/* Else go to the leftmost child 
in right subtree */
		cur = leftMost(cur->right); 
	} 
}
int main() 
{ 
	struct Node *root = newNode(1,0); 
	root->left			 = newNode(2,0); 
	root->right		 = newNode(3,0); 
	root->left->left	 = newNode(4,1);
	root->left->right = newNode(5,1);
	/* Constructed binary tree is 
			1 
			/ \ 
		2	 3 
		/ \ 
	4	 5 
	*/
	root->left->left->right=root->left;
	root->left->right->right=root;
	 
	cout << "\nInorder traversal of binary tree is \n"; 
	inOrder(root); 
	return 0; 
} 
