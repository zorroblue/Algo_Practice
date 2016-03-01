#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct node
{
    int rank;
    int value;
    struct node *parent;
}node;

node *makeset(int v)
{
    node *x=(node *)malloc(sizeof(node));
    x->parent=x;
    x->rank=0;
    x->value=v;
    return x;
}

node *findset(node *p) //find the representative of the set
{
    if(p->parent==p)
        return p;
    p->parent=findset(p->parent);
    return p->parent;
}

void merge(node *x,node *y)
{
    if(x->rank>y->rank)
        y->parent=x;
    else 
        x->parent=y;
    if(x->rank==y->rank)
        y->rank++;
}

int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int i,j;
    node **set=(node **)malloc(n*sizeof(node *));
    for(i=0;i<n;i++)
    {
        printf("Enter the value : ");
        int x;
        scanf("%d",&x);
        set[i]=makeset(x);
    }
    merge(set[1],set[2]);
    merge(set[0],set[1]);
    printf("the parent of %d is %d\n",set[0]->value,findset(set[0])->value);
    return 0;
}


        


