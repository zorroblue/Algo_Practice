#include<stdio.h>
int hash(x)
{
  return x%100;
}
int insert(int *a,int x,int n) // a function to insert into the hash array and returns status of insertion..1 if inserted else 0
{
  if(a[hash(x)]==-1)
    {
      a[hash(x)]=x;
      return 1;
    }
  else
    {
      int i=hash(x)+1;
      while(i<100)
	{
	  if(a[i]==-1)
	    {
	      a[i]=x;
	      return 1;
	    }
	  i++;
	}
      i=0;
      while(i<hash(x))
	{
	  if(a[i]==-1)
	    {
	      a[i]=x;
	      return 1;
	    }
	  i++;
	}
    }
  return 0;
}
int search(int *a,int x)// search function, returns 1 if search is successful else 0
{
  if(a[hash(x)]==-1)// no element has been inserted of the same hash
    {
      printf("Not found!\n");
      return 0;
    }
  else
    {
      if(a[hash(x)]==x)//the element is found
	{
	  printf("Found at %d\n",hash(x));
	  return 1;
	}
      else
	{
	  int i=hash(x)+1;
	  while(i<100)
	    {
	      if(a[i]==x)
		{
		  printf("Found at %d\n",i);
		  return 1;
		}
	      else
		i++;
	    }
	  i=0;
	  while(i<hash(x))
	    {
	      if(a[i]==x)
		{
		  printf("Found at %d\n",i);
		  return 1;
		}
	      else
		i++;
	    }	 
	}
    }
  printf("Not found!\n");
  return 0;
}
void print_hash_array(int *a)
{
  int i;
  for(i=0;i<100;i++)
    printf("%d ",a[i]);
}
int main()
{
  int a[100],x,i,n;
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  for(i=0;i<100;i++)
    a[i]=-1;
  for(i=0;i<n;i++)
    {
      printf("Enter element : ");
      scanf("%d",&x);
      insert(a,x,n);
    }
  printf("\nEnter the element you wanna search for ");
  scanf("%d",&x);
  search(a,x);
  //print_hash_array(a);
  return 0;
}