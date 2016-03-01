#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void merge(int *a,int n,int start,int end)
{
    if(start>=end)
        return;
    int mid=(start+end)/2;
    int temp,i,j;
    int l1=(mid-start+1);
    int l2=(end-mid+1);
    int *c=(int *)malloc((n)*sizeof(int));
    //merge the two halves
    i=start;j=mid+1;
    int k=start;
    while(i<=mid&&j<=end)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else if(a[i]>a[j])
            c[k++]=a[j++];
        else
        {
            c[k++]=a[i++];
            c[k++]=a[j++];
        }
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=end)
        c[k++]=a[j++];
    //copy c to a
    for(i=start;i<=end;i++)
        a[i]=c[i];
}

void mergesort(int *a,int n,int start,int end)
{
    if(start>=end)
        return;
    int mid=(start+end)/2;
    mergesort(a,n,start,mid);
    mergesort(a,n,mid+1,end);
    merge(a,n,start,end);
}
    
int main()
{
    int n,i;
    printf("Enter n : ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    int *a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,n,0,n-1);
    printf("After sorting...n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}

