#include<stdio.h>
int main()
{
	int arr[3][3]={1,2,3,4,5,6,7,8,9};
	int i,r=3,c=3,k=0,a=0,l=0;
	while(k<r&&l<c)
	{
		a=l;
		while(a<c)
		{
			printf("%d",arr[k][a]);
			a++;
		}
		k++;
		a=k;
		while(a<r)
		{
			printf("%d",arr[a][c-1]);
			a++;	
		}
		c--;
		a=c;
		while(a>=c)
		{
			printf("%d",arr[r-1][a]);
			a--;	
		}
		r--;
		a=r;
		while(a>=r)
		{
			printf("%d",arr[a][l]);
			a--;	
		}
		l++;
		a=l;
		
		
		
		
		
	}
	
	return 0;
}
