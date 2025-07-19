#include<stdio.h>
#define N 5
void insert(int queue[],int *f,int *r,int value){

if(((*r)+1)%N==*f){
    printf("QUEUE IS FULL\n");
 }
if(*f==-1){
 *f=0;
} 
(*r)=((*r)+1)%N;
queue[*r]=value;
//printf("%d HEY\n",queue[*r]);
printf("front %d rear %d \n",*f,*r);
printf("\n");
 
}

void delete(int queue[],int *f,int *r){
   int v;
    if(*f==-1){
    printf("QUEUE IS EMPTY \n");
   }
   v=queue[*f];
   if(*f==*r)
    {
    *f=*r=-1;
    }
    printf("\n");
    printf("dequeued %d \n",queue[*f]);
    *f=((*f)+1)%N;
    printf("front %d rear %d \n",*f,*r);
}
void display(int queue[],int *f,int *r){
 int i;
 
 if(*f==-1 && *r==-1)
 {
   printf("Underflow");
 }
 else{
  printf("QUEUE IS \n");
  i=*f;
  while(i!=*r)
  {
   printf("%d ",queue[i]);
   i=(i+1)%N;
  }
 printf("%d ",queue[*r]);
 printf("\n");
 } }

int main(){
int queue[N];
int f=-1;
int r=-1;
int v;
v=112;
insert(queue,&f,&r,v);
v=224;
insert(queue,&f,&r,v);
v=336;
insert(queue,&f,&r,v);
v=448;
insert(queue,&f,&r,v);
v=556;
insert(queue,&f,&r,v);
printf("THE ORIGINAL QUEUE \n");
display(queue,&f,&r);
delete(queue,&f,&r);
display(queue,&f,&r);
delete(queue,&f,&r);
display(queue,&f,&r);
delete(queue,&f,&r);
display(queue,&f,&r);
delete(queue,&f,&r);
display(queue,&f,&r);
v=1050;
insert(queue,&f,&r,v);
display(queue,&f,&r);
v=2080;
insert(queue,&f,&r,v);
display(queue,&f,&r);
}
/*
OUTPUT :
front 0 rear 0 

front 0 rear 1 

front 0 rear 2 

front 0 rear 3 

front 0 rear 4 

THE ORIGINAL QUEUE 
QUEUE IS 
112 224 336 448 556 

dequeued 112 
front 1 rear 4 
QUEUE IS 
224 336 448 556 

dequeued 224 
front 2 rear 4 
QUEUE IS 
336 448 556 

dequeued 336 
front 3 rear 4 
QUEUE IS 
448 556 

dequeued 448 
front 4 rear 4 
QUEUE IS 
556 
front 4 rear 0 

QUEUE IS 
556 1050 
front 4 rear 1 

QUEUE IS 
556 1050 2080 
*/




