/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<conio.h>
#define row 50
#define r 50
#define col 50

void display(int arr[r][r],int n);
void display(int arr[r][r],int n)
{
   for(int i=0;i<n;i++) 
   {
   for(int j=0;j<n;j++) 
   {
    printf("%d\t",arr[i][j]);
   }
    printf("\n");
   }
}

void multiply(int a[][r],int b[r][r],int n);
void multiply(int a[][r],int b[r][r],int n)
{
    int i,j,k,l,c[row][col];
   
   for(i=0;i<n;i++) 
   {
   for(j=0;j<n;j++) 
   
   {c[i][j]=0;
   for( l=0;l<n;l++) 
   {
      c[i][j]=c[i][j]+a[i][l]*b[l][j];
   }
   } 
   }

   
    display(c,n);
}

int gcd(int a,int n);
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,b%a);
}
int main()
{
    int a1[row][col],a2[row][col],i,j,n,m;
    printf("entr size of array\t");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) 
   for(int j=0;j<n;j++) 
   {
    printf("entr array1 wlwment \n");
   scanf("%d",&a1[i][j]);
   } 
   
   for(int i=0;i<n;i++) 
   for(int j=0;j<n;j++) 
   {
    printf("entr array2 wlwment \n");
    scanf("%d",&a2[i][j]);
   }
   
    display(a1,n);
    display(a2,n);
    multiply(a1,a2,n);
    return 0;
}
