#include<stdio.h>
#include<stdlib.h>
struct polynode{
    double c;
    int p;
    struct polynode* link;
};
struct polynode* insert_descending(struct polynode*,double,int);
struct polynode* subtract(struct polynode*,struct polynode*);
struct polynode* divide(struct polynode*,struct polynode*);
struct polynode* multiply(struct polynode*, struct polynode*);
void display(struct polynode*);

struct polynode* multiply(struct polynode* poly1,struct polynode* poly2){
 struct polynode* t1,*t2,*ans=NULL;
 int p; double c;
 t1=poly1;t2=poly2;
 while(t1!=NULL){
 while(t2!=NULL){
   c=t1->c*t2->c;
   p=t1->p+t2->p;
   ans=insert_descending(ans,c,p);
   t2=t2->link;
 }
 t2=poly2;
 t1=t1->link;
}
return ans;
}
struct polynode *divide(struct polynode* poly1,struct polynode* poly2){

  struct polynode* w,*w1,*s;
  struct polynode* q=NULL;
  struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
  w=poly2;w1=poly1;
  while((w->p)>=(poly1->p)){
    newnode->p=(w->p)-(w1->p);
    newnode->c=(w->c)/(w1->c);
    if(w->p-(poly1->p)==0){  
    w=insert_descending(w,0,-1);}
    q=insert_descending(q,newnode->c,newnode->p);
    s=multiply(w1,newnode);
    w=subtract(w,s);
   }
 printf("THE QUOTIENT IS \n");
display(q);
printf("THE REMAINDER IS \n");
if(w->c==0){
 printf("0");
 return NULL;
}
else{
//display(w);
return w;}
}
struct polynode* subtract(struct polynode* poly1, struct polynode* poly2) {
    struct polynode *headr=NULL,*l;
    l=headr;
  //  printf("%d %d test1\n",poly2->c,poly2->p);
    while(poly1!=NULL && poly2!=NULL){
      struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
     if (poly1->p<poly2->p){
        newnode->c = -poly2->c;
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
       }
       else if(poly1->p>poly2->p)
       {
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
     //  printf("%d \n",l->p);
       }
        else{ 
        if(headr==NULL){
        newnode->c = poly1->c - poly2->c;
        newnode->p = poly1->p;
        poly1 = poly1->link;
        poly2 = poly2->link;
        if(newnode->c!=0){
        l=newnode;
        headr=newnode; }//WHEN ADDING ON FIRST NODE , MAKE SURE TO UPDATE HEAD TO TEMP;
      
        }
        else{
        newnode->c = poly1->c - poly2->c;
        newnode->p = poly1->p;
        poly1 = poly1->link;
        poly2 = poly2->link;
        if(newnode->c!=0){
        l->link=newnode;
        l=newnode;}
        }
   }
   }
   while (poly2 != NULL) {
     struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
     //  poly2->c=-1*(poly2->c);
       newnode->c = -(poly2->c);
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

struct polynode* insert_descending(struct polynode* head,double c,int p){
 struct polynode* newnode=(struct polynode*)malloc(sizeof(struct polynode));
     newnode->p=p;
     newnode->c=c;
     if(head==NULL){
        newnode->link=NULL;
        head=newnode;
     }   
    else if(p>head->p){
        newnode->link=head;
        head=newnode;
    }
    else {
        struct polynode* temp;
        temp=head;
        while(temp->link!=NULL && temp->link->p>p){
            temp=temp->link;
        }
        if(temp->link==NULL){
            temp->link=newnode;
            newnode->link=NULL;
        }
        else {
            newnode->link=temp->link;
            temp->link=newnode;
        }
    }
    
 return head;
}
void display(struct polynode* head) {
    struct polynode* temp;
    temp = head;
    while (temp != NULL) {
        if((temp->c==0 && temp->p==0)){
          printf(" ");
        }
       
       else if(temp->c!=0 && temp->p==0){
        printf("(%0.2f) ", temp->c);
        }
       else if(temp->c==0 && temp->p!=0){
          printf(" ");
        }
        else{
        printf(" (%0.2fX^%d)+",temp->c,temp->p);
        }
        temp=temp->link;
    }
    printf("\n");
    printf("\n");
}
int main(){
  struct polynode* head1=NULL;
  struct polynode* head2=NULL;
  struct polynode* headr=NULL;
  head1=insert_descending(head1,1,2);
  head1=insert_descending(head1,-2,1);
  head1=insert_descending(head1,3,0);
  printf("THE DIVISOR IS \n");
  display(head1);
  head2=insert_descending(head2,3,8);
  head2=insert_descending(head2,-5,7);
   head2=insert_descending(head2,2,6);
  head2=insert_descending(head2,-4,5);
  head2=insert_descending(head2,7,4);
  head2=insert_descending(head2,-9,3);
  head2=insert_descending(head2,6,2);
  head2=insert_descending(head2,-8,1);
  head2=insert_descending(head2,10,0);
 
  printf("THE DIVIDEND IS \n");
  display(head2);
  headr=divide(head1,head2);
  display(headr); 
 }
 /*
 OUTPUT
 THE DIVISOR IS 
 (1.00X^2)+ (-2.00X^1)+(3.00) 

THE DIVIDEND IS 
 (3.00X^8)+ (-5.00X^7)+ (2.00X^6)+ (-4.00X^5)+ (7.00X^4)+ (-9.00X^3)+ (6.00X^2)+ (-8.00X^1)+(10.00) 

THE QUOTIENT IS 
 (3.00X^6)+ (1.00X^5)+ (-5.00X^4)+ (-17.00X^3)+ (-12.00X^2)+ (18.00X^1)+(78.00) 

THE REMAINDER IS 
 (94.00X^1)+(-224.00)  
*/
 
 
 
 
 
