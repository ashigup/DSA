#include<stdio.h>
#define ds 50
int num[ds],fact[ds],a[ds],b[ds];
int main()
{
	int i,j,k,l,m,n,d,x;
	for( i=0;i<ds;i++)
	{
		fact[i]=0;
		num[i]=0;
		a[i]=0;
		b[i]=0;
	}
	fact[ds-1]=1;
	printf("enter numer\n");
	scanf("%i",&x);
	
	
	
	for(i=1;i<=x;i++)        // geting nos. 1 by one
	{
	d=i%10;    //a1 start
	l=0;
		for(j=ds-1;j>=1;j--)
		{
			n=d*fact[j];
			a[j]=n%10+l;
			l=n/10;
		}
	d/=10;	
		
	printf("\n");
/*	d=i%10;   //b1 start
	l=0;
		for(j=ds-1;j>=1;j--)  
		{
			n=d*fact[j];
			b[j-1]=n%10+l;
			l=n/10;
		}
	
	
*/	
	for(j=ds-1;j>=1;j--) //adding two array
		{
			fact[j]=a[j]+b[j];
		}
	
	
	}	
	
	
	
	for( i=0;i<ds;i++)  //print
	{
	printf("%d",fact[i]);
	}
	printf("\nend of file\n");
}
