#include<stdio.h>
#define size 100
int find(int x,int arr[size],int n);
int main()
{
int i,c,d,j,count=0,sum=0,x=0,p1,p2,a[size],b[size],n=5;

printf("enter size of array:");
scanf("%d",&n);

printf("Enter number X:");
scanf("%d",&x);
printf("enter the elements:");
for(i=0;i<n;i++)
{
	b[i]=0;
scanf("%d",&a[i]);
}
/*-------------------------------------------*/
  for (c = 0; c < n; c++)
  {
    for (d = 0; d < count; d++)
    {
      if(a[c] == b[d])
        break;
    }
    if (d == count)
    {
      b[count] = a[c];
      count++;
    }
  }
  n=count;
/*------------------------------------------------display-------------------*/


for(i=0;i<n;i++)
{
printf("%d\t",b[i]);
}

/*-----------------------------------------------------*/


for(i=0;i<x/2;i++)
{
p1=find(i,b,n);
if(b[p1]>=0)
p2=find(x-i,b,n);
if(b[p1]+b[p2]==x) printf("%d %d\n",b[p1],b[p2]);
}



return 0;
}


int find(int x,int arr[size],int n)
{
int i;
for(i=0;i<n;i++)
{
if(arr[i]==x)
return i;
}

return -1;
}
