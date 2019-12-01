#include<stdio.h>
#define size 100
void ReverseAlgo(int [],int,int);
void rever(int [],int a,int b);
void display(int [],int);
int main()
{
    int arr[size],n,i,rot =0;
    printf("Enter size of array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    printf("Enter no of times to rotate\n");
    scanf("%d",&rot);

    ReverseAlgo(arr,rot,n);

    display(arr,n);
    return 0;
}
void ReverseAlgo(int a[],int d,int n)
{
    rever(a,0,d-1);
    rever(a,d,n-1);
    rever(a,0,n-1);
}
void rever(int a[],int start,int end)
{
   int temp;
   while(start<end)
   {
       temp=a[start];
       a[start]=a[end];
       a[end]=temp;
       start++;
       end--;
   }
}*/
void display(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }
}
