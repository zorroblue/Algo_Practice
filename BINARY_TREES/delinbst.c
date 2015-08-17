#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}node;
node *gen_node(int x)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}
//recursive implementation of the standard BST procedure
node *insert_node(node *root,int x)
{
    if(root==NULL)
    {
        root=gen_node(x);
        return root;
    }
    if(root->data>x)
    {
        root->left=insert_node(root->left,x);
    }
    else if(root->data<x)
        root->right=insert_node(root->right,x);
    return node;
}
int check_if_right_child(node *parent,node *child)
{
    if(parent->right==child)
        return 1;
    else 
        return 0;
}

node *delete_node(node *root,int x)
{
    //first find the node containing x ..Let it be p (initialised as root)
    node *p=root,*parent_of_p;
    while(p!=NULL)
    {
        parent_of_p=p;
        if(p->data==x)
            break;
        else if(p->data>x)
            p=p->left;
        else
            p=p->right;
    }
    if(p==NULL) // no such p exists
        return root;
    else
    {
        int flag=(check_if_right_child(parent_of_p,p));
        if(p->left==NULL && p->right==NULL) //no children
        {  if(flag==1)
               parent_of_p->right=NULL;
            else 
                parent_of_p->left=NULL;
        }
        else if(p->left==NULL ^ p->left

                    
        

