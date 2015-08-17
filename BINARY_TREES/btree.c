// IMPLEMENTATION OF A NORMAL BINARY TREE

#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node *left,*right;
}node;
node *initialiseNewNode()
{
   node *newnode=(node *)malloc(sizeof(node));
    newnode->left=newnode->right=NULL;
    newnode->data=rand()%100;
    return newnode;
}

void gen_tree(node *root)
{
    node *newnode=initialiseNewNode();
    if(root->left==NULL)
        root->left=newnode; //check if left node of the root is empty
    else if(root->right==NULL)
        root->right=newnode; // duh?!
    else //random insertion 
    {
        int random_choice=rand()%2;
        if(random_choice==0)
            gen_tree(root->left); //insert somewhere on the left subtree
        else if (random_choice==1)
            gen_tree(root->right);//insert somewhere on the right subtree
    }

}
void print_tree_in_preorder(node *root)
{
    if(root==NULL)
        return;
    printf("%d\n",root->data);
    print_tree_in_preorder(root->left);
    print_tree_in_preorder(root->right);
}
void print_tree_in_postorder(node *root)
{
    if(root==NULL)
        return ;
     print_tree_in_postorder(root->left);
     print_tree_in_postorder(root->right);
     printf("%d\n",root->data);
}
void print_tree_inorder(node *root)
{
    if(root==NULL)
        return;
    print_tree_inorder(root->left);
    printf("%d\n",root->data);
    print_tree_inorder(root->right);
}
int main()
{
//generate tree
    int n;
    node *root=(node *)malloc(sizeof(node));
    root->data=rand()%100;
    root->left=root->right=NULL;
    printf("Enter how many elements? ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n-1;i++) // n-1 other elements than root
        gen_tree(root);
    printf("In prefix order\n");
    print_tree_in_preorder(root);
    printf("In postfix order\n");
    print_tree_in_postorder(root);
    printf("In Inorder\n");
   print_tree_inorder(root); 
}
