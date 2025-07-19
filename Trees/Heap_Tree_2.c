#include<stdio.h>
#include<stdlib.h>
//DYNAMIC SIZE HEAP ARRAY IMPLEMENTATION
int* insert(int heap[],int v,int *current,int *size){
int i,j;
int* newheap;
if(*current>=(*size)){
 printf("THE HEAP IS FULL \n");
 (*size)=(*size)*2;
  newheap=(int*)malloc((*size)*sizeof(int));
  if(newheap==NULL){
   printf("CAN'T INCREASE SIZE \n");
   return heap;
  }
  printf("ALLOCATED HEAP WITH DOUBLE SIZE  %d\n",*size);
   printf("\n");
  for(i=0;i<(*current);i++){
   newheap[i]=heap[i];
  }
  free(heap);
   printf("POPULATED EXISTING ELEMENTS IN NEW HEAP \n");
   printf("NOW THE HEAP IS\n");
  j=*current;
while(j>0 && v>newheap[(j-1)/2]){
newheap[j]=newheap[(j-1)/2];
j=(j-1)/2;
}
newheap[j]=v;
(*current)++;
return (newheap);
}
 
else{
int i;
i=*current;
while(i>0 && v>heap[(i-1)/2]){
heap[i]=heap[(i-1)/2];
i=(i-1)/2;
}
heap[i]=v;
(*current)++;
return heap;
}
}
int* delete(int heap[], int *current,int *size) {
    int* newheap;
    int i;
    //printf("%d \n",*current);
    if (*current == 0) {
        printf("LIST IS EMPTY \n");
        return NULL;  
    }
    if((*current)<=((*size)/4)){
    *size=(*size)/2;
    newheap=(int*)malloc((*size)*sizeof(int));
    for(i=0;i<(*current);i++){
     newheap[i]=heap[i];
    }

    printf("HEAP SIZE IS %d\n",*size);
    printf("\n");
    free(heap);
    int item = newheap[0];
    newheap[0] = newheap[(*current) - 1];
    (*current)--;
    int parent = 0;
    int child = 1;
    while (child < (*current)) {
        if (child < (*current) - 1 && newheap[child] < newheap[child + 1]) {
            child = child + 1;
        }
        if (newheap[parent] >= newheap[child]) {
            break;
        }
        int temp = newheap[parent];
        newheap[parent] = newheap[child];
        newheap[child] = temp;
        parent = child;
        child = 2 * parent + 1;
    }
    return newheap;
    }
    printf("HEAP SIZE IS %d\n",*size);
    int item = heap[0];
    heap[0] = heap[(*current) - 1];
    (*current)--;
    int parent = 0;
    int child = 1;
    while (child < (*current)) {
        if (child < (*current) - 1 && heap[child] < heap[child + 1]) {
            child = child + 1;
        }
        if (heap[parent] >= heap[child]) {
            break;
        }
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        parent = child;
        child = 2 * parent + 1;
    }
 return heap;
}

void display(int heap[],int current){
int i;
for(i=0;i<current;i++){
 printf("%d ",heap[i]);
}
printf("\n");
printf("\n");
}
int main()
{
int *heap;
int size=1;;
heap=(int*)malloc(size*sizeof(int));
int current=0;
heap=insert(heap,90,&current,&size);
display(heap,current);
heap=insert(heap,56,&current,&size);
display(heap,current);
heap=insert(heap,32,&current,&size);
display(heap,current);
heap=insert(heap,30,&current,&size);
display(heap,current);
heap=insert(heap,25,&current,&size);
display(heap,current);
heap=insert(heap,10,&current,&size);
display(heap,current);
heap=insert(heap,7,&current,&size);
display(heap,current);
heap=insert(heap,6,&current,&size);
display(heap,current);
heap=insert(heap,5,&current,&size);
display(heap,current);
heap=delete(heap,&current,&size);
printf("AFTER DELETE OPERATION \n");
display(heap,current);
heap=delete(heap,&current,&size);
printf("AFTER DELETE OPERATION \n");
display(heap,current);
heap=delete(heap,&current,&size);
printf("AFTER DELETE OPERATION \n");
display(heap,current);
heap=delete(heap,&current,&size);
printf("AFTER DELETE OPERATION \n");
display(heap,current);
heap=delete(heap,&current,&size);
printf("AFTER DELETE OPERATION \n");
display(heap,current);
heap=delete(heap,&current,&size);
printf("AFTER DELETE OPERATION \n");
display(heap,current);
}
/*
OUTPUT OF THE PROGRAM 
90 

THE HEAP IS FULL 
ALLOCATED HEAP WITH DOUBLE SIZE  2

POPULATED EXISTING ELEMENTS IN NEW HEAP 
NOW THE HEAP IS
90 56 

THE HEAP IS FULL 
ALLOCATED HEAP WITH DOUBLE SIZE  4

POPULATED EXISTING ELEMENTS IN NEW HEAP 
NOW THE HEAP IS
90 56 32 

90 56 32 30 

THE HEAP IS FULL 
ALLOCATED HEAP WITH DOUBLE SIZE  8

POPULATED EXISTING ELEMENTS IN NEW HEAP 
NOW THE HEAP IS
90 56 32 30 25 

90 56 32 30 25 10 

90 56 32 30 25 10 7 

90 56 32 30 25 10 7 6 

THE HEAP IS FULL 
ALLOCATED HEAP WITH DOUBLE SIZE  16

POPULATED EXISTING ELEMENTS IN NEW HEAP 
NOW THE HEAP IS
90 56 32 30 25 10 7 6 5 

HEAP SIZE IS 16
AFTER DELETE OPERATION 
56 30 32 6 25 10 7 5 

HEAP SIZE IS 16
AFTER DELETE OPERATION 
32 30 10 6 25 5 7 

HEAP SIZE IS 16
AFTER DELETE OPERATION 
30 25 10 6 7 5 

HEAP SIZE IS 16
AFTER DELETE OPERATION 
25 7 10 6 5 

HEAP SIZE IS 16
AFTER DELETE OPERATION 
10 7 5 6 

HEAP SIZE IS 8

AFTER DELETE OPERATION 
7 6 5 

*/  


 
