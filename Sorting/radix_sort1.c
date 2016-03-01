#include<stdio.h>
#include<stdlib.h>
typedef struct person
{
  int cg;
  char name[100];
}person;
void count_sort(person *a,int n)
{
  int count[10],i;
  for(i=0;i<10;i++)
    count[i]=0;
  int max=-1;
  person temp,b[100];
  for(i=0;i<n;i++)
    {
      count[a[i].cg]++;
      if(a[i].cg>max)
	max=a[i].cg;
    }
  for(i=1;i<=max;i++)
    {
      count[i]=count[i]+count[i-1];
    }
  for(i=n-1;i>=0;i--)
    {
      b[count[a[i].cg]-1]=a[i];
      count[a[i].cg]--;
    }
  for(i=0;i<n;i++)
    {
      a[i]=b[i];
    }
}

void count_sort_radix_helper(person *a,int exp,int n)
{
  int count[10],i;
  for(i=0;i<10;i++)
    count[i]=0;
  int max=-1;
  person temp,b[100];
  for(i=0;i<n;i++)
    {
      count[(a[i].cg/exp)%10]++;
      if(a[i].cg>max)
	max=a[i].cg;
    }
  for(i=1;i<=max;i++)
    {
      count[i]=count[i]+count[i-1];
    }
  for(i=n-1;i>=0;i--)
    {
      b[count[(a[i].cg/exp)%10]-1]=a[i];
      count[(a[i].cg/exp)%10]--;
    }
  for(i=0;i<n;i++)
    {
      a[i]=b[i];
    }
}

void radix_sort(person *a,int n)
{
  int i,exp=1;
  int max=-1; //store the maximum of the arrray
  //find the max
  for(i=0;i<n;i++)
    {
      if(max<a[i].cg)
	max=a[i].cg;
    }
  while(max/exp>0)
    {
      count_sort_radix_helper(a,exp,n);
      exp*=10;
    }
}





void print_array(person *a,int n)
{
  int i;
  printf("\nThe sorted array is \n");
  for(i=0;i<n;i++)
    {
      printf("%s %d\n",a[i].name,a[i].cg);
    }
}


int main()
{
  person a[100];
  int i,n;
  printf("Enter the number of people ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("Enter the name ");
      scanf("%s",a[i].name);
      printf("Enter the cgpa ");
      scanf("%d",&a[i].cg);
    }
  // count_sort(a,n);
  radix_sort(a,n);
  print_array(a,n);
  return 0;
}


	    

