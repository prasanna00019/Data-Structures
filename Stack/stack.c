#include<stdio.h>
#define N 10
int readkth(int stack[], int tos, int k) {
    int v; 
    if (k > tos || k < 0) {
        printf("Invalid k value\n");
        return -1; 
    }
    v = stack[tos - k];
    return v;
}
int read(int stack[], int *tos){
 int v;
 v=stack[*tos];
 return v;
}
int pop(int stack[],int*tos)
{
 int v;
 if(*tos==-1)
 {
 printf("Stack Underflow\n");
 }
 
 v=stack[*tos];
 (*tos)--;
 return v;

}
void push(int stack[],int*tos,int value){
 if(*tos>=N-1){
   printf("Stack overflow\n");
   return;
   }
 (*tos)++;
 stack[*tos]=value;
 return;
}
void display(int stack[],int* tos){
  int i;
  printf("STACK CONTENT : ");
  for(i=0;i<=*tos;i++) 
     printf("%d ",stack[i]);
  printf("\n");   
}
int main(){
  int stack[N];
  int tos=-1;
  int value;
  int i;
  value=112;
  push(stack,&tos,value);
  display(stack,&tos);
  value=224;
  push(stack,&tos,value);
  display(stack,&tos);  
  value=336;
  push(stack,&tos,value);
  display(stack,&tos);
  value=666;
  push(stack,&tos,value);
  display(stack,&tos);
  value=15;
  push(stack,&tos,value);
  display(stack,&tos);
  value=700;
  display(stack,&tos);
  value=156;
  push(stack,&tos,value);
  value=765;
  push(stack,&tos,value);
  display(stack,&tos);  
  value=pop(stack,&tos);
  printf("popped %d\n",value);
  value=pop(stack,&tos);
  printf("popped %d\n",value);
  value=read(stack,&tos);
  printf("After peep  %d",value);
  printf("\n");
  value=readkth(stack,tos,2);
  printf("%d ",value);
  printf("\n");
  return 0;
}
/*
OUTPUT:
STACK CONTENT : 112 
STACK CONTENT : 112 224 
STACK CONTENT : 112 224 336 
STACK CONTENT : 112 224 336 666 
STACK CONTENT : 112 224 336 666 15 
STACK CONTENT : 112 224 336 666 15 
STACK CONTENT : 112 224 336 666 15 156 765 
popped 765
popped 156
After peep  15
336 
*/




