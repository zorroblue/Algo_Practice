#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{
    int u,v;
    struct node *parent;
    int rank;
}edge;

edge *makeset(int u,int v)
{
    edge *node=(edge *)malloc(sizeof(node));
    node->u=u;
    node->v=v;
    node->rank=0;
    node->parent=node;
    return node;
}

edge *findset(node *p)
{
    if(p->parent==p)
        return p;
    return findset(p->parent);
}

void merge(node *p,node *q)
{
    if(p->rank>q->rank)
    {
        findset(q)->parent=p;
    }
    else
    {
        findset(q)->parent=p;
    }
    if(p->rank==q->rank)
        p->rank++;
}


int main()
{
    printf("Enter the number of edges : ");
    int m;
    scanf("%d",&m);
    int i,j;
    edge **set=(edge **)malloc(sizeof(edge *)*n);
    for(i=0;i<m;i++)
    {
        int x,y;
        printf("Enter teh edge: ");
        scanf("%d %d",&x,&y);
        set[i]=makeset(x,y);
    }
    printf("Enter the edges to test : ");
    int x,y,l,m;
    scanf("%d %d",&x,&y);
    scanf("%d %d",&l,&m);
    if(findset(


