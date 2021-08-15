#include<stdio.h>
void main()  //ascending
{
	int arr[]={5,6,2,8,56,45,24,62,95,11};
	int i, j,k,temp;
	
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	printf("%d\t",arr[i]);
	
	printf("\n");
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0&&temp<arr[j])
		{ 
			arr[j+1]=arr[j];
			j--;
		
		}
		arr[j+1]=temp;
	}
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	printf("%d\t",arr[i]);
}
