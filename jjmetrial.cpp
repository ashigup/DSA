#include<iostream>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr=(int*)malloc(10000000*sizeof(int));
	int n=0,t=0,num=0,sum=0,i,j,k,l,m,start=-1,end=-1;
	scanf("%d",&t);
	
	while(t)
	{
	scanf("%d",&n);
	for( i=0;i<n;i++)
	scanf("%d",arr+i);
	scanf("%d",&num);
	
	for( i=0;i<n;i++)
	{
		sum=0;
		for( j=0+i;j<n;j++)
		{
			sum+=arr[j];
			if(sum>num) break;
			if(sum==num)
			{
				start=i;
				end=j;
				break;
			 } 
		}
		if(sum==num) break;
		
	}
	if(start!=-1)
	printf("%d %d\n",start,end);
	else 
	std::cout<<"-1\n";
	t--;
	}
	
	return 0;
}
