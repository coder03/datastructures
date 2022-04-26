/* implementation of heap data structure 
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_HEAP_LEN 100

//int ind=0; // global index

void swap(int *src, int *dest){
    int temp=*src;
    *src=*dest;
    *dest=temp;
}

int * min_heapify(int *array, int len){
    int *heap=(int *)calloc(MAX_HEAP_LEN, sizeof(int));
    heap[0] = len; // heap[0] is meant for lenght of heap
    
    for(int i=1; i<heap[0]+1; i++){ 
        heap[i] = array[i-1]; // array starts form i-1
        int parent = i/2;
        int i_index =i;
        // if new value is less then its parent
        while( (heap[i_index] < heap[parent]) && (parent != 0) ){
            swap(&heap[i_index], &heap[parent]);
            i_index = parent;
            parent = i_index/2;
        }
    }
    return heap;
}
void print_heap(int* heap){
    if(heap[0] <=0 ){
        printf("%s: Heap is empty\n", __func__);
        return;
    }
    printf("Heapify'ed array: ");
    for(int i=1; i<heap[0]+1; i++){
        printf("%d ", heap[i]);
    }
    printf("\nLength of heap = %d\n",heap[0]);
}

void push(int * heapify, int val){
    if(heapify[0] > MAX_HEAP_LEN){
        printf("heap over flow\n");
        exit(0);
    }
    int ind = heapify[0]+1;
    heapify[ind] = val;
    heapify[0]=heapify[0]+1;
    int parent = ind/2;
    while(heapify[ind] < heapify[parent] && parent != 0){
        swap(&heapify[ind], &heapify[parent]);
    }
}

void pop(int *heapify){
    int len = heapify[0];
    if(len<1){
        printf("Cannot pop: Heap is empty\n");
        exit(0);
    }
    heapify[1] = heapify[len];
    heapify[0] = heapify[0]-1;
    heapify[len] = 0;
    int ind = 1;
    int left = ind*2;
    int right = ind*2+1;
    while( (heapify[ind] > heapify[left] || heapify[ind] > heapify[right]) \
          && right < len && left < len){
        if(heapify[ind] > heapify[left]){
            swap(&heapify[ind], &heapify[left]);
            ind=left;
        }else if(heapify[ind] > heapify[right]){
            swap(&heapify[ind], &heapify[right]);
            ind=right;
        }
        left = ind*2;
        right = ind*2+1;
    }
}

int main(void) {
    int array[] = {8,7,2};
    int len = sizeof(array)/sizeof(int); // heap[0] will have lenght of the array
    int *heapify=min_heapify(array, len);
    print_heap(heapify);
    
    push(heapify, 6);
    push(heapify, 1);
    print_heap(heapify);
    pop(heapify); 
    pop(heapify);
    pop(heapify);
    pop(heapify);
    pop(heapify);
    print_heap(heapify);
    return 0; 
}
