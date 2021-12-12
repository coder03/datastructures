#include <stdio.h>
#include <stdlib.h>
// All functions in this header
#include "insert-red-black-tree.h" 

#define DEBUG_ENABLE 0 

int main()
{
	struct node *root=NULL;
	struct node *temp=NULL;
	
	/* start: Get input from stdin to insert as tree node */
	int *array=NULL;
	int array_len;
	printf("Enter the length of array\n");
	scanf("%d", &array_len);
	array=read_array_from_stdin(array,array_len);
	/* end: Get input from stdin to insert as tree node */
#ifdef DEBUG_ENABLE
	int i;
	for (i=0; i< array_len; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");
#endif
	redblack_insert(&root, 10);
	return 0;
}
