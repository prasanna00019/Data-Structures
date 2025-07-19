#include<stdio.h>
#define N 10
//ASCENDING ORDER PRIORITY QUEUE
void enqueue(int queue[],int x,int *front,int *rear){
int pos;
 if(*rear==N-1)
 {
 printf("overflow\n");
 }
 else{
 pos=*rear;
 (*rear)=(*rear)+1;
 while(pos>=0 && queue[pos]>=x){
  queue[pos+1]=queue[pos];
  pos=pos-1;
 }
 queue[pos+1]=x;
 if(*front==-1){
  *front=*front+1;
 }
 }
 
}
void dequeue(int queue[],int *front,int *rear)
{
 if(*front==-1 && *rear==-1)
 {
   printf("Underflow");
 }
 else if(*front==*rear)
 {
  *front=*rear=-1;
 }
 else{
  printf("dequeued %d \n",queue[*front]);
  (*front)++;
 // printf("front %d rear %d ",*front,*rear);
  
   }
}
void peek(int queue[],int *front,int *rear)
{
 if(*front==-1 && *rear==-1)
 {
   printf("Underflow");
 }
 else{
  printf("%d ",queue[*front]);
  }
 }
void display(int queue[],int *front,int *rear){
 int i;
 if(*front==-1 && *rear==-1)
 {
   printf("Underflow");
 }
 else{
  printf("PRIORITY QUEUE \n");
  for(i=(*front);i<=(*rear);i++)
  {
   printf("%d ",queue[i]);
  // printf("\n");
  }
  printf("\n");
  printf("\n");
 }
}
int main(){
 int front=-1;
 int rear=-1;
 int queue[N];
 int value;
 value=5;
 enqueue(queue,value,&front,&rear);
 value=2;
 enqueue(queue,value,&front,&rear);
 value=4;
 enqueue(queue,value,&front,&rear);
 value=3;
 enqueue(queue,value,&front,&rear);
 value=9;
 enqueue(queue,value,&front,&rear);
 value=7;
 enqueue(queue,value,&front,&rear);
 value=1;
 enqueue(queue,value,&front,&rear);
 display(queue,&front,&rear);
 dequeue(queue,&front,&rear);
 display(queue,&front,&rear);
 dequeue(queue,&front,&rear);
 display(queue,&front,&rear);
 dequeue(queue,&front,&rear);
 display(queue,&front,&rear);
 dequeue(queue,&front,&rear);
 display(queue,&front,&rear);
 printf("\n");
}
/*
OUTPUT:
PRIORITY QUEUE 
1 2 3 4 5 7 9 

dequeued 1 
PRIORITY QUEUE 
2 3 4 5 7 9 

dequeued 2 
PRIORITY QUEUE 
3 4 5 7 9 

dequeued 3 
PRIORITY QUEUE 
4 5 7 9 

dequeued 4 
PRIORITY QUEUE 
5 7 9 
*/





