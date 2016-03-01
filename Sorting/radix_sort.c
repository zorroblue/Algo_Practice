#include<stdio.h>
#include<math.h>
#include<stdlib.h>
const int max_length=100;
void *init(int *a,int n) //initialise an array a of size n with 0
{
  int i;
  for(i=0;i<n;i++)
    a[i]=0;
}
int getmax(int *a,int n)
{
  int i;
  int max=-1;
  for(i=0;i<n;i++)
    {
      if(max<a[i])
	max=a[i];
    }
  return max;
}
void count_sort(int *a,int pos,int n,int exp) // a is the input array while b is the output array
{
  int count[10],i;
  init(count,10);
  int *b=(int *)malloc(n*sizeof(int));
  init(b,n);
  for(i=0;i<n;i++)
    {
      count[((a[i]/exp))%10]++;
    }
  for(i=1;i<10;i++)
    {
      count[i]=count[i]+count[i-1];
    }
  for(i=n-1;i>=0;i--)
    {
      b[count[((a[i]/exp))%10]-1]=a[i];
      count[((a[i]/exp))%10]--;
    }
  for(i=0;i<n;i++)
    a[i]=b[i];
}	  





int main()
{
  int n;
  int *a=(int *)malloc(max_length*sizeof(int)); //max_length numbers
  int i;
  printf("Enter the number of numbers ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("Enter the number ");
      scanf("%d",&a[i]);
    }
  //as our size is max_length we can iterate for a max of log(n) to the base 10
  i=0;
  int exp=1;
  int max=getmax(a,n);
  while(i<ceil(log(max)/log(10)))
    {
      count_sort(a,i,n,exp);
      i++;
      exp*=10;
    }
  printf("\nThe output array is \n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}


