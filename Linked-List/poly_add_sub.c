#include <stdio.h>
#include <stdlib.h>

struct polynode {
    int c;  // c for coefficient
    int p;  // p for power
    struct polynode* link;
};
//WE INSERT THE GIVEN POLYNOMIAL IN ASCENDING ORDER OF THEIR COEFFICIENTS
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
//FUNCTION TO ADD TWO POLYNOMIALS 
struct polynode* add(struct polynode* poly1, struct polynode* poly2) {
    struct polynode *headr=NULL,*l;
    l=headr;
    while(poly1!=NULL && poly2!=NULL){
      struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
     if (poly1->p<poly2->p){ //CONTRIBUTE THE SMALLER POLYNOMIAL(POLY1) TO THE RESULT
        newnode->c = poly1->c;
        newnode->p = poly1->p;
       if(headr==NULL){ //IF RESULT LIST IS EMPTY , THEN CREATE A NEWNODE
        headr=newnode;
        l=newnode;
       }
       else{ //CASE WHEN RESULT LIST IS NON-EMPTY , WE KEEP LINKING .
        l->link=newnode;
        l=newnode;
       }
       poly1=poly1->link;//FINALLY MOVE THE POINTER OF SMALLER POWER NODE 
       }
       else if(poly1->p>poly2->p){ //CONTRIBUTE THE SMALLER POLYNOMIAL(POLY2) TO THE RESULT
       newnode->c = poly2->c;
       newnode->p = poly2->p;
          if(headr==NULL){ //IF RESULT LIST IS EMPTY , THEN CREATE A NEWNODE
        headr=newnode;
        l=newnode;
       }
       else{ //CASE WHEN RESULT LIST IS NON-EMPTY , WE KEEP LINKING .
        l->link=newnode;
        l=newnode;
       }
       poly2=poly2->link; //FINALLY MOVE THE POINTER OF SMALLER POWER NODE 
    
       }
        else{  //CASE WHEN POWERS ARE EQUAL, WE ADD THEIR RESPECTIVE COEFFICENTS 
        newnode->c = poly1->c + poly2->c;
        newnode->p = poly1->p;
        poly1 = poly1->link;
        poly2 = poly2->link;
      
        if(headr==NULL){ //IF LIST WAS EMPTY , CREATION OF 1st NODE
        headr=newnode;
        l=newnode;
         //WHEN ADDING ON FIRST NODE , MAKE SURE TO UPDATE HEAD TO TEMP;
        }
        else{ //LINK THE CURRENT LIST 
         l->link=newnode;
         l=newnode;
        }
       }
   }
   while (poly2 != NULL) { //WHILE POLYNOMIAL 2 HAS NOT BEEN TRAVERSED FULLY , KEEP ADDING ITS REMAINING NODES TO THE LIST WHEN POLYNOMIAL1 HAS BEEN TRAVERSED FULLY
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
    while (poly1 != NULL) {//WHILE POLYNOMIAL 1 HAS NOT BEEN TRAVERSED FULLY , KEEP ADDING ITS REMAINING NODES TO THE LIST WHEN POLYNOMIAL2 HAS BEEN TRAVERSED FULLY
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
//FUNCTION TO SUBTRACT 2 POLYNOMIALS
struct polynode* subtract(struct polynode* poly1, struct polynode* poly2) {
    struct polynode *headr=NULL,*l;
    struct polynode* t;
    l=headr;
    while(poly1!=NULL && poly2!=NULL){
      struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
     if (poly1->p<poly2->p){ //CONTRIBUTE THE SMALLER POLYNOMIAL(POLY1) TO THE RESULT;
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
       else if(poly1->p>poly2->p) //CONTRIBUTE THE SMALLER POLYNOMIAL(POLY2) TO THE RESULT;
       {
       newnode->c = -poly2->c;
       newnode->p = poly2->p;
        if(headr==NULL){//CASE WHEN LIST IS EMPTY , CREATION OF 1st NODE
        headr=newnode;
        l=newnode;
       }
       else{ //CASE WHEN LIST IS NON-EMPTY ,KEEP LINKING
        l->link=newnode;
        l=newnode;
       }
       poly2=poly2->link;
       }
        else{ //POWERS ARE SAME, THEN DO THE SUBTRACTION OF RESPECTIVE COEFFICIENTS
        if(headr==NULL){ //CASE WHEN LIST IS EMPTY 
        newnode->c = poly1->c - poly2->c;
        newnode->p = poly1->p;
        poly1 = poly1->link;
        poly2 = poly2->link;
         if(newnode->c!=0){
        l=newnode;
        headr=newnode;} //WHEN ADDING ON FIRST NODE , MAKE SURE TO UPDATE HEAD TO TEMP;
        }
        else
          
        newnode->c = poly1->c - poly2->c;
        newnode->p = poly1->p;
        poly1 = poly1->link;
        poly2 = poly2->link;
        if(newnode->c!=0){ //IF COEFFICIENT IS 0 THEN NO NEED TO ADD IT TO THE RESULT.
        l->link=newnode;
        l=newnode;}
        
        }
            } 
      while (poly2 != NULL) { //WHILE POLYNOMIAL 2 HAS NOT BEEN TRAVERSED FULLY , KEEP ADDING ITS REMAINING NODES TO THE LIST WHEN POLYNOMIAL1 HAS BEEN TRAVERSED FULLY
     struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
     //  poly2->c=-1*(poly2->c);
       newnode->c = -(poly2->c);
       newnode->p = poly2->p;
       
       newnode->link=NULL;
        if (headr == NULL) { //CASE WHEN LIST IS EMPTY , CREATION OF 1st NODE
            headr =newnode;
            l = newnode;
        } else { //CASE WHEN LIST IS NON-EMPTY 
            l->link =newnode;
            l = newnode;
        }
      poly2 = poly2->link;
    }
    while (poly1 != NULL) { //WHILE POLYNOMIAL 1 HAS NOT BEEN TRAVERSED FULLY , KEEP ADDING ITS REMAINING NODES TO THE LIST WHEN POLYNOMIAL2 HAS BEEN TRAVERSED FULLY
    struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
       newnode->c = poly1->c;
       newnode->p = poly1->p;
       newnode->link=NULL;
         if (headr == NULL) { //CASE WHEN LIST IS EMPTY 
            headr = newnode;
            l =newnode;
        } else { //CASE WHEN LIST IS NON-EMPTY
            l->link = newnode;
            l = newnode;
        }
     poly1 = poly1->link;
    
}
return headr;
}
//DISPLAY FUNCTION
void display(struct polynode* head) {
    struct polynode* temp;
    temp = head;
    while (temp != NULL) {
        if((temp->c==0 && temp->p==0)){
          printf(" ");
        }
       
       else if(temp->c!=0 && temp->p==0){
        printf("%d+", temp->c);
        }
       else if(temp->c==0 && temp->p!=0){
          printf(" ");
        }
        else{
        printf(" (%dX^%d)+",temp->c,temp->p);
        }
        temp=temp->link;
    }
    
    printf("\n");
    printf("\n");
}
int main() {
    struct polynode* head1 = NULL;
    struct polynode* head2 = NULL;
    struct polynode* headr = NULL;
    int p,c;
c=2;p=0;
head1=insert_order(head1,c,p);
c=-3;p=12;
head1=insert_order(head1,c,p);
c=4,p=7;
head1=insert_order(head1,c,p);
c=56,p=32;
head1=insert_order(head1,c,p);
printf("POLYNOMIAL 1 \n");
display(head1);
c=2;p=1;
head2=insert_order(head2,c,p);                  
c=-4;p=11;
head2=insert_order(head2,c,p);
c=3;p=12;
head2=insert_order(head2,c,p);
c=5,p=7;
head2=insert_order(head2,c,p);
c=56,p=32;
head2=insert_order(head2,c,p);
printf("POLYNOMIAL 2 \n");
display(head2); 
headr=add(head1,head2);
printf("AFTER ADDITION \n");
display(headr);
headr=subtract(head1,head2);
printf("AFTER SUBTRACTION(POLYNOMIAL 1 -POLYNOMIAL 2) \n");
display(headr);
return 0;
}
/*
OUTPUT 
POLYNOMIAL 1 
2+ (4X^7)+ (-3X^12)+ (56X^32)+

POLYNOMIAL 2 
 (2X^1)+ (5X^7)+ (-4X^11)+ (3X^12)+ (56X^32)+

AFTER ADDITION 
2+ (2X^1)+ (9X^7)+ (-4X^11)+  (112X^32)+

AFTER SUBTRACTION(POLYNOMIAL 1 -POLYNOMIAL 2) 
2+ (-2X^1)+ (-1X^7)+ (4X^11)+ (-6X^12)+



*/


