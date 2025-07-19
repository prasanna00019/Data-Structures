#include<stdio.h>
#include<stdlib.h>
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
int* pop(int stack[],int*size,int*tos)
{
int v;
 int i;
 int *newStack;
 if(*tos==-1)
 {
 printf("Stack Underflow\n");
 }
 if(((*tos)+1) <=((*size)/4)){
  *size=(*size)/2;
  newStack=(int*)malloc((*size)*sizeof(int));
  for(i=0;i<=*tos;i++){
     newStack[i]=stack[i];}
  free(stack);   
  v=newStack[*tos];
  printf("%d\n", v);
  printf("size is %d\n",*size);
  (*tos)--;
  return (newStack);
 
 }
 v=stack[*tos];
 (*tos)--;
 printf("%d\n", v);
 printf("size is %d\n",*size);
 return stack;

}
int* push(int stack[],int*size ,int*tos,int value){
 int i;
 int* newStack;
 if(*tos>=(*size)-1){
   printf("Stack overflow\n");
   *size=(*size)*2;
   newStack=(int*)malloc((*size)*sizeof(int));
   if(newStack==NULL){
       printf("cant increase size\n");
       return(stack);
   }
   printf("allocated stack with double size %d\n",*size);
   printf("\n");
   for(i=0;i<=*tos;i++)
     newStack[i]=stack[i];
   free(stack);
   printf("populated existing elements in new stack\n");
   printf("\n");
   (*tos)++;
   newStack[*tos]=value;
   printf("inserted new element in stack\n");
   return(newStack);
}
 (*tos)++;
 stack[*tos]=value;
 printf("inserted new element in stack\n");
 return(stack);
}
void display(int stack[],int* tos){
  int i;
  printf("STACK CONTENT : ");
  for(i=0;i<=*tos;i++) 
     printf("%d ",stack[i]);
  printf("\n");   
}
int main(){
  int *stack;
  int size=1;
  int tos=-1;
  int value;
  int i;
  stack=(int*)malloc(size*sizeof(int));
  value=300;
  stack=push(stack,&size,&tos,value);
  display(stack,&tos);
  value=575;
  stack=push(stack,&size,&tos,value);
  display(stack,&tos); 
  value=725;
  stack=push(stack,&size,&tos,value);
  display(stack,&tos);
  value=1125;
  stack=push(stack,&size,&tos,value);
  display(stack,&tos);
  value=1575;
  stack=push(stack,&size,&tos, value);
  display(stack,&tos);
  value=6625;
  stack=push(stack,&size,&tos,value);
  display(stack,&tos);
  value=8870;
  stack=push(stack,&size,&tos,value);
  display(stack,&tos);
  value=9980;
  stack=push(stack,&size,&tos,value);
  display(stack,&tos);
  value=readkth(stack,tos,3);
  value=read(stack,&tos);
  printf("%d \n",value);
  stack=pop(stack,&size,&tos);
  display(stack,&tos);
  stack=pop(stack,&size,&tos);
  display(stack,&tos);
  stack=pop(stack,&size,&tos);
  display(stack,&tos);
  stack=pop(stack,&size,&tos);
  display(stack,&tos);
  stack=pop(stack,&size,&tos);
  display(stack,&tos);
  stack=pop(stack,&size,&tos);
  display(stack,&tos);
  stack=pop(stack,&size,&tos);
  display(stack,&tos);
  return 0;
}
/*
OUTPUT OF PROGRAM :
inserted new element in stack
STACK CONTENT : 300 
Stack overflow
allocated stack with double size 2

populated existing elements in new stack

inserted new element in stack
STACK CONTENT : 300 575 
Stack overflow
allocated stack with double size 4

populated existing elements in new stack

inserted new element in stack
STACK CONTENT : 300 575 725 
inserted new element in stack
STACK CONTENT : 300 575 725 1125 
Stack overflow
allocated stack with double size 8

populated existing elements in new stack

inserted new element in stack
STACK CONTENT : 300 575 725 1125 1575 
inserted new element in stack
STACK CONTENT : 300 575 725 1125 1575 6625 
inserted new element in stack
STACK CONTENT : 300 575 725 1125 1575 6625 8870 
inserted new element in stack
STACK CONTENT : 300 575 725 1125 1575 6625 8870 9980 
9980 
9980
size is 8
STACK CONTENT : 300 575 725 1125 1575 6625 8870 
8870
size is 8
STACK CONTENT : 300 575 725 1125 1575 6625 
6625
size is 8
STACK CONTENT : 300 575 725 1125 1575 
1575
size is 8
STACK CONTENT : 300 575 725 1125 
1125
size is 8
STACK CONTENT : 300 575 725 
725
size is 8
STACK CONTENT : 300 575 
575
size is 4
STACK CONTENT : 300 



*/
