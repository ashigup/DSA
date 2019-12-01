/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    int i, j,k , temp;
    for( i=0;i<gcd(m,n);i++) 
    {
      temp=a[i];
      j=i;
      while(1)
      {
          k=j+m;
          if(k>=n) k=k-n;
          if(k==i) break;
          a[j]=a[k];
          j=k;
      }
      a[j]=temp;
    }
}

void gcd(int a,int n);
void gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,b%a);
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
