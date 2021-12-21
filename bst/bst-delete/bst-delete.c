/* program to delete a node given a key.
Here we use insert an element, inorder traversel, find inorder predesisor
*/

# include <stdio.h>
# include <stdlib.h>

/* allocate new node */ 
struct node * allocnode(int);
/* insert a new node into bst */
struct node * insert(struct node* , int);
/* inorder travere */
void inorder(struct node*);

/* struct to hold nodes of BST */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* allocate new node */
struct node * allocnode(int key){
    struct node *newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* insert a new node into bst */
struct node * insert(struct node* root, int key) {
    if ( root == NULL) {
    	return allocnode(key);
    }
    if (key > root->data)
	root->right = insert(root->right, key);
    else
	root->left = insert(root->left, key);	
    return root;
}

/* inorder travere */
void inorder(struct node* root){
    if (root == NULL)
	return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    struct node *root;
    root=insert(root, 1);
    root=insert(root, 2);
    root=insert(root, 3);
    root=insert(root, 4);
    root=insert(root, 5);
    root=insert(root, 6);
    root=insert(root, 7);
    inorder(root);

    return 0;
}
