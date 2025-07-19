#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* link;
};
//INSERTION AT FRONT OF CIRUCLAR LINKED LIST, IF LIST IS EMPTY THEN THE NODE TO BE INSERTED WILL BE THE 1ST NODE
struct node* insert_front(struct node* head, int v) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {//CASE WHEN MEMORY ALLOCATION FAILS 
        perror("MALLOC");
        return head;
    }
       newnode->data = v;
      if (head == NULL) { //CASE WHEN LIST IS EMPTY 
        newnode->link = newnode; 
        head=newnode;
    } else {  //REST OTHER CASE WHEN LIST IS NON EMPTY
        struct node* temp ;
         temp=head;
        newnode->link=head;
         while(temp->link!=head){
          temp=temp->link;
        }
         temp->link=newnode;
         head=newnode;
   }
    return newnode;
}
//INSERTION AT END OF CIRCULAR LINKED LIST, IF LIST IS EMPTY THEN THE NODE TO BE INSERTED WILL BE THE 1ST NODE
struct node* insert_end(struct node*head,int v){
  struct node* newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=v;
  if(head==NULL){ //CASE WHEN LIST IS EMPTY
   newnode->link=newnode;
   head=newnode;
  }
  else{ //CASE WHEN LIST IS NON-EMPTY 
     temp=head;
     while(temp->link!=head){
     temp=temp->link;
     }
     temp->link=newnode;
     newnode->link=head; 
   
     
  }
return head;  
}
// DELETION IN A CIRCULAR LINKED LIST
struct node* deletenode(struct node* head, int v) {
    struct node* temp, * temp2;
    struct node *t = head;
    if (head == NULL) { //CASE WHEN LIST IS EMPTY
        printf("List is empty\n");
        
    }
     else if(head->data==v) { // CASE WHEN DATA TO BE DELETED IS AT HEAD NODE, THEN WE UPDATE THE HEAD POINTER AS WELL
        if(head->link==head){ //IF ONLY ONE NODE PRESENT THEN SET HEAD TO NULL 
         head=NULL;
        }
        else{  //CASE WHEN THERE ARE MORE THAN ONE NODE NODE PRESENT & NODE TO BE DELETED IS THE 1st NODE, ALSO WE UPDATE THE HEAD
        head = head->link;
        temp = head;
        while (temp->link != t ){
            temp = temp->link;
        }
        temp->link = head;
         
     }
  }
    
       
    else { // REST OTHER CASES WHERE DATA TO BE DELETED IS AT OTHER PLACES 
        temp=head;
        while (temp->link != head && temp->link->data != v) {
            temp = temp->link;
        }
        if (temp->link == head) {
            printf("Value not found\n");
        } else {
             temp2 = temp->link;
            temp->link = temp->link->link;
            free(temp2);
        }
    }
    return head;
}
//HERE WE WANT TO INSERT A NODE(OF VALUE x) BEFORE A NODE OF VALUE v.
struct node* insert_before(struct node* head,int v,int x){
if(head->data==v){ //CASE WHEN WE WANT TO INSERT BEFORE THE HEAD NODE 
 insert_front(head,x);
}
else{  //CASE WHEN NODE IS TO BE INSERTED BEFORE ANY OTHER NODE , EXCEPT HEAD NODE
 struct node* temp=head;
 while(temp->link!=head && temp->link->data!=v){
  temp=temp->link;
 }
 if(temp->link==head){ //IF WE TRAVERSE AND GET TO HEAD, THEN THE NODE WITH VALUE V DOESNT EXIST 
  printf("NODE WITH VALUE %d DOESN'T EXISTS \n",v);
 }
 else if(temp->link->data==v){ 
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=x;
   newnode->link=temp->link;
   temp->link=newnode;
    
 }
return head;
}
}
//HERE WE WANT TO INSERT A NODE(OF VALUE x) AFTER  A NODE OF VALUE v.
struct node* insert_after(struct node* head, int v,int x){
struct node* temp=head;
if(head->data==v){ //CASE WHEN NODE WITH VALUE X IS TO BE INSERTED AFTER HEAD NODE 
 struct node* newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=x;
 newnode->link=head->link;
 head->link=newnode;
}
else{ //REST OTHER CASES WHEN NODE WITH VALUE X IS TO BE INSERTED AFTER SOME NODE WITH VALUE OTHER THAN HEAD NODE 
do{                      
 temp=temp->link;
}while(temp!=head && temp->data!=v);
 if(temp==head){
  printf("NODE WITH VALUE %d DOESN'T EXIST \n",v);
 }
 else if(temp->data==v){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->link=temp->link;
  temp->link=newnode;
  
 }
 }
 return head;
}
//INSERTION OF NODES IN A ORDERED CIRCUALR LINKED LIST 
struct node* insert_order(struct node* head,int v){
struct node* newnode,*temp;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=v;
if(head==NULL){ //CASE WHEN LIST IS EMPTY 
        newnode->link=newnode;
        head=newnode;
        return newnode;
}
else if(v<head->data){ //VALUE V IS LESS THAN VALUE IN HEAD NODE
temp=head;
while (temp->link != head) {
            temp = temp->link;
        }
       
        newnode->link = head;
        head=newnode;
        temp->link=head;
      return newnode;
}
else{ //REST OTHER CASES  
temp=head;
 while(temp->link!=head && temp->link->data<v){
    temp=temp->link;
 }
 newnode->link=temp->link;
 temp->link=newnode;
 return head;
 }
}
//DISPLAY FUNCTION 
void display(struct node* head) {
    if (head == NULL) {
        printf(" EMPTY LIST \n");
        return;
    }
    
    struct node* temp = head;
    do {
        printf("%d-> ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("\n");

}
int main() {
    struct node* head = NULL;
    //INSERT FRONT, END , BEFORE , AFTER OPERATIONS  
    head = insert_front(head, 6666);
     display(head);
    head=insert_front(head,5555);
     display(head);
    head=insert_end(head,7777);
    display(head);
     head=insert_before(head,5555,3000);
    display(head);
    head=insert_before(head,7777,3450);
    display(head);
    head=insert_after(head,6666,6955);
    display(head);
      head=insert_after(head,7777,1235);
    display(head);
    //SEQUENCE OF DELETE OPERATIONS 
    head=deletenode(head,1235);
    display(head);
    head=deletenode(head,3450);
    display(head);
     head=deletenode(head,7777);
    display(head);
     head=deletenode(head,5555);
    display(head);
     head=deletenode(head,6666);
    display(head);
       head=deletenode(head,3000);
    display(head);
       head=deletenode(head,6955);
    display(head);
    //SEQUENCE OF INSERT ORDER OPERATIONS 
    head=insert_order(head,5000);
    display(head);
    head=insert_order(head,2440);
    display(head);
    head=insert_order(head,3455);
    display(head);
    head=insert_order(head,30);
    display(head);
     head=insert_order(head,6000);
    display(head);
    return 0;
}
/*
OUTPUT OF PROGRAM 
6666-> 
5555-> 6666-> 
5555-> 6666-> 7777-> 
3000-> 5555-> 6666-> 7777-> 
3000-> 5555-> 6666-> 3450-> 7777-> 
3000-> 5555-> 6666-> 6955-> 3450-> 7777-> 
3000-> 5555-> 6666-> 6955-> 3450-> 7777-> 1235-> 
3000-> 5555-> 6666-> 6955-> 3450-> 7777-> 
3000-> 5555-> 6666-> 6955-> 7777-> 
3000-> 5555-> 6666-> 6955-> 
3000-> 6666-> 6955-> 
3000-> 6955-> 
6955-> 
 EMPTY LIST 
5000-> 
2440-> 5000-> 
2440-> 3455-> 5000-> 
30-> 2440-> 3455-> 5000-> 
30-> 2440-> 3455-> 5000-> 6000-> 
*/




