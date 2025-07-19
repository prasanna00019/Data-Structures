#include<stdio.h>
#include<stdlib.h>
#define n 30
//ITERATIVE DELETE & INSERT OPERATIONS
struct node{
int data;
struct node* left;
struct node* right;
};
int c=0;
struct node* q[n];
int f=-1;
int r=-1;
void enqueue(struct node* v){
 if(r>=n-1)
 { printf("QUEUE IS FULL \n");}
 else{
  if(f==-1)
   {f=0;}
  r++;
  q[r]=v;
 }
}
void dequeue(){
 if(f==-1 && r==-1){
   printf("QUEUE IS EMPTY \n");
  }
  else{
   if(f==r){
    struct node* r1=q[f];
    f=-1;r=-1;
      }
   f++;
   }
}
struct node* inorderSuccessor(struct node* root){
 while(root->left!=NULL){
  root=root->left;
 }
 return root;
}
struct node* insert(struct node* root,int v){
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL){
 perror("MALLOC");
 exit(1);
}
c+=1;
newnode->data=v;
newnode->right=NULL;
newnode->left=NULL;
if(root==NULL){
 root=newnode;
 return root;
}
struct node* temp=root;
while(1){
 if(v<temp->data){
  if(temp->left==NULL){
    temp->left=newnode;
    break;  
 }
 temp=temp->left;
}
else{
 if(temp->right==NULL){
  temp->right=newnode;
  break;
 }
 temp=temp->right;
}
}
return root;;
}
struct node* delete(struct node* root, int v) {
    struct node* temp3 = NULL;
    struct node* temp = root;
    while (temp != NULL && temp->data != v) {
        temp3 = temp;
        if (v < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
                                           }
    if (temp == NULL) {
        printf("NOT FOUND\n");
        return root;
                      }
   //0 or 1 child wala case
      if (temp->left == NULL || temp->right == NULL) {
        struct node* temp2 ; 
        if(temp->left == NULL) { temp2=temp->right; }
        else{
        temp2= temp->left;}
        if(temp3==NULL){
          root=temp2;
        }
        else if (temp3->left == temp)
           { temp3->left = temp2;}
        else{
            temp3->right = temp2;
        free(temp);}
    }
    //2-CHILD wala case
     else {
        struct node* successor = inorderSuccessor(temp->right);
        temp->data = successor->data;
        struct node* temp2=temp->right;
        while(temp2!=successor){
           temp3=temp2;
           temp2=temp2->left; 
        }
        if(temp2->right==NULL){
          temp3->left=NULL;
        }
        else if(temp2->right!=NULL){
          temp3->left=temp2->right;
        //free(temp2);
        }
        free(temp2);
        //temp->right = delete(temp->right, successor->data);
    }

    return root;
}
void inorder(struct node* root){
if(root==NULL){
 return;
}
else{
 inorder(root->left);
 printf("%d ",root->data);
 inorder(root->right);
}
}
void levelOrder(struct node* root){
  if(root==NULL){
   return;
   }
      enqueue(root);
   while(f!=-1 && r!=-1){
     struct node* current=q[f];
     //display();
    printf("%d ",current->data);
     if(current->left!=NULL){
       enqueue(current->left); 
     }
     if(current->right!=NULL){
      enqueue(current->right);
     }
     dequeue();    
   }
   printf("\n");
}   
struct node* clone(struct node* root){
struct node* root1;
if(root==NULL){
 return NULL;
} 
else {
  root1=(struct node*)malloc(sizeof(struct node)); 
  if(root1==NULL){
  perror("MALLOC");
  exit(1);
    }
  root1->data=root->data; 
 root1->left=clone(root->left);
 root1->right=clone(root->right);
}
return root1;
}
int main(){
struct node* root=NULL;
printf("AFTER INSERT OPERATIONS \n");
root=insert(root,26);
root=insert(root,5);
root=insert(root,77);
root=insert(root,1);
root=insert(root,61);
root=insert(root,11);
root=insert(root,59);
root=insert(root,15);
root=insert(root,48);
root=insert(root,19);
printf("THE INORDER TRAVERSAL IS \n");
inorder(root);
printf("\n");
printf("LEVEL ORDER TRAVERSAL IS \n");
levelOrder(root);
printf("AFTER DELETE OPERATIONS \n");
root=delete(root,26);
inorder(root);
printf("\n");
root=delete(root,26);
inorder(root);
printf("\n");
root=delete(root,1);
inorder(root);
printf("\n");
root=delete(root,5);
inorder(root);
printf("\n");
root=delete(root,48);
inorder(root);
printf("\n");
root=delete(root,61);
inorder(root);
printf("\n");
root=delete(root,77);
inorder(root);
printf("\n");
root=delete(root,59);
inorder(root);
printf("\n");
root=delete(root,11);
inorder(root);
printf("\n");
root=delete(root,15);
inorder(root);
printf("\n");
root=delete(root,19);
inorder(root);
printf("\n");
//printf("% d \n",c);
/*inorder(root1);
printf("\n");*/
}

/*OUTPUT OF THE RUN PROGRAM
AFTER INSERT OPERATIONS 
THE INORDER TRAVERSAL IS 
1 5 11 15 19 26 48 59 61 77 
LEVEL ORDER TRAVERSAL IS 
26 5 77 1 11 61 15 59 19 48 
AFTER DELETE OPERATIONS 
1 5 11 15 19 48 59 61 77 
NOT FOUND
1 5 11 15 19 48 59 61 77 
5 11 15 19 48 59 61 77 
11 15 19 48 59 61 77 
11 15 19 59 61 77 
11 15 19 59 77 
11 15 19 59 
11 15 19 
15 19 
19 
*/
