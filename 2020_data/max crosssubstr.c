#include<stdio.h>
#include<limits.h>
struct dda
{
	int num;
	int start;
	int end;
};
struct dda maxcrosssub(int arr[],int start,int mid,int end)
{
	struct dda d1;
	int i,j,k,n,s,e,maxl,maxr,sum;
	i=mid;sum=0;maxl=INT_MIN;s=i;
	while(i>=0)
	{
		sum+=arr[i];
		if(maxl<sum)
		{
			maxl=sum;
			d1.start=i;
		}
		i--;
	}
	i=mid+1;sum=0;maxr=INT_MIN;e=i;
	while(i<=end)
	{
		sum+=arr[i];
		if(maxr<sum)
		{
			maxr=sum;
			d1.end=i;
		}
		i++;
	}
	d1.num=maxl+maxr;
	return d1;
	
}
struct dda maxsub(int arr[],int start,int end)
{
	struct dda m;
	m.num=arr[start];
	m.start=m.end=start;
	if(start==end) return m;
	int mid=(start+end)/2;
	struct dda l=maxsub(arr,start,mid);
	struct dda r=maxsub(arr,mid+1,end);
	struct dda c=maxcrosssub(arr,start,mid,end);
	
	l=l.num>c.num?l:c;
	return l.num>r.num?l:r;
	
	
}
int main()
{
	int arr[]={-5,-6,-8,2,-1,6,-4,-2,-1,-9,-7,-5,-3,-6,-4};
	int n=sizeof(arr)/sizeof(int),i;
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
	struct dda d1=maxsub(arr,0,n-1);
	printf("%d\n%d\n%d\n",d1.start,d1.end,d1.num);
	
	return 0;
	
}
