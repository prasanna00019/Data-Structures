#include<stdio.h>
#define N 10
void insert(int queue[],int *f,int *r,int value){
 if(*r>=N-1){
  printf("QUEUE IS FULL \n");
 }
 else if(*f==-1 &&*r==-1){
   *f=*r=0;
   queue[*r]=value;
 }
 else{
    (*r)++;
    queue[*r]=value;
 }
}
int delete(int queue[],int *f,int *r){
   int v;
   if(*f==-1 && *r==-1){
    printf("QUEUE IS EMPTY \n");
    return -1;
   }
   v=queue[*f];
   if(*f==*r){
    *f=*r=-1;
   }
   else{
    (*f)++;
   }
   printf("DELETED ELEMENT IS %d \n",v);
   printf("AFTER DELETION THE QUEUE IS \n");
   //printf("\n");
   return v;
}
void display(int queue[],int *f,int *r){
 int i;
 if(*f==-1 && *r==-1)
 {
   printf("QUEUE IS EMPTY");
 }
 else{
  for(i=(*f);i<=(*r);i++)
  {
   printf("%d ",queue[i]);
  }
  printf("\n");
  printf("\n");
 }
}
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
v=669;
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
delete(queue,&f,&r);
display(queue,&f,&r);
}

/*
OUTPUT:
THE ORIGINAL QUEUE 
112 224 336 448 556 669 

DELETED ELEMENT IS 112 
AFTER DELETION THE QUEUE IS 
224 336 448 556 669 

DELETED ELEMENT IS 224 
AFTER DELETION THE QUEUE IS 
336 448 556 669 

DELETED ELEMENT IS 336 
AFTER DELETION THE QUEUE IS 
448 556 669 

DELETED ELEMENT IS 448 
AFTER DELETION THE QUEUE IS 
556 669 

DELETED ELEMENT IS 556 
AFTER DELETION THE QUEUE IS 
669 


*/
