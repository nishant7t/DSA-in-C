# include<stdio.h>
#include <stdlib.h>
struct node {
   int data;
   struct node * left;
    struct node * right;
};
struct node * createnode(int val)
{
   struct node * newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=val;
   newnode->left=NULL;
   newnode->right=NULL;
   return newnode;
}


struct node * insert(struct node * root,int val){
   if (root==NULL)
   {
       return createnode(val);
   }
  
   if (val< root->data)
   {
           root->left=insert(root->left,val);
   }
   else{
       root->right=insert(root->right,val);


   }
   return root;
}
struct node *search(struct node *root,int val){
   if(root==NULL ||root->data==val){
       return root;
   }
   if(val<root->data){
       return search(root->left,val);
   }
   else{
        return search(root->right,val);
   }
 
struct node * traversalinorder(struct node * root){
   if (root!=NULL)
   {
           traversalinorder(root->left);
   }
   printf("%d",root->data);
}
int main (){
   struct node *root=createnode(10);
   insert(root,20);
   insert(root,20);
   traversalinorder(root);




   return 0;
}
