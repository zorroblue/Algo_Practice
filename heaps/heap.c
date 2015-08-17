#include<stdio.h>
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
void print_heap(int *a,int n)
{
  int i=1;
  for(i=1;i<=n;i++)
    printf("%d ",a[i]);
}
int find_max(int *a)
{
  return a[1];
}
void delete_max(int *a,int *k)
{
  swap(&a[1],&a[*k]);//swap the first and last elements
  (*k)--; // the length of the heap reduces by 1
  int n=*k;
  int i=1;
  while(i<=n)
    {
      if(2*i+1<=n) // then 2*i is also less
	{
	  if(a[2*i+1]>a[2*i] && a[i]<a[2*i+1]) // now 2*i+1 is the largest child and is greater than its parent
	    {
	      swap(a+i,a+2*i+1);
	      i=2*i+1;
	    }
	  else if(a[i]<a[2*i]) // 
	    {
	      swap(a+i,a+2*i); // swap with a[2*i] as it is greater than parent
	      i=2*i;
	    }
	}
      else if(2*i<=n && a[i]<a[2*i]) // if there is only one child and it is greater than its parent
	{
	  swap(a+i,a+2*i);
	  i=2*i;
	}
      else
	break;
      // there is no children if the above two cases dont match
    }
}




  

int main()
{
  int n,i,a[100];
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  int x;
  //INSERTION ONE BY ONE
  for(i=1;i<=n;i++)
    {
      printf("Entre the element : ");
      scanf("%d",&a[i]);
      int k=i;
      while(k!=1)
	{
	  if(a[k]>a[k/2])
	    { swap(a+k,a+k/2);
	      k=k/2;
	    }
	  else
	    break;
	}
    }
  print_heap(a,n);
  printf("Max is %d\n",find_max(a));
  delete_max(a,&n);
  printf("\nNew Heap is ");
  print_heap(a,n);
  printf("No of elements is %d and max is %d\n",n,a[1]);
  return 0;
}
