#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int i,j,k,l ,m,n,t;
	int arr[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	i=0;j<n-1;
	while(i<j)
	{
		if(arr[i]==1)
		{
			while(i<j)
			{
				if(arr[j]==0)
				{
				swap(arr+i,arr+j);
				break;
				}
				j--;
			}
			
		j--;
		}
		
		i++;
	}
	
	
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
	
return 0;	
}
