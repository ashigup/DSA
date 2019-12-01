#include <stdio.h> 
#define size 1000
int main()
{
	int arr[]={22,3565,265,1,2,5,55,66,214,841,665},i,k,n,temp;
	//scanf("%d",&n);
	n=sizeof(arr)/sizeof(arr[0]);
	scanf("%d",&k);
	//for(i=0;i<n;i++)
	//scanf("%d",arr+i);
	k=k%n;
	temp=arr[k];
	for(i=k;i>=0;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[0]=temp;
	for(i=0;i<n;i++)
	printf("%d\t",*(arr+i));
	
	
	
	return 0;
}
