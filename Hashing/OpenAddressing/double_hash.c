#include<stdio.h>
const int m=100;
int hash1(int x) //the primary hash function
{
  return x%100;
}
int hash2(int x)
{
  return x%99;
}
int insert(int *a,int x)
{
  if(a[hash1(x)]==-1)
    {
      a[hash1(x)]=x;
      return 1;
    }
  else
    {
      int i=1;
      //max m probes we finished 1 so m-1 probes left
      while(i<m)
	{
	  if(a[(hash1(x)+i*hash2(x))%m]==-1)
	    {
	      a[(hash1(x)+i*hash2(x))%m]=x;
	      return 1;
	    }
	  i++;
	}
    }
  return 0;
}
int search(int *a,int x)
{
  int i=0;
  //max m probes
  while(i<m)
    {
      if(a[(hash1(x)+i*hash2(x))%m]==-1) //no more probes required
	{
	  printf("not found!\n");
	  return 0;
	}
      else if(a[(hash1(x)+i*hash2(x))%m]==x)
	{
	  printf("Found at %d\n",(hash1(x)+i*hash2(x))%m);
	  return 1;
	}
      i++;
    }
  printf("Not found!\n");
  return 0;
}
int main()
{
  int a[m],x,i,n;
  for(i=0;i<m;i++)
    a[i]=-1;
  printf("how many elements to be entered? : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("Enter the element : ");
      scanf("%d",&x);
      int status=insert(a,x);
      if(status==0)
	printf("Not inserted!\n");
      else
	search(a,x);
    }
  // printf("Which element do you want to search for ? ");
  //scanf("%d",&x);
  //search(a,x);
  return 0;
}

