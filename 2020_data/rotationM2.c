
#include <stdio.h>
#define length 50

int func(int arr[]);
void enter(int arr[],int n);
void enter(int arr[],int n)
{
   for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}
void display(int arr[],int n);
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
}

void shift(int a[],int m,int n);
void shift(int a[],int m,int n)
{
    int i,cutt[length];
    for(i=0;i<m;i++) shiftone(a,n);
}

void shiftone(int a[],int n);
void shiftone(int a[],int n)
{
    int i,temp =a[0];
    for(i=0;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    a[i]=temp;
}
int main()
{
    int arr[length],i,j,n,m;
    printf("entr size of array\t");
    scanf("%d",&n);
    printf("entr %d elements\t",n);
   enter(arr,n);
   
    printf("entr a length to shift\t");
    scanf("%d",&m);
    
    shift(arr,m,n);
    display(arr,n);
    return 0;
}
