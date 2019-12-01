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
	int i;
   for( i=0;i<n;i++) scanf("%d",&arr[i]);
}
void display(int arr[],int n);
void display(int arr[],int n)
{ int i;
    for( i=0;i<n;i++)
    printf("%d\t",arr[i]);
}
void shift(int arr[],int m,int n);
void shift(int a[],int m,int n)
{
    int i,j,cutt[length];
    for(i=0;i<m;i++) cutt[i]=a[i];
    
    for(i=0;i<n;i++)
    {
        if (i>=(n-m)) 
        {
            for(j=0;j<m;j++,i++) a[i]=cutt[j];
        }
        else a[i]=a[m+i];
    }
    
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
