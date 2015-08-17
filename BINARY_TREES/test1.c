#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int count;
    struct node *next;
}node;
int main()
{
    node *root=(node *)malloc(sizeof(node));
    node *newnode=(node *)malloc(sizeof(node));
    root->count=2;
    printf("%d %d\n",root->count,newnode->count);
    return 0;
}

