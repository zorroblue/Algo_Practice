#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef struct node 
{
    int value;
    struct node *next;
}node;
typedef struct Queue
{
    node *front;
    node *rear;
}Queue;
node *gen_node(int x)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->value=x;
    newnode->next=NULL;
}
void enqueue(int x,Queue *queue)
{
    if(queue->front==NULL)
    {
        queue->front=gen_node(x);
        queue->rear=queue->front;
    }
    else 
    {
        queue->rear->next=gen_node(x);
        queue->rear=queue->rear->next;
    }
}
void dequeue(Queue *queue)
{
    if(queue->front==NULL)
        return;
    else if(queue->front==queue->rear)
    {
        queue->front=NULL;
        queue->rear=NULL;
    }
    else
    {
        queue->front=queue->front->next;
    }
}
void printqueue(Queue *queue)
{
    node *p=queue->front;
    if(p==NULL)
        return;
    while(p!=queue->rear&&p!=NULL)
    {
        printf("%d ",p->value);
        p=p->next;
    }
    printf("%d\n",p->value);
}
int main()

{
    Queue *queue=(Queue *)malloc(sizeof(Queue));
    int x,n,i;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>n;
        enqueue(n,queue);
    }
    printqueue(queue);
    i=0;
    while(i<x)
    {
        dequeue(queue);
        i++;
        printqueue(queue);
    }
    return 0;

}




