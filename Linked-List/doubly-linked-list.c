#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* l;
 struct node* r;
};
//INSERTION AT FRONT OF DOUBLY LINKED LIST , WHEN LIST IS EMPTY THE NEW NODE IS THE 1ST ELEMENT 
struct node* insert_front(struct node** head,struct node** tail,int v){
  struct node* newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=v;
  if(*head==NULL && *tail==NULL){ //CASE WHEN LIST IS EMPTY , CREATION OF 1st NODE 
   *head=*tail=newnode;
   newnode->l=NULL;
   newnode->r=NULL;
}
  else{ //CASE WHILE LIST IS NON-EMPTY , INSERTING AT FRONT 
   (*head)->l=newnode;
   newnode->r=*head;      
   newnode->l=NULL;
   *head=newnode;
   }
  return newnode;
}
//INSERTION AT FRONT OF DOUBLY LINKED LIST , WHEN LIST IS EMPTY THE NEW NODE IS THE 1ST ELEMENT 
struct node* insert_end(struct node** head,struct node** tail,int v){
 struct node* newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=v;
 if(*head==NULL && *tail==NULL){ //CASE WHEN LIST IS EMPTY , CREATION OF 1st NODE
   *head=*tail=newnode;
   newnode->l=NULL;
   newnode->r=NULL;
  }
  else{ //CASE WHILE LIST IS NON-EMPTY , INSERTING AT END
   
   newnode->l=*tail;
   newnode->r=NULL;
   (*tail)->r=newnode;
   *tail=newnode;
   }
  return *head;
}
//DELETING ELEMENT FROM A DOUBLY LINKED LIST 
struct node* deletenode(struct node** head,struct node** tail,int v){
 struct node* temp,*temp2;
 if(*head==NULL && *tail==NULL){ //CASE WHEN LIST IS EMPTY 
  printf("List is empty \n");
 } 
 else if((*head)->data==v && (*tail)->data!=v){ //CASE WHEN DATA IS EQUAL TO HEAD NODE DATA
  
  temp=*head;
  *head=(*head)->r;
  (*head)->l=NULL;
  free(temp);
 }
 else if(*head==*tail && (*head)->data==(*tail)->data){//LIST WITH ONLY ONE NODE
   if((*head)->data==v){
   *head=NULL;
   *tail=NULL;
   }
   else{
   printf("NODE NOT FOUND\n");}
    printf("LIST IS NOW EMPTY \n");
 }
 else if((*tail)->data==v && (*head)->data!=v){ //CASE WHEN DATA IS EQUAL TO TAIL NODE DATA
  temp2=*tail;
  (*tail)->l->r=NULL;
  (*tail)=(*tail)->l;
  free(temp2);
 }
 else{  //CASE WHEN DATA TO BE DELETED IS AT SOME OTHE PLACE
    temp=*head;
    while(temp!=NULL && temp->data!=v){
     temp=temp->r;
    } 
    if(temp==NULL){ //IF WE TRAVERSE WHOLE LIST AND DONT FIND THE NODE WITH VALUE V
     printf("NOT FOUND \n");
    } 
    else{
    temp->r->l=temp->l;
    temp->l->r=temp->r;
  }
 }
 return *head;
}
//HERE WE WANT TO INSERT A NODE WITH VALUE x , before a NODE WTH VALUE v;
struct node* insert_before(struct node** head,int v,int x){
  if((*head)->data==v){ //CASE WHEN WE WANT TO INSERT BEFORE HEAD & UPDATE HEAD TO NEWNODE
      struct node* newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=x;
      newnode->r=*head;
      newnode->l=NULL;
      (*head)->l=newnode;
      *head=newnode;
  }
  
  else{ //REST OTHER CASE 
   struct node* temp=*head;
   while(temp!=NULL && temp->data!=v){
     temp=temp->r;
   }
   if(temp==NULL){ //THE NODE WITH VALUE V DOESNT EXISTS 
   printf("NODE WITH VALUE %d DOESN'T EXISTS \n",v);
   }
   else if(temp->data==v){  //THE NODE EXISTS AND WE WANT TO INSERT BEFORE IT 
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->l=temp->l;
    newnode->r=temp;
    temp->l->r=newnode;
    temp->l=newnode;
   }
  }
  return *head;
}
//HERE WE WANT TO INSERT A NODE WITH VALUE x , after a NODE WTH VALUE v;
struct node* insert_after(struct node** head, struct node** tail,int v,int x){
 if((*tail)->data==v){ //CASE WHEN WE WANT TO INSERT AFTER TAIL , & UPDATE TAIL TO NEWNODE
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->l=(*tail);
  newnode->r=NULL;
  (*tail)->r=newnode;
  (*tail)=newnode;
  
 }
  else{ //REST OTHER CASES
  struct node* temp=*head;
   while(temp!=NULL && temp->data!=v){
     temp=temp->r;
   }
   if(temp==NULL){ //NODE WITH VALUE V DOESNT EXISTS 
   printf("NODE WITH VALUE %d DOESN'T EXISTS \n",v);
   }
   else if(temp->data==v){ 
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->l=temp;
    newnode->r=temp->r;
    temp->r=newnode;
    temp->r->l=newnode;
   }
   }
   return *head;
}
//INSERTION IN AN ORDERED DOUBLY LINKED LIST 
struct node* insert_order(struct node** head,struct node** tail,int v){
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=v;
if(*head==NULL && *tail==NULL){  //WHEN LIST IS EMPTY , CREATION OF THE 1st NODE 
 *head=*tail=newnode;
 newnode->l=NULL;
 newnode->r=NULL;
}
else if((*head)->data>v){ //VALUE V IS LESS THAN VALUE IN HEAD 
  newnode->r=*head;
  newnode->l=NULL;
  *head=newnode; //UPDATE HEAD TO NEWNODE
}
else { // REST OTHER CASES
 struct node* temp;
 temp=*head;
 while(temp->r!=NULL && temp->r->data<v){
   temp=temp->r;
   }
   if(temp->r==NULL){ //INSERTNG AT THE END ,THE VALUE V IS THE LARGEST AMONG ALL  THE VALUES IN GIVEN LIST
    newnode->l=temp;
    newnode->r=NULL;
    temp->r=newnode;
    *tail=newnode;    
    }
     else{ // VALUE IS SOMEWHERE TO BE INSERTED IN BETWEEN 
   newnode->l=temp;
   newnode->r=temp->r;
   temp->r=newnode;
   newnode->r->l=newnode;
   }
   }
return *head;
}
//FUNCTION TO DISPLAY LIST 
void display(struct node* head){
    struct node* temp;
    temp = head;
    while (temp != NULL) {
        printf("%d<->",temp->data);
        temp = temp->r;
        
    }
   
    printf("\n");
   
    }
int main(){
struct node* head=NULL;
struct node* tail=NULL;
//SEQUENCE OF INSERT FRONT,END, AFTER ,BEFORE OPERATIONS 
head=insert_front(&head,&tail,8000);
display(head);
head=insert_front(&head,&tail,7998);
display(head);
head=insert_end(&head,&tail,9000);
display(head);
head=insert_before(&head,8000,8090);
display(head);
head=insert_after(&head,&tail,8000,1357);
display(head);
head=insert_before(&head,7998,7750);
display(head);
head=insert_after(&head,&tail,9000,9925);
display(head);
//SEQUENCE OF DELETE OPERATIONS 
head=deletenode(&head,&tail,8000);
display(head);
head=deletenode(&head,&tail,7998);
display(head);
head=deletenode(&head,&tail,9925);
display(head);
head=deletenode(&head,&tail,7750);
display(head);
head=deletenode(&head,&tail,8090);
display(head);
head=deletenode(&head,&tail,1357);
display(head);
head=deletenode(&head,&tail,9000);
display(head);
//SEQUENCE OF INSERT ORDER OPERATIONS 
head=insert_order(&head,&tail,1225);
display(head);
head=insert_order(&head,&tail,3275);
display(head);
head=insert_order(&head,&tail,4475);
display(head);
head=insert_order(&head,&tail,1025);
display(head);
head=insert_order(&head,&tail,5790);
display(head);
head=insert_order(&head,&tail,3560);
display(head);
}

/*
OUTPUT
8000<->
7998<->8000<->
7998<->8000<->9000<->
7998<->8090<->8000<->9000<->
7998<->8090<->8000<->1357<->9000<->
7750<->7998<->8090<->8000<->1357<->9000<->
7750<->7998<->8090<->8000<->1357<->9000<->9925<->
7750<->7998<->8090<->1357<->9000<->9925<->
7750<->8090<->1357<->9000<->9925<->
7750<->8090<->1357<->9000<->
8090<->1357<->9000<->
1357<->9000<->
9000<->
LIST IS NOW EMPTY 

1225<->
1225<->3275<->
1225<->3275<->4475<->
1025<->1225<->3275<->4475<->
1025<->1225<->3275<->4475<->5790<->
1025<->1225<->3275<->3560<->4475<->5790<->
*/

