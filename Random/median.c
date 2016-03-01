#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
  int *c=a;
  a=b;
  b=c;
}
int *heapify(int *a,int n)
{
  int i=n;
  while(i>1)
    {
      if(a[i]<a[i/2])
	{
	  int temp=a[i];
	  a[i]=a[i/2];
	  a[i/2] =temp;
	}
      i=i/2;
    }
  return a;
}
int delete_min(int *a,int *n) //assume a is a min heap
{
  int x=a[1];
  int temp=a[1];
  a[1]=a[*n];
  a[*n]=temp;
  *n--; //size reduces
  int i=1;
  while(2*i<=n)
    {
      if(a[i]>a[i*2])
	{
	  swap(&a[i],&a[i*2]);
	  i=2*i;
	}
      else if(2*i+1<=n && a[i]>a[2*i+1])
	{
	  swap(&a[i],&a[2*i+1]);
	  i=2*i+1;
	}
      else 
	break;
    }
  return x;
}
int delete_max(int *a,int *n) //assume a is a min heap
{
  int x=a[1];
  int temp=a[1];
  a[1]=a[*n];
  a[*n]=temp;
  *n--; //size reduces
  int i=1;
  while(2*i<=n)
    {
      if(a[i]<a[i*2])
	{
	  swap(&a[i],&a[i*2]);
	  i=2*i;
	}
      else if(2*i+1<=n && a[i]<a[2*i+1])
	{
	  swap(&a[i],&a[2*i+1]);
	  i=2*i+1;
	}
      else 
	break;
    }
  return x;
}
int insert(int *a,int *n,int x)
{
  if(*n>=99)
    {
      printf("No insertion");
      return -1;
    }
  else
    {
      a[*n+1]=x;
      *n++;
      a=heapify(a,n);
      return 1;
    }
}

void print_array(int *a,int n)
{
  for(i=1;i<=n;i++)
    printf("%d\n",a[i]);
}

int balance_heap(int *a,int a_size,int *b,int b_size)
{
  if(a_size-b_size>=2) //element from a needs to be popped out
    {
      int x=delete_max(a,max_heap_size);
      insert(b,min_heap_size,x);
    }






int main()
{
  int n,i,x,eff_median,*max_heap,*min_heap,max_heap_size=0,min_heap_size=0;
  max_heap=(int *)malloc(sizeof(int)*n);
  min_heap=(int *)malloc(sizeof(int)*n);

  //eff_median is th effective median at each step
  //max_heap is the heap containing elements less than or equal to eff_median
  //min_heap is the heap containing elements greater than eff_median
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      printf("Enter the data  : ");
      scanf("%d",&x);
      if(i==1) //the first time
	{
	  eff_median=x;
	  insert(max_heap,&max_heap_size,x); //insert into heap
	  max_heap_size++;
	  printf("\nThe median is %d\n",eff_median);
	  continue;
	}
      else
	{
	  //atleast one heaps is non empty
	  if(x<=eff_median)
	    insert(max_heap,&max_heap_size,x);
	  else
	    insert(min_heap,min_heap_size,x);
	  balance_heap(max_heap,&max_heap_size,min_heap,min_heap_size);
	}
      if(i%2==0) //the number of elements are even
	{
	  eff_median=(max_heap[0]+min_heap[0])/2;
	  printf("\nThe median is %d\n",(max_heap[0]+min_heap[0])/2);
	}
      else //odd number of elements 
	{
	  //median is the eff_median
	  printf("\nThe median is %d\n",eff_median);
	}

    }
  print_array(max_heap,max_heap_size);
  return 0;
}
