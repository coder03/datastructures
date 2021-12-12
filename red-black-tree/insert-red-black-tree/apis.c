/* files with all APIs to red-black tree */

#include <stdio.h>
#include <stdlib.h>
#include "insert-red-black-tree.h"

/* read array from stdin and return the pointer to array */
int *read_array_from_stdin(int array[], int array_len);

/* insert array to red-black tree */
void redblack_insert(struct node** , int );

/* read array from stdin and return the pointer to array */
int *read_array_from_stdin(int array[], int array_len) {
        int i;
        array=(int *)malloc(array_len * sizeof(int));
        printf("Enter nodes to be insert\n");
        for (i=0 ; i < array_len; i++)
                scanf("%d", &array[i]);
        printf("in funtion %p\n", array);
        return array;
}

/* insert array to red-black tree */
void redblack_insert(struct node** head, int data){
        struct node* new_node;
        if (head == NULL){
                new_node=(struct node*) malloc(sizeof(struct node));
                new_node->data=data;
                new_node->p = new_node;
                new_node->l = NULL;
                new_node->r = NULL;
                new_node->color = 0;
        }
        (*head)=new_node;
}
