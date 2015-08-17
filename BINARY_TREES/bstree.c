#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node *left,*right;
}node;
node *Initialise_NewNode()
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=rand()%100;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void Search(node *root,int k)
{
    if(root==NULL)
        printf("Not found");
    if(root->data==k)
        printf("Found");
    else if(root->data>k)
        Search(root->left,k);
    else if(root->data<k)
        Search(root->right,k);
}
node *insert(node* root,node *newnode)
{

   if(root==NULL)
       return newnode;
   if(root->data<newnode->data)
   {
       root->left=insert(root->left,newnode);
   }
   else if(root->data>newnode->data)
       root->right=insert(root->right,newnode);
   return root;
}

void print_tree_inorder(node *root)
{
    if(root==NULL)
    {        printf("the root is null");
        return;}
    print_tree_inorder(root->left);
    printf("%d\n",root->data);
    print_tree_inorder(root->right);
}
int main()
{
    int i;
    printf("How many elements? :");
    int n;
    node *root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         node *newnode=(node *)malloc(sizeof(node));
              newnode->data=rand()%100;
               newnode->left=NULL;
                newnode->right=NULL;
    
        insert(root,newnode);
    }
    print_tree_inorder(root);
    return 0;
}
