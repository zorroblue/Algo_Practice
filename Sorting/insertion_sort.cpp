#include<iostream>
#include<limits.h>
#include<stdlib.h>

using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    int *a=(int *)malloc((n+1)*sizeof(int));
    int i,j;
    a[0]=INT_MIN;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
       int temp=a[i];
        int pos=0;
        while(temp>=a[pos] &&pos<=n)
            pos++; //found the position for the element
        for(j=i;j>pos;j++)
            a[j]=a[j-1];
        a[pos]=temp;
    }
    //printing the numbers
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}

