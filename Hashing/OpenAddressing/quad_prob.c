#include<stdio.h>
const int m=100; //the size of the array
int hash(int x) //the hash function
{
  return x%m;
}
int f(int i) //the function of i which is quadratic here and here f(0)=0
{
  return 2*i+i*i; //c1=2,c2=1
}
int insert(int *a,int x) //the insert function returns 1 if insert is successful else 0
{
  if(a[hash(x)]==-1)
    {
      a[hash(x)]=x;
      return 1;
    }
  else
       {
	 int i=1; //check for empty slot and break or else stop after m probes
	 //since first probe is unsuccessful we have m-1 more probes to go with
	 while(i<m)
	   {
	     
	     if(a[(hash(x)+f(i))%m]==-1)
	       {
		 a[(hash(x)+f(i))%m]=x;
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
  //maximum of m probes is allowed
  while(i<m)
    {
      if(a[(hash(x)+f(i))%m]==-1)//no more searching required
	{
	  printf("Not found1! %d\n",(hash(x)+f(i))%m);
	  return 0;
	}
      else if(a[(hash(x)+f(i))%m]==x)//found
	{
	  printf("Found at position %d\n",(hash(x)+f(i))%m);
	  return 1;
	}
      i++;
    }
  printf("Not found2!\n"); // in case the probed elements are full and dont match with the given element
  return 0;
}

    


int main()
{
  int a[m],x;
  int i;
  for(i=0;i<m;i++)
    a[i]=-1; // initialise the array to be empty
  int n;
  printf("how many elements to enter? : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("Enter element : ");
      scanf("%d",&x);
     int status=insert(a,x);
     if(status==0)
       printf("Insert unsuccessful!\n");
     else
       search(a,x);
    }
  //printf("Which element do you want to search for ? ");
  //scanf("%d",&x);
  //search(a,x);
  return 0;
}
