#include<stdio.h>
#include<stdlib.h>
//AVL TREE CODE- INSERT, DELETE OPERATIONS 
struct node{   //AVL TREE NODE STRUCTURE
int data;
struct node* left;
struct node* right;
int height;
};
int max_2(int a,int b){
 if(a>b){
  return a;
 }
 return b;
}
struct node* InorderSuccessor(struct node* root){
 while(root->left!=NULL){
  root=root->left;
 }
 return root;
}
int getheight(struct node* root){
 if(root==NULL){
  return -1;
  }
 if(root->left==NULL && root->right==NULL){
  return 0;
 } 
 else{
  int hl=getheight(root->left);
  int hr=getheight(root->right);
  return 1+max(hl,hr);
 }
}
int getbalance(struct node* root){
 return (getheight(root->left)-getheight(root->right));
}
struct node* SingleRightRotate(struct node* P){
 struct node* LC;
 LC=P->left;
 P->left=LC->right;
 LC->right=P;
 P->height=getheight(P);
 LC->height=getheight(LC);
 return LC;
}
struct node* SingleLeftRotate(struct node* P){
 struct node* RC;
 RC=P->right;
 P->right=RC->left;
 RC->left=P;
 P->height=getheight(P);
 RC->height=getheight(RC);
 return RC;
}
struct node* DoubleRotateLeftRight(struct node* P){
 P->left=SingleLeftRotate(P->left);
 return SingleRightRotate(P);
}
struct node* DoubleRotateRightLeft(struct node* P){
P->right=SingleRightRotate(P->right);
 return SingleLeftRotate(P);
}
//INSERT NODES IN AVL TREE
struct node* insert(struct node* root,int v){

 if(root==NULL){
  struct node* newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL){
  perror("MALLOC");
  exit(1);
    }
  newnode->data=v;
  newnode->right=NULL;
  newnode->left=NULL;
  root=newnode;
  }
  else if(v>root->data){
   root->right=insert(root->right,v);
   if(getbalance(root)==-2){
     if(v>root->right->data){
      root=SingleLeftRotate(root);
     }
     else{
      root=DoubleRotateRightLeft(root);
     }
   }
  }
  else if(v<root->data){
   root->left=insert(root->left,v);
   if(getbalance(root)==2){
     if(v<root->left->data){
      root=SingleRightRotate(root);
     }
     else{
      root=DoubleRotateLeftRight(root);
     }
   }
  }
 root->height=getheight(root);
  return root;
}
//DELETE NODES IN AVL TREE
struct node* delete(struct node* root,int v){
 if(root==NULL){
  printf("VALUE NOT FOUND \n");
  return root;
 }
 if(v<root->data){
  root->left=delete(root->left,v);
 }
 else if(v>root->data){
  root->right=delete(root->right,v);
 }
 else{
   if(root->left==NULL){
   struct node* temp=root->right;
   free(root);
   return temp;
   }
   else if(root->right==NULL){
   struct node* temp=root->left;
   free(root);
   return temp;
   }
   struct node* temp=InorderSuccessor(root->right);
   root->data=temp->data;
   root->right=delete(root->right,temp->data);
 }
 if(root==NULL){
 return root;
} 
if(getbalance(root)==2){
  if(getbalance(root->left)>=0){
   root= SingleRightRotate(root);
  }
  else{
   root= DoubleRotateLeftRight(root);
  }
 }
 if(getbalance(root)==-2){
 if(getbalance(root->right)<=0){
   root= SingleLeftRotate(root);
  }
  else{
   root= DoubleRotateRightLeft(root);
  }
 }
 root->height=getheight(root);
 return root;
}
void traverse(struct node* root){
if(root==NULL){
 return;
}
else{
 traverse(root->left);
 printf("VALUE= %d, HEIGHT= %d\n",root->data,root->height);
 traverse(root->right);
}
}
int main(){
struct node* root=NULL;
printf("AFTER INSERT OPERATIONS \n");
root=insert(root,5);
root=insert(root,10);
root=insert(root,15);
root=insert(root,20);
root=insert(root,45);
root=insert(root,55);
root=insert(root,3);
traverse(root);
printf("\n");
printf("AFTER DELETE OPERATIONS \n");
root=delete(root,45);
traverse(root);
printf("\n");
root=delete(root,10);
traverse(root);
printf("\n");
root=delete(root,15);
traverse(root);
printf("\n");
root=delete(root,55);
traverse(root);
printf("\n");
root=delete(root,5);
traverse(root);
printf("\n");
root=delete(root,20);
traverse(root);
printf("\n");
}


int main(){
struct node* root=NULL;
printf("AFTER INSERT OPERATIONS \n");
root=insert(root,5);
root=insert(root,10);
root=insert(root,15);
root=insert(root,20);
root=insert(root,45);
root=insert(root,55);
root=insert(root,3);
traverse(root);
printf("\n");
printf("AFTER DELETE OPERATIONS \n");
root=delete(root,45);
traverse(root);
printf("\n");
root=delete(root,10);
traverse(root);
printf("\n");
root=delete(root,15);
traverse(root);
printf("\n");
root=delete(root,55);
traverse(root);
printf("\n");
root=delete(root,5);
traverse(root);
printf("\n");
root=delete(root,20);
traverse(root);
printf("\n");
}
/*
OUTPUT OF RUN PROGRAM
AFTER INSERT OPERATIONS 
VALUE= 3, HEIGHT= 0
VALUE= 5, HEIGHT= 1
VALUE= 10, HEIGHT= 2
VALUE= 15, HEIGHT= 0
VALUE= 20, HEIGHT= 3
VALUE= 45, HEIGHT= 1
VALUE= 55, HEIGHT= 0

AFTER DELETE OPERATIONS 
VALUE= 3, HEIGHT= 0
VALUE= 5, HEIGHT= 1
VALUE= 10, HEIGHT= 2
VALUE= 15, HEIGHT= 0
VALUE= 20, HEIGHT= 1
VALUE= 55, HEIGHT= 0

VALUE= 3, HEIGHT= 0
VALUE= 5, HEIGHT= 1
VALUE= 15, HEIGHT= 2
VALUE= 20, HEIGHT= 1
VALUE= 55, HEIGHT= 0

VALUE= 3, HEIGHT= 0
VALUE= 5, HEIGHT= 1
VALUE= 20, HEIGHT= 2
VALUE= 55, HEIGHT= 0

VALUE= 3, HEIGHT= 0
VALUE= 5, HEIGHT= 1
VALUE= 20, HEIGHT= 0

VALUE= 3, HEIGHT= 0
VALUE= 20, HEIGHT= 1

VALUE= 3, HEIGHT= 0


*/

