#include<stdio.h>
int main()
{
  int i,b[100],n,a[100],c[100];
  for(i=0;i<100;i++) //initialise
    {
      a[i]=0;
      b[i]=0;
      c[i]=0;
    }
  printf("Enter the number of elements ");
  scanf("%d",&n);
  int max=-1;
  for(i=0;i<n;i++)
    {
      printf("Enter the number ");
      scanf("%d",&a[i]);
      c[a[i]]++;
      if(a[i]>max)
	max=a[i];
    }
  for(i=1;i<=max;i++)
    c[i]=c[i]+c[i-1]; //now c[i] holds the number of values <=i
  //for(i=0;i<n;i++)
  //printf("%d ",c[i]);
  for(i=0;i<n;i++)
    {
      b[c[a[i]]-1]=a[i]; //due to 0 based indexing
      c[a[i]]--;
    }
  printf("The output array is \n");
  for(i=0;i<n;i++)
    printf("%d ",b[i]);
  return 0;
}
