#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};
//INSERTS VALUE AT FRONT OF LIST . IF LIST IS EMPTY THEN THE ELEMENT TO BE INSERTED WILL BE THE FIRST NODE
struct node* insert_front(struct node*head,int v){
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL){
   perror("MALLOC");
   return head;
  }
  newnode->data=v;
  newnode->link=head;
  head=newnode;
  return head;
}
//TO DISPLAY LINKED LIST 
void display(struct node *head){
    struct node* temp;
    temp = head;
    if(temp==NULL){
    printf("LIST IS EMPTY NOW\n");
    }
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->link;
                     }
    printf("\n");
   
   }
//INSERTS NODE WITH VALUE V AT THE END OF GIVEN LIST. IF LIST IS EMPTY , THEN THE ELEMENT TO BE INSERTED IS THE 1ST ELEMENT
struct node* insert_end(struct node* head, int v){
   struct node *newnode,*temp;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->link=NULL;
   newnode->data=v;
   if(head==NULL){
    return newnode;
   }
  
   temp=head;
   while(temp->link!=NULL){
    temp=temp->link;
   }
   temp->link=newnode;
   return head;
}
//the node(having value v) before which we want to insert a node with value x;
struct node* insert_before(struct node* head, int v,int x)
{
if(head->data==v){   //case when inserting before head, in that case we have to update head
struct node* newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=x;
 newnode->link=head;
 head=newnode;
} 
 else{  //rest other cases, insertion before other nodes (except head)
 struct node* temp=head;
 while(temp->link!=NULL && temp->link->data!=v){
    temp= temp->link;
    }
    if(temp->link==NULL){
     printf("NODE WITH VALUE %d DOESN'T EXIST \n",v);
    }
    else if (temp->link->data==v){
     struct node* newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=x; //x is the data to be inserted in newnode
     newnode->link=temp->link;
     temp->link=newnode;
    }
    }
    return head;
}
//the node(having value v) after which we want to insert a node with value x;
struct node* insert_after(struct node* head,int v, int x){
 struct node* temp=head;
 while(temp!=NULL && temp->data!=v){//GENERAL CASE TO INSERT AFTER ANY NODE WITH VALUE V.
    temp= temp->link;
    }
    if(temp==NULL){
     printf("NODE WITH VALUE %d DOESN'T EXIST \n",v);
    }
    else if (temp->data==v){
     struct node* newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=x; //x is the data to be inserted in newnode
     newnode->link=temp->link;
     temp->link=newnode;
    }
    
    return head;
 }
//deletion of a node with value v;
struct node* deletenode(struct node* head,int v){
  struct node *temp,*temp2;
  if(head==NULL){   //EMPTY LIST CASE
   printf("Empty list\n");   
  }
  else if(head->data==v){//CASE WHEN DATA TO BE DELETED IS AT HEAD OF NODE.
   temp=head;
   head=temp->link;
   free(temp);
  }
  else{  //DATA TO BE DELETED IS AT OTHER PLACES 
   temp=head;
   while(temp->link!=NULL && temp->link->data!=v){
    temp=temp->link;
  }
    if(temp->link==NULL) //WHEN WE TRAVERSED WHOLE LIST, BUT THE VALUE WAS NOT FOUND 
    {
      printf("Value not found \n");
    }
    else{
       temp2=temp->link;
       temp->link=temp->link->link;
       free(temp2);
    }
}
return head;
} 
//INSERTING NODES IN AN ORDERED SINGLY LINKED LIST .
struct node* insert_order(struct node* head,int v){
struct node* newnode,*temp;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=v;
if(head==NULL || v<head->data){ //IF VALUE TO BE INSERTED IS LESS THAN VALUE AT HEAD 
 newnode->link=head;
 head=newnode;
 return newnode;
}
else{  // CASE WHEN DATA TO BE INSERTED IS AT OTHER PLACES 
 temp=head;
 while(temp->link!=NULL && temp->link->data<v){
    temp=temp->link;
 }
 newnode->link=temp->link;
 temp->link=newnode;
 return head;
 }

}
int main(){
struct node* head,*head1;
head=NULL;
head=insert_front(head,8888);
display(head);  
head=insert_front(head,4444);
display(head);  
head=insert_end(head,5555);
display(head);  
head=insert_before(head,4444,8930);
display(head);
head=insert_after(head,5555,77965);
display(head);
head=insert_before(head,8888,1000);
display(head);
head=deletenode(head,77965);
display(head);
head=deletenode(head,5555);
display(head);
head=deletenode(head,8888);
display(head);
head=deletenode(head,1000);
display(head);
head=deletenode(head,4444);
display(head);
head=deletenode(head,8930);
display(head);
head=insert_front(head,8005);
display(head);  
head=insert_end(head,9007);
display(head);  
head=insert_order(head,3370);
display(head);
head=insert_order(head,9999);
display(head);
head=insert_order(head,8190);
display(head);

}

/*
OUTPUT OF THE RUN PROGRAM 
8888-> 
4444-> 8888-> 
4444-> 8888-> 5555-> 
8930-> 4444-> 8888-> 5555-> 
8930-> 4444-> 8888-> 5555-> 77965-> 
8930-> 4444-> 1000-> 8888-> 5555-> 77965-> 
8930-> 4444-> 1000-> 8888-> 5555-> 
8930-> 4444-> 1000-> 8888-> 
8930-> 4444-> 1000-> 
8930-> 4444-> 
8930-> 
LIST IS EMPTY NOW

8005-> 
8005-> 9007-> 
3370-> 8005-> 9007-> 
3370-> 8005-> 9007-> 9999-> 
3370-> 8005-> 8190-> 9007-> 9999-> 
*/








