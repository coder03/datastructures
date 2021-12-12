/* header for red-black tree
*/
#include <stdio.h>

/* define structure for insear/deletion nodes */
struct node {
	int data;
	int color; // 1 for red and 0 for black
	struct node *p; // parent
	struct node *l; // left node
	struct node *r; // right node
};

/* read array from stdin and return the pointer to array */
int *read_array_from_stdin(int array[], int array_len);

/* insert array to red-black tree */
void redblack_insert(struct node** head, int data);
