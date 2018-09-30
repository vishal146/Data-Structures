#include<iostream>
#include<stdlib.h>
#include<stack> 
using namespace std; 

struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
struct Node* newNode(int data){
    struct Node* root=(struct Node*)(malloc(sizeof(struct Node)));
    root->left=NULL;
    root->data=data;
    root->right=NULL;
    return(root);
}
/* Iterative function for inorder tree 
traversal */
void inOrder(struct Node *root) 
{ 
    stack <Node*> s; 
    Node *curr = root; 

    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
        curr Node */
        while (curr != NULL) 
        { 
            /* place pointer to a tree node on 
            the stack before traversing 
            the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 

        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 

        cout << curr->data << " "; 

        /* we have visited the node and its left subtree. Now, it's right subtree's turn */
        curr = curr->right; 

    }
} 

int main() 
{ 

    /* Constructed binary tree is 
            1 
            / \ 
        2    3 
        / \ 
    4    5 
    */
    struct Node *root = newNode(1); 
    root->left   = newNode(2); 
    root->right  = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 

    inOrder(root); 
    return 0; 
} 