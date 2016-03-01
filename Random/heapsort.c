#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void heapify(int a[],int *size,int i)
{
    int temp;
    int n=*size;
    if(i>n)
        return;
    if(a[2*i]>a[2*i+1])
    {
        temp=a[2*i];
        a[2*i]=a[i];
        a[i]=temp;
        heapify(a,&n,2*i);
    }
    else
    {
        temp=a[2*i+1];
        a[2*i+1]=a[i];
        a[i]=temp;
        heapify(a,&n,2*i+1);
    }
    *size=n;
}

int del_max(int a[],int *size)
{
    int n=*size;
    int max=a[1];
    a[1]=a[n-1];
    n--;
    *size=n;
    heapify(a,size,1);
    return max;
}

int main()
{
    int a[100];
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int i,j;
    for(i=0;i<100;i++)
    a[i]=0;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heapify(a,&n,1);
    int b=n;
    for(i=1;i<n;i++)
        printf("%d\n",del_max(a,&b));
    return 0;
}

