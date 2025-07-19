#include<stdio.h>
#include<stdlib.h>
#define N 100
/*
IN THIS PROGRAM WE TAKE POLYNOMIAL 1 & POLYNOMIAL 2 . WE TAKE EACH INDIVIDUAL POLYNOMIAL OF POLYNOMIAL 1 & MULTIPLY IT WITH
POLYNOMIAL 2 ANS STORE THE RESULT IN A STACK OF LINKED LISTS, LIKE THIS WE KEEP MULTIPLYING EACH ELEMENT OF POLY1 AND WE GET A STACK .
NOW TO ADD ALL OF THEM , WE POP 2 LINKED LISTS(POLYNOMIALS) AND ADD THEM, THEN WE PUSH THE ANSWER TO THE TOP OF STACK
THEN LIKE THIS WE CONTINUE. FINALLY AFTER ALL ADDITIONS ARE OVER , THE TOP OF THE STACK, CONTAINS THE FINAL ANSWER OF THE MULTIPLICATION
THE 2 POLYNOMIALS BELOW IT ARE THE ORIGINAL POLYNOMIALS WE WANTED TO MULTIPLY 
*/
struct polynode {
    int c;  // c for coefficient
    int p;  // p for power
    struct polynode* link;
};
struct polynode* insert_order(struct polynode* head, int c, int p) {
    struct polynode* newnode, *temp;
    newnode = (struct polynode*)malloc(sizeof(struct polynode));
    newnode->c = c;
    newnode->p = p;
   if (head == NULL || p < head->p) {
        newnode->link = head;
        head = newnode;
        return newnode;
    } else {
        temp = head;
        while (temp->link != NULL && temp->link->p < p) {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
        return head;
    }
}
struct polynode* add(struct polynode* poly1, struct polynode* poly2) {
    struct polynode *headr=NULL,*l;
    l=headr;
    while(poly1!=NULL && poly2!=NULL){
      struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
     if (poly1->p<poly2->p){
        newnode->c = poly1->c;
        newnode->p = poly1->p;
       if(headr==NULL){
        headr=newnode;
        l=newnode;
       }
       else{
        l->link=newnode;
        l=newnode;
       }
       poly1=poly1->link;
       }
       else if(poly1->p>poly2->p){
       newnode->c = poly2->c;
       newnode->p = poly2->p;
          if(headr==NULL){
        headr=newnode;
        l=newnode;
       }
       else{
        l->link=newnode;
        l=newnode;
       }
       poly2=poly2->link;
     //  printf("%d \n",l->p);
       }
        else{ 
        newnode->c = poly1->c + poly2->c;
        newnode->p = poly1->p;
        poly1 = poly1->link;
        poly2 = poly2->link;
      
        if(headr==NULL){
        headr=newnode;
        l=newnode;
         //WHEN ADDING ON FIRST NODE , MAKE SURE TO UPDATE HEAD TO TEMP;
        }
        else{
         l->link=newnode;
         l=newnode;
        }
       }
   }
   while (poly2 != NULL) {
    struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
    newnode->c = poly2->c;
    newnode->p = poly2->p;
    newnode->link=NULL;
        if (headr == NULL) {
            headr =newnode;
            l = newnode;
        } else {
            l->link =newnode;
            l = newnode;
        }
      poly2 = poly2->link;
    }
    while (poly1 != NULL) {
    struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
    newnode->c = poly1->c;
    newnode->p = poly1->p;
    newnode->link=NULL;
         if (headr == NULL) {
            headr = newnode;
            l =newnode;
        } else {
            l->link = newnode;
            l = newnode;
        }
     poly1 = poly1->link;
}
return headr;
}
struct polynode* pop(struct polynode* stack[],int *tos){
  struct polynode* v;
  if((*tos)==-1){
    printf("UNDERFLOW \n");
  }
  v=stack[*tos];
   struct polynode* poly = stack[*tos];
       printf("POPPED POLY %d: ", *tos);
         printf("[");
        while (poly != NULL) {
            printf("(%dX^%d)+ ", poly->c, poly->p);
            poly = poly->link;
        }
        printf("](POPPED FROM PREVIOUS STACK)");
        printf("\n");
  (*tos)--;
  return v;
}
void push(struct polynode* stack[],int *tos,struct polynode* poly){
  int i;
  if((*tos)>=N-1){
   printf("Stack overflow");
  }
  (*tos)++;
  stack[*tos]=poly;
  }

int len(struct polynode* poly){
 struct polynode* temp=poly;
 int c=0;
 while(temp!=NULL){
  temp=temp->link;
  c+=1;
 }
 return c;
}
void display_stack(struct polynode* stack[], int *tos) {
    if (*tos == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("STACK CONTENT:\n");
    for (int i = *tos; i >= 0; i--) {
        struct polynode* poly = stack[i];
        printf("POLY %d: ", i);
         printf("[");
        while (poly != NULL) {
            printf("(%dX^%d)+ ", poly->c, poly->p);
            poly = poly->link;
        }
        if(i==*tos && i>1 && i!=(1+len(stack[0]))){
         printf("](AFTER ADDITION OF 2 POPPED LISTS)");
        printf("\n");
        }
        if(i==0){
        printf("](POLYNOMIAL 1)");
        printf("\n");
        }
        if(i==1){
         printf("](POLYNOMIAL 2)");
        printf("\n");
        }
        if(i==(1+len(stack[0]))){
         printf("]");
         printf("\n");
        }
        else if(i!=1 && i!=0 && i!=*tos){
        printf("]");
        printf("\n");}
    }
    printf("\n");
}
struct polynode*  multiply(struct polynode* stack[],int *tos){
  struct polynode* op1,*op2,*ans,*ans2=NULL;
 // struct polynode* ans=(struct polynode*)malloc(sizeof(struct polynode));
  int i,j,c,p;
  struct polynode* ptr1,*ptr2;
  ptr1=stack[0];ptr2=stack[1];
   while(ptr1!=NULL){
      while(ptr2!=NULL){
        c = ptr1->c * ptr2->c;
        p = ptr1->p + ptr2->p;
        ans2=insert_order(ans2,c,p);
        ptr2=ptr2->link;
       }
         push(stack,tos,ans2);
       
         ans2=NULL;
      ptr2=stack[1];
   ptr1=ptr1->link;
}
  display_stack(stack,tos);
while(*tos!=2){
  op1=pop(stack,tos);
  op2=pop(stack,tos);
  ans=add(op1,op2);
  push(stack,tos,ans);
  printf("AFTER ADDITION OF ABOVE POPPED LINKED LIST, NEW STACK\n");
  display_stack(stack,tos);
 }
 printf("AFTER MULTIPLICATION OF TWO POLYNOMIALS(RESULT IS ON TOP OF PREVIOUS STACK) : \n");
 return stack[2];
}

void display(struct polynode* head) {
    struct polynode* temp;
    temp = head;
    while (temp != NULL) {
        if((temp->c==0 && temp->p==0)){
          printf(" +");
        }
       
       else if(temp->c!=0 && temp->p==0){
        printf("%d+", temp->c);
       // temp = temp->link;
        }
       else if(temp->c==0 && temp->p!=0){
          printf(" ");
          // temp = temp->link;
        }
        else{
        printf(" (%dX^%d)+",temp->c,temp->p);
        }
        temp=temp->link;
    }
    printf("\n");
    printf("\n");
}
int main(){
  struct polynode* stack[N];
  int tos=-1;
  struct polynode* head1 = NULL;
    struct polynode* head2 = NULL;
    struct polynode* headr = NULL;
    struct polynode* head3=NULL;
    struct polynode *h=NULL;
    int p,c,v;
c=1;p=2;
head1=insert_order(head1,c,p);
c=1;p=1;
head1=insert_order(head1,c,p);
c=2,p=0;
head1=insert_order(head1,c,p);
c=1;p=3;
head2=insert_order(head2,c,p);
c=1;p=4;
head2=insert_order(head2,c,p);
c=2,p=1;
head2=insert_order(head2,c,p);
c=1;p=3;
head3=insert_order(head3,c,p);
c=1;p=4;
head3=insert_order(head3,c,p);
c=2,p=1;
head3=insert_order(head3,c,p);
push(stack,&tos,head1);
push(stack,&tos,head2);
//push(stack,&tos,head3);
display_stack(stack,&tos);
headr=multiply(stack,&tos);
display(headr);
}
/*
OUTPUT
STACK CONTENT:
POLY 1: [(2X^1)+ (1X^3)+ (1X^4)+ ](POLYNOMIAL 2)
POLY 0: [(2X^0)+ (1X^1)+ (1X^2)+ ](POLYNOMIAL 1)

STACK CONTENT:
POLY 4: [(2X^3)+ (1X^5)+ (1X^6)+ ]
POLY 3: [(2X^2)+ (1X^4)+ (1X^5)+ ]
POLY 2: [(4X^1)+ (2X^3)+ (2X^4)+ ]
POLY 1: [(2X^1)+ (1X^3)+ (1X^4)+ ](POLYNOMIAL 2)
POLY 0: [(2X^0)+ (1X^1)+ (1X^2)+ ](POLYNOMIAL 1)

POPPED POLY 4: [(2X^3)+ (1X^5)+ (1X^6)+ ](POPPED FROM PREVIOUS STACK)
POPPED POLY 3: [(2X^2)+ (1X^4)+ (1X^5)+ ](POPPED FROM PREVIOUS STACK)
AFTER ADDITION OF ABOVE POPPED LINKED LIST, NEW STACK
STACK CONTENT:
POLY 3: [(2X^2)+ (2X^3)+ (1X^4)+ (2X^5)+ (1X^6)+ ](AFTER ADDITION OF 2 POPPED LISTS)
POLY 2: [(4X^1)+ (2X^3)+ (2X^4)+ ]
POLY 1: [(2X^1)+ (1X^3)+ (1X^4)+ ](POLYNOMIAL 2)
POLY 0: [(2X^0)+ (1X^1)+ (1X^2)+ ](POLYNOMIAL 1)

POPPED POLY 3: [(2X^2)+ (2X^3)+ (1X^4)+ (2X^5)+ (1X^6)+ ](POPPED FROM PREVIOUS STACK)
POPPED POLY 2: [(4X^1)+ (2X^3)+ (2X^4)+ ](POPPED FROM PREVIOUS STACK)
AFTER ADDITION OF ABOVE POPPED LINKED LIST, NEW STACK
STACK CONTENT:
POLY 2: [(4X^1)+ (2X^2)+ (4X^3)+ (3X^4)+ (2X^5)+ (1X^6)+ ](AFTER ADDITION OF 2 POPPED LISTS)
POLY 1: [(2X^1)+ (1X^3)+ (1X^4)+ ](POLYNOMIAL 2)
POLY 0: [(2X^0)+ (1X^1)+ (1X^2)+ ](POLYNOMIAL 1)

AFTER MULTIPLICATION OF TWO POLYNOMIALS(RESULT IS ON TOP OF PREVIOUS STACK) : 
 (4X^1)+ (2X^2)+ (4X^3)+ (3X^4)+ (2X^5)+ (1X^6)+

*/
 




