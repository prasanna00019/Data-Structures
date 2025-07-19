#include<stdio.h>
//FIXED SIZE HEAP ARRAY IMPLEMENTATION
void insert(int heap[],int v,int *current,int max){
if(*current>=max){
 printf("THE HEAP IS FULL \n");
}
int i;
i=*current;
while(i>0 && v>heap[(i-1)/2]){
heap[i]=heap[(i-1)/2];
i=(i-1)/2;
}
heap[i]=v;
(*current)++;
}
int delete(int heap[], int *current, int max) {
    if (*current == 0) {
        printf("LIST IS EMPTY \n");
        return -1;  
    }
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
 return item;
}

void display(int heap[],int current){
int i;
if(current==0){
printf("LIST IS EMPTY\n");
}
else{
for(i=0;i<current;i++){
 printf("%d ",heap[i]);
}
printf("\n");
}
}
int main()
{
const int max=50;
int heap[50],v;
int current=0;
insert(heap,26,&current,max);
insert(heap,5,&current,max);
insert(heap,77,&current,max);
insert(heap,1,&current,max);
insert(heap,61,&current,max);
insert(heap,11,&current,max);
insert(heap,59,&current,max);
insert(heap,15,&current,max);
insert(heap,48,&current,max);
insert(heap,19,&current,max);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
v=delete(heap,&current,max);
printf("DELETED %d\n",v);
display(heap,current);
}  

/*
OUTPUT OF THE RUN PROGRAM 
77 61 59 48 19 11 26 1 15 5 
DELETED 77
61 48 59 15 19 11 26 1 5 
DELETED 61
59 48 26 15 19 11 5 1 
DELETED 59
48 19 26 15 1 11 5 
DELETED 48
26 19 11 15 1 5 
DELETED 26
19 15 11 5 1 
DELETED 19
15 5 11 1 
DELETED 15
11 5 1 
DELETED 11
5 1 
DELETED 5
1 
DELETED 1
LIST IS EMPTY
*/


 
