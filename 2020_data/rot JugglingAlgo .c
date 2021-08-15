#include<stdio.h>
#define size 100
void JugglingAlgo(int [],int,int);
int gcd(int a,int b);
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

       // JugglingAlgo(arr,n,rot);

    display(arr,n);
    return 0;
}/*
void JugglingAlgo(int a[],int d,int n)
{
    int temp=0,i,j,k;
    for(i =0;i<gcd(d,n);i++)
    {
        temp=a[i];
        j=i;
        while(1)
        {
            k=j+d;
           if(k>=n) k=k-n;
           if(k==i) break;
           a[j]=a[k];
           j=k;
        }
        a[j]=temp;
    }
}
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}*/
void display(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }
}
