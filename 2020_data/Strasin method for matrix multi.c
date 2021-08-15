#include<stdio.h>
#include<limits.h>
struct mat2
{
	int C[2][2];
};
struct mat2 maxstrassin(int A[][2],int B[][2],int n)
{
	struct mat2 x;
	if(n<=2)
	{	
	 x.C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];		
	 x.C[0][1]=A[0][0]*B[1][0]+A[0][1]*B[1][1];
	 x.C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];		
	 x.C[1][1]=A[1][0]*B[1][0]+A[1][1]*B[1][1];
	}
	return x;
}
int main()
{
	int A[][2]={-5,-6,-8,2},B[][2]={-1,6,-4,-2};
	int n=sizeof(A)/sizeof(int),i;
//	for(i=0;i<n;i++)
	//printf("%d\t",arr[i]);
	struct mat2 num=maxstrassin(A,B,2);
	//printf("%d\n",num);
	
	return 0;
	
}
