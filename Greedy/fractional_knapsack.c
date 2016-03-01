#include<stdio.h>
void merge(float *array,int *w,int *v,int start,int end)
{
  int i,j,k;
  float a[100],b[100];
  int mid=(start+end)/2;
  for(i=start;i<=mid;i++)
    a[i]=array[i];
  for(i=mid+1;i<=end;i++)
    b[i]=array[i];
  float c[100];
  int v1[100],w1[100];
 
  i=start,j=mid+1,k=0;
  while(i<=mid &&j<=end)
    {
      if(a[i]<b[j])
	{
	  v1[k]=v[i];
	  w1[k]=w[i];
	  c[k++]=a[i++];
	}
      else if(a[i]==b[j])
	{
	  v1[k]=v[i];
	  w1[k]=w[i];
	  c[k++]=a[i++];
	  v1[k]=v[j];
	  w1[k]=w[j];
	  c[k++]=b[j++];
	}
      else
	{
	  v1[k]=v[j];
	  w1[k]=w[j];
	  c[k++]=b[j++];
	}
    }
  while(i<=mid)
    {
      v1[k]=v[i];
      w1[k]=w[i];
      c[k++]=a[i++];
    }
  while(j<=end)
    {
      v1[k]=v[j];
      w1[k]=w[j];
      c[k++]=b[j++];
    }
  for(i=start;i<=end;i++)
    {
      array[i]=c[i-start];
      w[i]=w1[i-start];
      v[i]=v1[i-start];
    }
}





void mergesort(float *a,int *b,int *c,int start,int end)
{
  if(start<end)
    {
      mergesort(a,b,c,start,(start+end)/2);
      mergesort(a,b,c,(start+end)/2+1,end);
      merge(a,b,c,start,end);
    }
}


int main()
{
int n;
int k;
printf("Enter the number of elements and weight of the bag ");
scanf("%d %d",&n,&k);
int i,j;
int x,y;
 int value[100],weight[100];
 float ratio[100];
 printf("Enter :");
for(i=0;i<n;i++)
{
  scanf("%d %d",&value[i],&weight[i]);
  ratio[i]=(float)value[i]/weight[i];
 }
 printf("Before sorting,the ratios are :\n");
 for(i=0;i<n;i++)
   printf("%f weight=%d value=%d\n",ratio[i],weight[i],value[i]);

 mergesort(ratio,weight,value,0,n-1);
 printf("After sorting,the ratios are :\n");
 for(i=0;i<n;i++)
   printf("%f weight=%d value=%d\n",ratio[i],weight[i],value[i]);
 float ans=0,max_weight=k;
 i=n-1;
 while(i>=0&&max_weight>=0)
   {
     if(max_weight>=weight[i])//capacity greater than weight
       {
	 max_weight-=weight[i];
	 ans+=value[i];
	 i--;
       }
     else if(max_weight<weight[i])
       {
	 ans+=((float)max_weight/weight[i])*value[i];
	 max_weight=0;
	 i--;
	 break;
       }
     
   }
 printf("The max value possible is %f\n",ans);
 return 0;
}

