#include<stdio.h>
void merge(int arr[],int start,int mid,int end)
{
	int i,j,k,l,L[1000],R[1000];
	int n1=mid-start+1;
	int n2=end-mid;
	for(i=0;i<n1;i++)
	L[i]=arr[start+i];
	for(i=0;i<n2;i++)
	R[i]=arr[mid+1+i];
	i=0;j=0;k=start;
	while(i<n1&&j<n2)
	{
		if(L[i]<R[j])
		{
			arr[k++]=L[i++];
		}
		else{
			arr[k++]=R[j++];
		}
	}
	while(i<n1)
	{
		arr[k++]=L[i++];
	}
	while(j<n2)
	{
		arr[k++]=R[j++];
	}
}
void mergesort(int arr[],int start,int end)
{
	if(start==end) return;
	int mid=(start+end)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,mid,end);
}
int main()
{
	int arr[]={5,6,8,2,1,6,4,2,1,9,7,5,3,6,4};
	int n=sizeof(arr)/sizeof(int),i;
	mergesort(arr,0,n-1);
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
	
	return 0;
	
}
