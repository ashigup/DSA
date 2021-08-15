#include<stdio.h>
#define size 100
void roter(int [],int);
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
    while(rot!=0)
    {
        roter(arr,n);
        rot--;
    }
    display(arr,n);

    return 0;
}
void roter(int a[],int n)
{
    int temp=*a,i;
    for(i=0;i<n;i++)
    {
        *(a+i)=*(a+i+1);
    }
    *(a+n-1)=temp;
    return;
}

void display(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }
}
