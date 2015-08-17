#include<stdio.h>
#include<stdlib.h>
//a function to check for mismatch
void swap(int *a,int *b)
{
  printf("Swap happened between %d and %d\n\n",*a,*b);
  int *c=a;
  a=b;
  b=c;
}

void check_for_mismatch(int *a,int i)
{
  if(i<=1)
    return;
  while(i>1)
    {
      if(a[i]<a[i/2]) //the parent is greater than child
	return;
      else
	{
	  printf("a[%d] was %d ",i,a[i]);
	  //	  swap(&a[i],&a[i/2]); //swap parent and child
	  int temp=a[i];
	  a[i]=a[i/2];
	  a[i/2]=temp;
	  printf("Now a[%d] is %d\n",i,a[i]);
	  i=i/2;
	}
    }
  
}

int main()
{
  int a[101];
  int i,x,n;
  printf("Enter the no of numbers? : ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      printf("Entre the number: ");
      scanf("%d",&a[i]);
      check_for_mismatch(a,i);
    }

  printf("\n");
  printf("%d\n",a[1]);
  for(i=1;i<=n;i++)
    printf("%d ",a[i]);
  return 0;
}


      
