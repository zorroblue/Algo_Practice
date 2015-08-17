#include<stdio.h>
#include<stdlib.h>
typdef struct node
{
    int key;
    struct node *left,*right;
}node;
node *insert_tree(node *root,node *newnode)
{
    if(root==NULL)
        return newnode
    else
    {
        if(root->key>newnode->key)
            root->left=insert(

int main()
{
    node *root=(node *)malloc(sizeof(node));


