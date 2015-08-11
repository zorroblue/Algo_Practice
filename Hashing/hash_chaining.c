//RAMESHWAR BHASKARAN
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}node;
int hash(int n)
{
  return n%101;
}
node *gen_node(int x)
{
  node *newnode=(node *)malloc(sizeof(node));
  newnode->data=x;
  newnode->next=NULL;
  return newnode;
}
int main()
{
  int a[101];
  int i;
  for(i=0;i<101;i++)
    a[i]=0;
  node *head[101];
  int m=100;
  int n;
  printf("Enter n : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      int x;
      printf("Enter value : ");
      scanf("%d",&x);
      int hash_value=hash(x);
      if(a[hash_value]==0) //no element has the hash
	{
	  a[hash_value]=1;
	  head[hash_value]=(node *)malloc(sizeof(node));
	  node *newnode=gen_node(x);
	  head[hash_value]=newnode;
	}
      else
	{
	  node *newnode=(node *)malloc(sizeof(node));
	  newnode->next=head[hash_value];
	  head[hash_value]=newnode;
	}
    }
  return 0;
}
